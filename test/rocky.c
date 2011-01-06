#include <stdio.h>
#include <stdlib.h>


void rocky(){
	
	int i = 100;
	
	while( i > 0 ){
		
		printf( "%d \n" , i );
		fflush(stdout);
		char * a = ( char * )malloc( 10 * sizeof( char ) );
		
		free(a);
		
		printf( "%s \n" , a );
	
		i = i - 1;
		
	}
	
	
	
	
	}

int main(){
	
	rocky();
	
	
	}