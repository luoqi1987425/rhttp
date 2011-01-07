#include <stdio.h>
#include <stdlib.h>

typedef struct{
	
	char * a;
	
	}ROCKY;

void rocky(){
	
	ROCKY * a = malloc( sizeof( ROCKY ) );
	char    * b = malloc( 10 * sizeof( char ) );
	
	a->a = b;
	
	free( b );
	free( a );
	
	
	
	
	}

int main(){
	
	rocky();
	
	
	}