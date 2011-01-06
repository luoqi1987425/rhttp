#ifndef RHTTP_GLOBAL_H
#define RHTTP_GLOBAL_H

typedef struct{
    
    int                  client_fd;
    struct sockaddr_in * client_addr;
    char               * buf;
    
}rhttp_request;


typedef struct{
    
    
    
}rhttp_response;

#ifndef NULL
	#define NULL 0
#endif

#ifndef TRUE
	#define TRUE 1
#endif

#ifndef FALSE
	#define FALSE 0
#endif


#endif
