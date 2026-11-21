#include <stdio.h>

int main()
{ int choice,DOB,num,pass, Ac, money, AvlBalance, receiverAc;

  char name[50], fname[50], gender[10], userId[20];
printf("======== Welcome To BHUSHAN BANK OF INDIA ========\n"); 
 printf("Select The Below Option\n");
 printf("1. Create Account\n");
 printf("2. Login\n");
 printf("3. Deposite Money\n");
 printf("4. Withdraw Money\n");
 printf("5. Transfer Money\n");
 printf("6. Check Balance\n");


AvlBalance= 10000;
 switch (choice)
 {
  case 1:

    printf("To open Account fill the given details\n");

    printf("Enter your name: ");
    scanf(" %49[^\n]", name);

    printf("Enter your father name: ");
    scanf(" %49[^\n]", fname);

    printf("Enter your Gender: ");
    scanf("%9s", gender);

    printf("Enter your DOB: ");
    scanf("%d", &DOB);

    printf("Enter your Mob No: ");
    scanf("%d",&num);

    printf("\nAccount Created Successfully!\n");

    printf("Name: %s\n", name);
    printf("Father Name: %s\n", fname);
    printf("Gender: %s\n", gender);
    printf("Your Mob No: %d\n",num);
    printf("Your Account No: 9875478956684\n");
    printf("IFSE Code: BBIN0007845\n");

    break;
case 2:
   printf("=========Login Your Account=========\n");
   printf("Enter Your User Id or Account No:\n");
   scanf("%19[^\n]",&userId);
   printf("Enter Your Password:\n");
   scanf("%d",&pass);
   
   printf("======== WELCOME TO BHUSHAN BANK OF INDIA =========\n");

    printf("Name: %s\n", name);
    printf("Father Name: %s\n", fname);
    printf("Your Mob No: ll%d\n",num);
    printf("Your Account No: 9875478956684\n");
    printf("Your Avl Balance: %d",AvlBalance);
    break;

case 3:
	printf("========= Deposite Money =========\n");
	printf("Enter Your Account No: \n");
	scanf("%d",&Ac );
	printf("How much Money you want to Deposite:");
	scanf("%d",&money);
    if (money>0)
       {
        printf("Thanks Your Money Desposite successfully!\n");
        printf("Your Avl Balance: %d",AvlBalance+money);
       }
    else
       printf("Invalid Amount!");
      
	break;

case 4:
    printf("========= Withdraw Money =========\n");
		
    printf("Enter Your Account No: \n");
	scanf("%d",&Ac);
	printf("How much Money you want to Withdraw:\n");
	scanf("%d",&money);
    
   if(money>AvlBalance)
   {
     printf("Insufficient Balance");
    }

    else if(money<=0)
       printf("Invalid Input");

    else
       printf("Thanks! Your Money Withdraw successfully!\n");
       printf("Your Avl Balance: %d",AvlBalance-money);  
    

	break;

case 5:
   printf("========= Transfer Money  =========\n");

   printf("Enter Your Account No: \n");
   scanf("%d",&Ac);

   printf("Enter Receiver Account Number: \n");
   scanf("%d",&receiverAc);

  printf("How much Money you want to Transfer:\n");
   scanf("%d",&money);
   
   if (money>AvlBalance)
   { printf("Insufficient Balance! \n");
     
   }
   else if(money<0) {
      printf("Invalid! ");
   }

   else
   {
      printf("Thanks Your Money Transfer successfully!\n");
      printf("Your Avl Balance: %d\n",AvlBalance-money);  
   }
   break;  
   
case 6:
    printf("========= Check Balance  =========\n");

    printf("Enter Your Account Number: \n");
    scanf("%d",Ac);

    printf("Your Avl Balance =%d \n",AvlBalance);

    printf("Thanks!\n");
    break;

 
   }
      
}