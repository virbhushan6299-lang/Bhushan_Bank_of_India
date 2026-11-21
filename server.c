#include <stdio.h>
#include <winsock2.h>
#include <string.h>

void sendResponse(SOCKET client, const char *message)
{
    char response[2048];

    int len = sprintf(response,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n"
        "Access-Control-Allow-Headers: Content-Type\r\n"
        "Content-Length: %d\r\n"
        "Connection: close\r\n\r\n"
        "%s",
        (int)strlen(message), message);

    send(client, response, len, 0);
}

int main()
{
    WSADATA wsa;
    SOCKET server;
    struct sockaddr_in address;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Winsock initialization failed!");
        return 1;
    }

    server = socket(AF_INET, SOCK_STREAM, 0);

    if (server == INVALID_SOCKET)
    {
        printf("Socket creation failed!");
        WSACleanup();
        return 1;
    }

    memset(&address, 0, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server, (struct sockaddr*)&address,
             sizeof(address)) == SOCKET_ERROR)
    {
        printf("Server binding failed!");
        closesocket(server);
        WSACleanup();
        return 1;
    }

    if (listen(server, 5) == SOCKET_ERROR)
    {
        printf("Listen failed!");
        closesocket(server);
        WSACleanup();
        return 1;
    }

    printf("BHUSHAN BANK SERVER STARTED!\n");
    printf("Server running on port 8080\n");
    printf("Open http://localhost:8080 in browser\n");

    while (1)
    {
        SOCKET client = accept(server, NULL, NULL);

        if (client != INVALID_SOCKET)
        {
            char request[4096];

            int received = recv(
                client, request, sizeof(request) - 1, 0
            );

            if (received > 0)
            {
                request[received] = '\0';

                char method[10] = {0};
                char path[100] = {0};

                sscanf(request, "%9s %99s", method, path);

                printf("\nMethod: %s\n", method);
                printf("Path: %s\n", path);

                sendResponse(
                    client,
                    "BHUSHAN BANK SERVER READY"
                );
            }

            closesocket(client);
        }
    }

    closesocket(server);
    WSACleanup();

    return 0;
}