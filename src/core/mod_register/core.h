#ifndef RHTTP_MOD_REGISTER_CORE_H
#define RHTTP_MOD_REGISTER_CORE_H

/**
 * register 模块的 接口方法
 *
 * set( "config" , config );
 * get( "config" )
 */
typedef struct{

	void 	(*set)( char * args  , void * );

	void *	(*get)( char * args );

}rhttp_mod_register;



rhttp_mod_register * rhttp_mod_register_instance();

void rhttp_mod_register_destory();


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
