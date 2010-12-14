#include "multhread/core.h"

rhttp_mod_mpm * rhttp_mod_mpm_factory( char * type ){
        
    if( type == "multhread" ){
        _instance = ( rhttp_mod_mpm *)malloc( sizeof( rhttp_mod_mpm ) );
		_instance->start    = multhread_start;
		_instance->process  = multhread_process;
    }
}