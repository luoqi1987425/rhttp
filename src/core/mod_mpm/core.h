#ifndef RHTTP_MOD_MPM_CORE_H
#define RHTTP_MOD_MPM_CORE_H

/**
 * mod_mpm 模块的 接口方法
 * 
 */
typedef struct{
    
    void    (*start ) ( rhttp_mod_config * config );

	void 	(*process)( char * args  , void * );


}rhttp_mod_mpm;


rhttp_mod_mpm * rhttp_mod_mpm_factory( char * type );



#endif