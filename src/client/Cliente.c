//
// Created by jon on 19/9/19.
//


#include "Cliente.h"

void start() {

    sock = createSocket();
    server_address = serverAddress(server_address);
    printf("inicia Cliente \n");
    conectarServer(sock, server_address);

}

int createSocket() {
    int status = socket(AF_INET, SOCK_STREAM, 0);
    if (status < 0) printf("Error de Socket");
    return status;
}

struct sockaddr_in serverAddress(struct sockaddr_in serverAddress) {
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);

    if(inet_pton(AF_INET, IP, &serverAddress.sin_addr) <= 0)
    {
        printf("Error de dirección");
    }

    return serverAddress;
}

int conectarServer(int socket, struct sockaddr_in serverAddress) {
    int status = connect(socket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    if (status < 0) {
        printf("Conexión fallida\n");
        status = -1;
    }
    return status;
}

void enviarMensaje(char *message) {
    write(sock, message, strlen(message));
    printf("Client send: %s \n", message);
}

void detenerCliente() {
    printf("Finaliza conexión\n");
    close(sock);
}


char obtenerMensaje  () {


   char message;

   read(sock, message, sizeof(message));
printf("Client read: %s \n", message);
return message;


}

char* parserData(){
    char *message[MAX];

    read(sock, message, sizeof(message));


    char *str= message;
    int init_size = strlen(str);
    char delim[] = ",";

    char *ptr = strtok(str, delim);

    return ptr;


}
