#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

#define NO_FLAGS_SET 0
#define PORT 80
#define MAXBUFLEN 20480

SOCKET createSocket(){
    SOCKET recvSocket;
    recvSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(recvSocket != INVALID_SOCKET){
	    return recvSocket;
	}
	printf("ERROR: socket unsuccessful\r\n");
    exit(EXIT_FAILURE);
}

SOCKADDR_IN newSocketAddr(const char * hostName){
     char * IP;
     struct hostent * remoteHost;
     remoteHost = gethostbyname(hostName);
     IP = inet_ntoa(*(struct in_addr *)*remoteHost->h_addr_list);
     SOCKADDR_IN recvSocketAddr;
     memset(&recvSocketAddr, 0, sizeof(recvSocketAddr));
     recvSocketAddr.sin_port = htons(PORT);
     recvSocketAddr.sin_family = AF_INET;
     recvSocketAddr.sin_addr.s_addr = inet_addr(IP);
     return recvSocketAddr;
}

void connectingWithServer(SOCKADDR_IN recvSocketAddr, SOCKET recvSocket){
    if(connect(recvSocket,(SOCKADDR*)&recvSocketAddr,sizeof(SOCKADDR_IN)) == SOCKET_ERROR){
        printf("ERROR: socket could not connect\r\n");
        closesocket(recvSocket);
        WSACleanup();
        exit(EXIT_FAILURE);
    }
}

void sendRequest(SOCKET recvSocket, const char * hostName, char * content){
    char request[100];
    sprintf(request, "GET /var/6?%s HTTP/1.1\r\nHost:%s\r\n\r\n", content, hostName);
    send(recvSocket, request, strlen(request), 0);
}

void sendResultRequest(SOCKET recvSocket, const char * hostName, char * content){
    char result[100];
    char request[100];
    sprintf(result, "result=%d", ColumnWithMaxSum(content));
    sprintf(request, "POST /var/6 HTTP/1.0\r\n"
		"Host: %s\r\n"
		"Content-length: %d\r\n\r\n"
		"%s\r\n", hostName, strlen(result), result);
    send(recvSocket, request, strlen(request), 0);
}

void recieveAnswer(SOCKET recvSocket, char * buffer, int status){
    int numrcv = 0;
    numrcv = recv(recvSocket, buffer, MAXBUFLEN, NO_FLAGS_SET);
    if (numrcv == SOCKET_ERROR){
        printf("ERROR: recvfrom unsuccessful\r\n");
        status = closesocket(recvSocket);
        if(status == SOCKET_ERROR)
			printf("ERROR: closesocket unsuccessful\r\n");
        status = WSACleanup();
        if (status == SOCKET_ERROR)
			printf("ERROR: WSACleanup unsuccessful\r\n");
        exit(EXIT_FAILURE);
    }
}
int ColumnWithMaxSum(char * matrix){
    int count = 0;
    int max = 0;
    int maxIndex;
    for(int i = 0; i <= strlen(matrix); i++){
        if( *(matrix + i) == '\0' || *(matrix + i) == '\n')
            count++;
    }
    int sumColumn[count];
    for(int i = 0; i < count; i++){
        sumColumn[i] = 0;
    }
    for(int i = 0; i < count; i++){
        for(int k = 0; k < count; k++){
            sumColumn[k] += strtol(matrix, &matrix, 10);
        }
    }
    for(int i = 0; i < count; i++){
        if(sumColumn[i] > max){
            max = sumColumn[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main(void) {
    WSADATA data;
    SOCKADDR_IN recvSocketAddr;
    SOCKET recvSocket;
    int status;
    const char * hostName = "pb-homework.appspot.com";
    char buffer[MAXBUFLEN];
    memset(buffer,0,MAXBUFLEN);
    status = WSAStartup(MAKEWORD(2, 2), &data);
    if(status != 0)
    {
        printf("ERROR: WSAStartup unsuccessful\r\n");
        return 0;
    }

    recvSocketAddr = newSocketAddr(hostName);
    recvSocket = createSocket();
    connectingWithServer(recvSocketAddr, recvSocket);

    sendRequest(recvSocket, hostName, "");
    recieveAnswer(recvSocket, buffer, status);

	char * secret = strstr(buffer, "secret");
	int len_jump = strlen(buffer) - strlen(secret);

	sendRequest(recvSocket, hostName, secret);
    recieveAnswer(recvSocket, buffer, status);

    char * content = buffer + len_jump;
    printf("%s\r\n",content);

    sendResultRequest(recvSocket, hostName, content);
    printf("Result: %d\n", ColumnWithMaxSum(content));

    memset(buffer, 0, MAXBUFLEN);

    recieveAnswer(recvSocket, buffer, status);
    printf("%s\n", buffer);
    return 0;
}
