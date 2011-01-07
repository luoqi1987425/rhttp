#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "../global.h"    
#include "core.h"



static rhttp_mod_mpm * _instance;
static void _simple_process( rhttp_request * request );


rhttp_mod_mpm * rhttp_mod_mpm_factory( char * type ){
        
    _instance 		= ( rhttp_mod_mpm *)malloc( sizeof( rhttp_mod_mpm ) );
    _instance->process  = _simple_process;
}

static void _simple_process( rhttp_request * request ){
    
	
    printf ( "server: data is %s \n" , request->buf );
	
    free( request->buf );
	printf( "1111" );
    fflush( stdout );
    free( request );
	printf( "2222" );
    fflush( stdout );
    //free
   /*
    free( request->buf );
	 printf( "2222" );
    fflush( stdout );
    close( request->client_fd );
    free( request );
	 printf( "3333" );
    fflush( stdout );
    */

}
