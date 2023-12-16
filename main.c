#include "main.h"
#include <stdio.h>

/**
 * @ Discription - main shell program.
 * 
 *  
*/
int main (int argc, char *argv[])
{
	if(argc < 1)
	{
		printf("$: %s/n", argv[0]);
		return 1;
	}
	while(1)
	{
    		s_loop();
    		printenv();
	}
	return 0;
}
