#include <stdio.h>

main()

{

  int x;
  /* x=0;

  for (i=0; i<4; i++)
    {
      x=x+i;
      printf("%d\n",x);
      }*/
  int i,j,number;
    
  printf("Enter a number: ");
  scanf("%d",&number);
  i=1;
  while (i*i<= number)
    {
      j=1;
      while (j<=i)
	{
       if (i*i + j*j == number)
	   printf("Found: %d + %d\n",i*i,j*j);
	 j++;
     
	}
      i=i+1;
   }
 
 return(0);
}
