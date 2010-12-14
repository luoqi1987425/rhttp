#include "listen.h"

void start( char * args ){
    
    _init_register();
    _init_config();
    _init_so();
    _init_mpm();
    _start_listen();
    
}

static void init_register(){
    extern rhttp_mod_register * rhttp_register   = mod_register_instance(); 
}

static void init_config(){
    extern rhttp_mod_config *   rhttp_config     = mod_config_instance();
}

static void init_so(){
    extern rhttp_mod_so     *   rhttp_so         = mod_so_instance();
}

static void init_mpm(){
    char * mpm_name = "multhread";
    rhttp_mod_mpm * rhttp_mod_mpm = rhttp_mod_mpm_factory(mpm_name);
}
