/*
############################################################################
#                                                                          #
# Copyright TU-Berlin, 2011-2015                                           #
# Die Weitergabe, Veröffentlichung etc. auch in Teilen ist nicht gestattet #
#                                                                          #
############################################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_LENGTH 100


/*
int packData(unsigned char *buffer, unsigned int a, unsigned int b)
{
    /* ******************************************************************
    TO BE DONE:  pack data
    ******************************************************************* *
	buffer[0]=a>>8;
	buffer[1]=a;
	buffer[2]=b>>8;
	buffer[3]=b;

    return 0; */

	void unpackData(unsigned char *buffer, unsigned int *a, unsigned int *b)

	{
	*a = (buffer[0]<<8) | buffer[1];
	*b = (buffer[2]<<8) | buffer[3];
	}


int main(int argc, char *argv[])
{
    int tcp_sockfd;
    struct sockaddr_in tcp_addr; // connector's address information
    struct hostent *he;
    struct addrinfo hints;
    struct addrinfo *servinfo; // will point to the results
    int tcp_port;
    int status;
    int a = 0;
    int b = 0;





    printf("UDP TCP Server\n\n");

    if (argc != 2)
    {
        fprintf(stderr,"Usage: tcpUdpServer tcpPort\n");
        exit(EXIT_FAILURE);
    }



    tcp_port = atoi(argv[1]);

    memset(&hints, 0, sizeof hints); // make sure the struct is empty
    hints.ai_family = AF_UNSPEC; // don't care IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
    hints.ai_flags = AI_PASSIVE; // fill in my IP for me

    if ((status = getaddrinfo(NULL, tcp_port, &hints, &servinfo)) != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    tcp_sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    printf("%s",argv[1]);
    return 0;
//    tcp_sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);


    /* ******************************************************************
    TO BE DONE:  Binding
    ***********************************************pack******************** */

    unsigned char buffer[4];

	/*bind(tcp_sockfd, tcp_addr, sizeof(tcp_addr));

	listen(tcp_sockfd, 10);

	accept(tcp_sockfd, (struct sockaddr*)&their_addr, sizeof(their_addr));*/

    /* ******************************************************************
    TO BE DONE:  Send data
    ******************************************************************* */
	//recv(tcp_sockfd, buffer, sizeof(buffer),0);
//	recvfrom(udp_sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&their_addr, sizeof(their_addr));

	//unpackData(buffer, a, b);
	/* ******************************************************************
    TO BE DONE:  Close socket
    ******************************************************************* */
	//close(tcp_sockfd);
    return EXIT_SUCCESS;
}
