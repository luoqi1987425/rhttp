#ifndef RHTTP_MOD_BOOTSTRAP_CORE_H
#define RHTTP_MOD_BOOTSTRAP_CORE_H

/**
 * bootstrap 模块的 接口方法
 * 
 * start( int argc, char * argv[] )
 * -e production|development|testing
 * -c /var/config.xml
 */
typedef struct{

	void 	(*start)( int argc, char * argv[] );

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
