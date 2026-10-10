#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>


int main() {

    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0); // domain : AF_INET, type of socket : TCP socket (SOCK_STREAM), protocol : 0 (tcp)

    //create an addr structure to specify where to connect to
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9001);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct sockaddr *) &server_addr,sizeof(server_addr)); // 0 : good, -1 : issue
    // check for error with connection 

    if(connection_status == -1) {
        printf("There was an error making a connecction \n");
    }

    //to receive the data from server
    char server_resp[256];
    recv(network_socket, &server_resp, sizeof(server_resp), 0);


    //print out the data we get back 
    printf("The server sent the data: %s", server_resp);

    //close the socket
    close(network_socket);


    return 0;
}