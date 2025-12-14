#include <Windows.h>
#include <stdio.h>
//#include "?"
// A rusty key found within ruins, find Sleepy and ask for the newest header file

#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char* argv[]) {

WSADATA wsaData;
SOCKET sock;
SOCKADDR_IN dat;

if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
return 1;
}

sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

dat.sin_family = AF_INET;
dat.sin_addr.S_un.S_addr = inet_addr(IP);
dat.sin_port = htons(port);

if (connect(sock, &dat, sizeof(SOCKADDR_IN)) == -1) {
    puts("Failed to connect");
    return 0;
}

char httpbuff[0x4000];
int num = recv(sock, httpbuff, sizeof(httpbuff), 0);

const char* sendData = password;
send(sock, sendData, strlen(sendData), 0);

Sleep(500); // Wait for server to load

num = recv(sock, httpbuff, sizeof(httpbuff)-1, 0);

while (1) {

    httpbuff[num] = '\0';
    printf("%s\n", httpbuff);

    char option[25];
    fgets(option, 25, stdin);
    option[strcspn(option, "\n")] = '\0';

    if (strcmp(option, "exit") == 0) break;

    snprintf(option, sizeof(option), "%s\r\n", option);

    send(sock, &option, sizeof(option), 0);

    num = recv(sock, httpbuff, sizeof(httpbuff)-1, 0);

}

closesocket(sock);
WSACleanup();
return 0;

}
