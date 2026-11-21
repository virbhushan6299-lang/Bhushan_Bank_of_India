let accounts = JSON.parse(localStorage.getItem("bhushanAccounts")) || [];

let account = null;

let loggedIn = false;


// Save Data

function saveData() {

    localStorage.setItem(
        "bhushanAccounts",
        JSON.stringify(accounts)
    );

}


// Show Sections

function showSection(id) {

    if (
        ["deposit", "withdraw", "transfer", "balance"].includes(id)
        && !loggedIn
    ) {
        alert("Please Login First!");
        return;
    }

    let sections = document.querySelectorAll(".section");

    sections.forEach(section => {
        section.style.display = "none";
    });

    document.getElementById(id).style.display = "block";

    if (id === "balance") {
        checkBalance();
    }

}


// CREATE ACCOUNT

function createAccount() {

    let inputs = document.querySelectorAll("#create input");

    let name = inputs[0].value.trim();
    let father = inputs[1].value.trim();
    let gender = inputs[2].value.trim();
    let dob = inputs[3].value;
    let mobile = inputs[4].value.trim();
    let password = inputs[5].value;

    if (!name || !father || !gender || !dob || !mobile || !password) {

        alert("Please fill all details!");
        return;

    }

    if (!/^\d{10}$/.test(mobile)) {

        alert("Enter valid 10 digit mobile number!");
        return;

    }

    let accountNo = String(
        Math.floor(1000000000000 + Math.random() * 9000000000000)
    );

    account = {

        name,
        father,
        gender,
        dob,
        mobile,
        password,
        accountNo,
        balance: 10000

    };

    // Important: Add account to array

    accounts.push(account);

    saveData();

    alert(
        "Account Created Successfully!\nYour Account Number: "
        + accountNo
    );

    inputs.forEach(input => input.value = "");

    showSection("login");

}


// LOGIN

function login() {

    let inputs = document.querySelectorAll("#login input");

    let ac = inputs[0].value.trim();

    let pass = inputs[1].value;

    let foundAccount = accounts.find(function(a) {

        return a.accountNo === ac && a.password === pass;

    });

    if (foundAccount) {

        account = foundAccount;

        loggedIn = true;

        alert("Welcome " + account.name);

        showSection("balance");

    }

    else {

        alert("Invalid Account Number or Password!");

    }

}


// DEPOSIT MONEY

function depositMoney() {

    let amount = Number(
        document.querySelector("#deposit input").value
    );

    if (!Number.isSafeInteger(amount) || amount <= 0) {
        alert("Enter a valid amount!");
        return;
    }

    let previous = account.balance;

    account.balance += amount;

    saveData();

    document.getElementById("depositResult").innerHTML = `
        <div class="transaction-result">
            <h3>✓ Deposit Successful!</h3>
            <p><b>Deposited Amount:</b> ₹${amount}</p>
            <p><b>Previous Balance:</b> ₹${previous}</p>
            <p class="new-balance">
                New Balance: ₹${account.balance}
            </p>
        </div>
    `;

    document.querySelector("#deposit input").value = "";
}


// WITHDRAW MONEY

function withdrawMoney() {

    let amount = Number(
        document.querySelector("#withdraw input").value
    );

    if (!Number.isSafeInteger(amount) || amount <= 0) {
        alert("Enter a valid amount!");
        return;
    }

    if (amount > account.balance) {
        alert("Insufficient Balance!");
        return;
    }

    let previous = account.balance;

    account.balance -= amount;

    saveData();

    document.getElementById("withdrawResult").innerHTML = `
        <div class="transaction-result">
            <h3>✓ Withdrawal Successful!</h3>
            <p><b>Withdrawn Amount:</b> ₹${amount}</p>
            <p><b>Previous Balance:</b> ₹${previous}</p>
            <p class="new-balance">
                Remaining Balance: ₹${account.balance}
            </p>
        </div>
    `;

    document.querySelector("#withdraw input").value = "";
}
// TRANSFER MONEY (DEMO)

function transferMoney() {

    let inputs = document.querySelectorAll("#transfer input");

    let receiver = inputs[0].value.trim();
    let amount = Number(inputs[1].value);

    if (!/^\d{13}$/.test(receiver) ||
        receiver === account.accountNo) {
        alert("Enter a valid receiver account number!");
        return;
    }

    if (!Number.isSafeInteger(amount) || amount <= 0) {
        alert("Enter a valid amount!");
        return;
    }

    if (amount > account.balance) {
        alert("Insufficient Balance!");
        return;
    }

    let previous = account.balance;

    account.balance -= amount;

    saveData();

    document.getElementById("transferResult").innerHTML = `
        <div class="transaction-result">
            <h3>✓ Transfer Successful!</h3>
            <p><b>Receiver Account:</b> ${receiver}</p>
            <p><b>Transferred Amount:</b> ₹${amount}</p>
            <p><b>Previous Balance:</b> ₹${previous}</p>
            <p class="new-balance">
                Remaining Balance: ₹${account.balance}
            </p>
        </div>
    `;

    inputs.forEach(input => input.value = "");
}

// CHECK BALANCE

function checkBalance() {

    if (!loggedIn) {

        alert("Please Login First!");
        return;

    }

    document.getElementById("balanceDetails").innerHTML = `

        <h3>Account Details</h3>

        <p><b>Account Holder:</b> ${account.name}</p>

        <p><b>Account Number:</b> ${account.accountNo}</p>

        <h2>Available Balance: ₹${account.balance}</h2>

    `;

}


// OPEN LOGIN BY DEFAULT

showSection("login");