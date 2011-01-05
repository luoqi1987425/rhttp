#include <stdio.h>
#include <stdlib.h>
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
    
    printf ( "server: got connection from " ) ;

}
