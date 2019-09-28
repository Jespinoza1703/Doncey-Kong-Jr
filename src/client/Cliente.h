//
// Created by jon on 19/9/19.
//

#ifndef CLIENTESOCKET_CLIENTE_H
#define CLIENTESOCKET_CLIENTE_H


#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define IP "192.168.43.226"
#define PORT 8080
#define MAX 1024

int sock;
struct sockaddr_in server_address;

void start();

void detenerCliente();
char *parserData();

int createSocket();

struct sockaddr_in serverAddress(struct sockaddr_in);

int conectarServer(int , struct sockaddr_in);

void enviarMensaje(char *);

char obtenerMensaje();

void parserMessage();
#endif //C_CLIENT_CLIENT_H

