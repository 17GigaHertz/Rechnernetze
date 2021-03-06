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

	int ggt(unsigned int a, unsigned int b) {
	if (a == 0) { return b;}
		while(b != 0) {
			if (a>b){a = a - b;}
			else {b = b - a;}
   	 	}
	return a;		
	}


int main(int argc, char *argv[])
{
    int sockfd, sockfd_new;
    //int udp_sockfd;
    struct sockaddr_in tcp_addr, tcp_addr_new; // connector's address information
    //struct sockaddr_in udp_addr;
    struct hostent *he;
    int tcp_port;
    //int udp_port;
    unsigned int a = 0;
    unsigned int b = 0;
    socklen_t addrsize;

    printf("TCP Server\n\n");

    if (argc != 2)
    {
        fprintf(stderr,"Usage: tcpUdpServer tcpPort\n");
        exit(EXIT_FAILURE);
    }



    tcp_port = atoi(argv[0]);

/*
    //Resolv hostname to IP Address
    if ((he=gethostbyname(argv[0])) == NULL)
    {  // get the host info
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    } server_port;
*/
    /* ******************************************************************
    TO BE DONE: Create socket
    ******************************************************************* */

    //setup transport address
    tcp_addr.sin_family = AF_INET;
    tcp_addr.sin_port = htons((uint16_t)tcp_port);
    tcp_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(tcp_addr.sin_zero, '\0', sizeof tcp_addr.sin_zero);


	sockfd = socket(tcp_addr.sin_family, SOCK_STREAM, IPPROTO_TCP);





    /* ******************************************************************
    TO BE DONE:  Binding
    ***********************************************pack******************** */

    unsigned char buffer[4];
	
	bind(sockfd, (struct sockaddr*)&tcp_addr, sizeof(tcp_addr));
	//bind(sockfd, tcp_addr, sizeof(tcp_addr));
	//bind(udp_sockfd, udp_addr, sizeof(udp_addr));
	
	listen(sockfd, 10);
	addrsize = sizeof(tcp_addr);
	sockfd_new = accept(sockfd, (struct sockaddr*)&tcp_addr_new, &addrsize);
	

    /* ******************************************************************
    TO BE DONE:  Send data
    ******************************************************************* */
	int numbytes = recv(sockfd, buffer, sizeof(buffer),0);
    	printf("%lu bytes recived\n",sizeof(buffer));
	unpackData(buffer, &a, &b);
	/* ******************************************************************
    TO BE DONE:  Close socket
    ******************************************************************* */
	printf("Received a: %d  b: %d  ggt(a,b) = %d \n",a,b,ggt(a,b));	
	close(sockfd);
	
    return EXIT_SUCCESS;
}


