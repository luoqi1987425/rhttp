#include <stdio.h>
#include <stdlib.h>    
#include "core.h"
#include "../mod_register/core.h"


extern rhttp_mod_register * rhttp_register;
extern rhttp_mod_register * rhttp_mod_register_instance();
extern void _start_listen();

static void _start( int argc, char * argv[] );
static void _init_register();
static void _init_config();
static void _init_so();
static void _init_mpm();



static rhttp_mod_bootstrap * _instance;

rhttp_mod_bootstrap * rhttp_mod_bootstrap_instance(){

	if( _instance == NULL ){
		_instance = ( rhttp_mod_bootstrap *)malloc( sizeof( rhttp_mod_bootstrap ) );
		_instance->start =_start;
	}

	return _instance;
}

static void _start( int argc, char * argv[] ){
    
    _init_register();
    _init_config();
    _init_so();
    _init_mpm();
    _start_listen();
    
}

static void _init_register(){
	rhttp_register	= rhttp_mod_register_instance(); 
}

static void _init_config(){
    //extern rhttp_mod_config *   rhttp_config     = mod_config_instance();
}

static void _init_so(){
    //extern rhttp_mod_so     *   rhttp_so         = mod_so_instance();
}

static void _init_mpm(){
    //char * mpm_name = "multhread";
    //rhttp_mod_mpm * rhttp_mod_mpm = rhttp_mod_mpm_factory(mpm_name);
}
