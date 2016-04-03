#include <winsock2.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

#define NO_FLAGS_SET 0
#define PORT 80
#define MAXBUFLEN 20480

#define SYMBOL_AMOUNT 100

SOCKET createSoc (){
    SOCKET soc;
    soc = socket(AF_INET , SOCK_STREAM , 0);
    if(soc == INVALID_SOCKET)
    {
        exit(EXIT_FAILURE);
        printf("Could not create socket : %d" , WSAGetLastError());
    }
    printf("Socket created.\n");
    return soc;
}

SOCKADDR_IN newSocketAddr(const char * nameHost){
     char * IP;
     struct hostent * remoteHost;
     remoteHost = gethostbyname(nameHost);
     IP = inet_ntoa(*(struct in_addr *)*remoteHost->h_addr_list);
     SOCKADDR_IN recvSockAddr;
     memset(&recvSockAddr, 0, sizeof(recvSockAddr));
     recvSockAddr.sin_port=htons(PORT);
     recvSockAddr.sin_family=AF_INET;
     recvSockAddr.sin_addr.s_addr= inet_addr(IP);
     return recvSockAddr;
}

void connectToServer(SOCKET s, SOCKADDR_IN recvSockAddr){
    if(connect(s,(SOCKADDR*)&recvSockAddr,sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
    {
       puts("Connect error");
       closesocket(s);
       WSACleanup();
       exit(EXIT_FAILURE);
    }
     puts("Connected");
}

void sendInquiry(SOCKET s, const char * nameHost, char * content){
    char request[SYMBOL_AMOUNT];
    sprintf(request, "GET /var/6?%s HTTP/1.1\r\nHost:%s\r\n\r\n", content, nameHost);  // add Host header with host_name value
    send(s, request, strlen(request), 0);
}

void sendResultInquiry(SOCKET s, const char * nameHost, char * content){
    char result[SYMBOL_AMOUNT];
    char request[SYMBOL_AMOUNT];
    sprintf(result, "result=%d", maxSum(content));
    sprintf(request, "POST /var/6 HTTP/1.0\r\n" "Host: %s\r\n"  "Content length: %d\r\n\r\n" "%s\r\n", nameHost, strlen(result), result);
    send(s, request, strlen(request), 0);
}

void recieveAnswer(SOCKET s, char * buffer, int status){
    int numrcv = 0;
    numrcv = recv(s, buffer, MAXBUFLEN, NO_FLAGS_SET);
    if (numrcv == SOCKET_ERROR)
    {
        printf("ERROR: recvfrom unsuccessful\r\n");
        status = closesocket(s);
        if(status == SOCKET_ERROR)
			printf("ERROR: closesocket unsuccessful\r\n");
            status = WSACleanup();
        if (status == SOCKET_ERROR)
			printf("ERROR: WSACleanup unsuccessful\r\n");
        exit(EXIT_FAILURE);
    }

int maxSum(char * mat){
    int amount = 0;
    int maxVal = 0;
    int maxIndex;
    for(int i = 0; i <= strlen(mat); i++){
        if( *(mat + i) == '\0' || *(mat + i) == '\n')
            amount++;
    }

    int sumCol[amount];

    for(int i = 0; i < amount; i++){
        sumCol[i] = 0;
    }
    for(int i = 0; i < amount; i++){
        for(int k = 0; k < amount; k++){
            sumCol[k] += strtol(mat, &mat, 10);
        }
    }
    for(int i = 0; i < amount; i++){
        if(sumCol[i] > maxVal){
            maxVal = sumCol[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

    int main(){
        WSADATA Data;
        SOCKADDR_IN recvSockAddr;
        SOCKET s;
        SOCKET newSocket();
        int status;
        const char * nameHost = "pb-homework.appspot.com";
        char buffer[MAXBUFLEN];
        memset(buffer,0,MAXBUFLEN);
        status = WSAStartup(MAKEWORD(2, 2), &Data);

        if(status != 0)
        {
            printf("ERROR: WSAStartup unsuccessful\r\n");
            return 0;
        }

        recvSockAddr = newSocketAddr(nameHost);
        s = newSocket();
        connectToServer(s, recvSockAddr);

        sendInquiry(s, nameHost, "");
        recieveAnswer(s, buffer, status);

        char * secret = strstr(buffer, "secret");
        int lenJump = strlen(buffer) - strlen(secret);

        sendInquiry(s, nameHost, secret);
        recieveAnswer(s, buffer, status);

        char * content = buffer + lenJump;
        printf("%s\r\n",content);

        sendResultInquiry(s, nameHost, content);
        printf("Result: %d\n", maxSum(content));

        memset(buffer, 0, MAXBUFLEN);

        recieveAnswer(s, buffer, status);
        printf("%s\n", buffer);
        return 0;
    }
}
