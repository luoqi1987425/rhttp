#ifndef RHTTP_MOD_INIT_CORE_H
#define RHTTP_MOD_INIT_CORE_H

//interface

typedef struct{

	rhttp_mod_init_entity * (*init)( char * args );

}rhttp_mod_init_core



//mod factory

rhttp_mod_init_core * rhttp_mod_init_instance();

void rhttp_mod_init_destory();


#endif
