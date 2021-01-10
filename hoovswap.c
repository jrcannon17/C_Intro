#include <stdio.h>

int main()
{
  int num,i,j,k,swap,n;


  char c[8];

  c[0]='f'; c[1]='r'; c[2]='o'; c[3]='g'; c[4]=0;



  printf("Initial values for first 5 cells: %c,%c,%c,%c,%c\n",c[0],c[1],c[2],c[3],c[4]);

  /*initialize i as the start of the for loop */
  for (i=0; i<4; i++)
    {

      /*K now becomes the last incrememnt that was i */
      k=i;
            
      /*J is now intialized as one greater than i and k */
       
      for (j=i+1; j<4; j++)
				
	printf("%d is j %d is k\n",c[j],c[k]);	 
        if (c[j]-c[k] < 10)
	  
	              
	  k=j;
      swap=c[i];
     
      c[i]=c[k];
      c[k]=swap;
	
 }  
  printf("Final values: i: %d, j: %d, k: %d, swap: %d\n",i,j,k,swap);
  printf("Final values for first 5 cells after we swap: %c,%c,%c,%c,%c\n",
	 c[0],c[1],c[2],c[3],c[4]);

  printf("Final values for first 8 cells after we swap: %c,%c,%c,%c,%c,%c,%c,%c\n",
	 c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7]);

  return(0);

}  
