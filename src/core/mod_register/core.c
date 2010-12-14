#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "core.h"


typedef struct rhttp_mod_register_data{

	char * _key;
	void * _config;
	struct rhttp_mod_register_data * _next;

}rhttp_mod_register_data;



static rhttp_mod_register * _instance;

static rhttp_mod_register_data * _first_data;
static rhttp_mod_register_data * _last_data;


static void _set( char * args  , void * _config);
static void _create_new( char * args  , void * _config );
static int  _set_exist( char * args  , void * _config );
static int  _is_equal( rhttp_mod_register_data * data , char * args );
static void _set_value( rhttp_mod_register_data * data , void * config );
static void * _get( char * args );


rhttp_mod_register * rhttp_mod_register_instance(){

	if( _instance == NULL ){
		_instance = ( rhttp_mod_register *)malloc( sizeof( rhttp_mod_register ) );
		_instance->get =_get;
		_instance->set = _set;
	}

	return _instance;
}


void rhttp_mod_register_destory(){
	if( _instance != NULL ){
		free(_instance);
	}
}


static void _set( char * args  , void * _config){
	int is_exist = _set_exist( args , _config );
	if( is_exist == 0 ){
		_create_new( args , _config );
	}
}

static void _create_new( char * args  , void * _config ){

	rhttp_mod_register_data * _data = ( rhttp_mod_register_data * )malloc( sizeof( rhttp_mod_register_data ) );
	_data->_key 	= args;
	_data->_config 	= _config;

	if( _first_data == NULL ){
		_first_data = _data;
		_last_data  = _data;
	}else{
		_last_data->_next = _data;
		_last_data = _data;
	}

}

static int _set_exist( char * args  , void * _config ){

	int rtn = 0;
	rhttp_mod_register_data * current = _first_data;

	while( current != NULL ){


		if( _is_equal( current , args )){
			_set_value( current , _config );
			rtn = 1;
			break;

		}else{
			current = current->_next;
		}

	}

	return rtn;


}

static int _is_equal( rhttp_mod_register_data * data , char * args ){

	int a = strcmp( data->_key , args );
	if( a != 0 ){
		return 0;
	}else{
		return 1;
	}
}

static void _set_value( rhttp_mod_register_data * data , void * config ){
	data->_config = config;
}



static void * _get( char * args ){

	void * rtn;

	rhttp_mod_register_data * current = _first_data;

	while( current != NULL ){

		if(_is_equal( current , args )){

			rtn = current->_config;
			break;

		}else{
			current = current->_next;
		}

	}

	return rtn;

}
