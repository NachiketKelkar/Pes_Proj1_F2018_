
/*
****************************************************************************************************************************************************************************
FILENMAE	:disp.c
DESCRIPTION	:Function to display the contents of memory in unsigned 32-bit hexadecimal format.The user may specify an address and
                 the  number of 32bit words to display
AUTHOR NAME	:Puneet Bansal & Nachiket Kelkar
TOOLS USED	:GCC, GNU MAKE			
****************************************************************************************************************************************************************************
*/

#include <stdio.h>
#include "disp.h"
#include "allocate.h"
#include "write.h"

int disp()
{
   int scan,offset=0;
   int k=1;int l;
   if(mem==NULL)
   {
      printf("There is no memory allocated");	 //To check whether memory has been allocated or not            
   }
   else
   {
      printf("\n\nDo you wish to:\n(1)Type the address whose data you want to see\n(2)Give an offset from %p\n>>",mem);
      scanf("%d",&scan);
      switch(scan)					//Check whether the user wants to input address or offset
      {
         case 1: 
	 printf("\nEnter the address on which you want to see the contents\n>>");
	 scanf("%p",&u_disp_add);			//Get the memory address from the user
	 break;
	
	 case 2:
	 printf("\nEnter the offset from %p\n>>",mem);
	 scanf("%d",&offset);
	 u_disp_add=mem+offset;				//Calculating the starting address of the memory that user wants to display using offset
	 break;
	
	 default:
	 printf("Invalid choice");
	 break;
      }

      printf("\nEnter the no of blocks you want to see\t\n>>");
      scanf("%d",&no_of_blocks);
      j=(uint32_t *)malloc(8);

      for(j=mem;j<=memlast;j++)				//Loop starts from the starting address of the first block of allocated memory to the starting add of the last block of allocated memory
      {
         if(j==u_disp_add)				//If j is equal to the address entered by the user, break from the loop
	 {
	    break;		
	 }
	 else
	 {
	    k++;					//If j is not equal to address entered by user, increment k	
	 }
      }
      if(k==(size+1))					//Condition to check whether entered address is valid or not
      {
         printf("\nMemeory entered is not valid\nType disp to try again or help to see the menu\n>>");
      }
      else if(no_of_blocks<=(size-(k-1)))		//Condition to check whether the entered block size is valid or not
      {
         for(l=0;l<no_of_blocks;l++)
 	 {
	    printf("\nData at address %p is %x",j,*j);	//Prints the data present at the specific adddress
	    j++;
	 }
      printf("\nType the function you would like to perform or type help to see the menu\n>>");	
       }
      else
      {
         printf("The number of blocks entered is invalid\nType disp to try again or help to see the menu\n>>");}
      }
   return 0;
}
