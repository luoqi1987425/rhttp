#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "../global.h"
#include "../mod_mpm/core.h"

#define SERVERPORT  10088
#define MAXCONN_NUM 20
#define MAXDATASIZE 1025


extern rhttp_mod_mpm	* rhttp_mpm;


static int sockfd;

static struct sockaddr_in server_addr;

static void _init_socket();
static void _listen();
static void _accept();
static rhttp_request *  _build_rhttp_request( int client_fd , struct sockaddr_in * client_addr, char * buf );


void start_listen(){

    _init_socket();
    _listen();
    _accept();

}



static void _init_socket(){
    
    	if ( ( sockfd = socket ( AF_INET , SOCK_STREAM , 0) ) == - 1) {
		perror( "socket error" ) ;
	        exit(1);
	}
    
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = htons (SERVERPORT) ;
	server_addr.sin_addr.s_addr = INADDR_ANY ;
    
	if ( bind ( sockfd, ( struct sockaddr * ) & server_addr, sizeof ( struct sockaddr ) ) == - 1) {
	     perror ( "bind error" ) ;
	     exit(1);
	}
    
}

static void _listen(){
    
    	if ( listen ( sockfd, MAXCONN_NUM ) == - 1) {
	      perror ( "listen error" ) ;
	      exit(1);
	}
    
}

static void _accept(){
    	
	int sin_size = sizeof ( struct sockaddr_in ) ;
	int new_fd;
    int receive_numbytes;

    	while (TRUE) {
        
	    //init client information
	    struct sockaddr_in * client_addr = ( struct sockaddr_in * )malloc( sizeof ( struct sockaddr_in ) );
	    char	    * buf	  = ( char * )malloc( sizeof ( MAXDATASIZE ) );
	    
	    if ( ( new_fd = accept ( sockfd, ( struct sockaddr * )client_addr, &sin_size) ) == - 1) {
	            perror ( "accept error" ) ;
	            continue ;
	    }
    
	    if ( ( receive_numbytes = recv ( new_fd, buf, MAXDATASIZE, 0) ) == - 1) {
	            perror ( "recv error" ) ;
	            continue ;
	    }
        
        buf[receive_numbytes] = '\0';
    
	    rhttp_request * request = _build_rhttp_request( new_fd , client_addr , buf);
        rhttp_mpm->process( request );
	}   
}

static rhttp_request *  _build_rhttp_request( int client_fd , struct sockaddr_in * client_addr, char * buf ){
	
	rhttp_request * request = ( rhttp_request *)malloc( sizeof( rhttp_request ) );
	request->client_fd       = client_fd;
        request->client_addr 	= client_addr;
	request->buf	        = buf;
	return request; 
}
