#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>

int main () {

    //string to send data
    char server_msg[256] = "You have reached the server";

    // create server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    //define the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9001);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    //bind the socket to our IP
    bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr));

    //to start listening to connections
    listen(server_socket, 5);
    
    //when we accept a connection we get a client socket that we need to write to
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    //send ddata to client socket
    send(client_socket, server_msg, sizeof(server_msg), 0);

    //close the socket
    close(server_socket);

    return 0;
}