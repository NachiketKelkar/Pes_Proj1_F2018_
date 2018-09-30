#include<stdio.h>
#include<string.h>
#include "help.h"
#include "allocate.h"
#include "write.h"
#include "disp.h"

typedef struct { char *ip; int (*funcp)();}lookup;

int main()
{
int i=0;
lookup table[]={{"help",&help},{"allocate",&allocate},{"write",&write},{"disp",&disp}};//{"free",&free},{"invert",&invert},{"write_pattern",&write_pattern},{"verify_pattern",&verify_pattern},{"ext",&ext}};
char input[15]; 

printf("Welcome to the command line \n Type Help to see the commands\n");
do{

scanf("%s",input);


for(i=0;i<4;i++)
{
if(strcmp(input,table[i].ip)==0)
	{
	(*table[i].funcp)();
	}
}

}while(strcmp(input,"ext")!=0);
return 0;

}


	
