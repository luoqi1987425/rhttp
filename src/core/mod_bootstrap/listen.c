# include <stdio.h>
# include <string.h>
# include <sys/socket.h>
# include <netinet/in.h>

static int sockfd;

static struct sockaddr_in server_addr;
static struct sockaddr_in client_addr;

void _start_listen(){

    printf( "start listen \n" );
    //socket = _init_socket();
    //_listen();
    //_accept();

}

/**

static void _init_socket(){
    
    if ( ( sockfd = socket ( AF_INET , SOCK_STREAM , 0) ) == - 1) {
	        printf ( "socket error \n" ) ;
	        return 1;
	}
    
    server_addr. sin_family = AF_INET ;
	server_addr. sin_port = htons ( SERVERPORT) ;
	server_addr. sin_addr. s_addr = INADDR_ANY ;
    
    if ( bind ( sockfd, ( struct sockaddr * ) & server_addr, sizeof ( struct sockaddr ) ) == - 1) {
	     perror ( "bind error" ) ;
	     return 1;
	}
    
}

static void _listen(){
    
    if ( listen ( sockfd, MAXCONN_NUM) == - 1) {
	      perror ( "listen error" ) ;
	      return 1;
	}
    
}

static void _accept(){
    
    mod_mpm = mod_register->get("mpm");
    
    while (TRUE) {
        
		sin_size = sizeof ( struct sockaddr_in ) ;
	    if ( ( new_fd = accept ( sockfd, ( struct sockaddr * ) & client_addr, & sin_size) ) == - 1) {
	            perror ( "accept error" ) ;
	            continue ;
	    }
	    printf ( "server: got connection from %s\n" , inet_ntoa( client_addr. sin_addr) ) ;
    
	    if ( ( numbytes = recv ( new_fd, buf, MAXDATASIZE, 0) ) == - 1) {
	            perror ( "recv error" ) ;
	            return 1;
	    }
    
	    rhttp_request * request = _build_rhttp_request();
        mod_mpm->process( request );
	}
    
}

**/
