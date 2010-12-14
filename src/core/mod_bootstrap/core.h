#ifndef RHTTP_MOD_REGISTER_CORE_H
#define RHTTP_MOD_REGISTER_CORE_H

/**
 * bootstrap 模块的 接口方法
 *
 * start( char * args )
 *
 */
typedef struct{

	void 	(*start)( char * args );

}rhttp_mod_bootstrap;



rhttp_mod_bootstrap * rhttp_mod_bootstrap_instance();



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
