#include <stdio.h>
#include <stdlib.h>
#include "core/mod_bootstrap/core.h"
#include "core/mod_register/core.h"

//全局变量
rhttp_mod_bootstrap * rhttp_bootstrap;
rhttp_mod_register  * rhttp_register;
//rhttp_mod_config    * rhttp_config;
//rhttp_mod_so        * rhttp_so;
//rhttp_mod_mpm       * rhttp_mpm;


int main( int argc, char * argv[] ){

    rhttp_bootstrap = rhttp_mod_bootstrap_instance();
    rhttp_bootstrap->start( argc , argv );

}

