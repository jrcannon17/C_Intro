#include <stdio.h>

main()
{
  int b,i,number;

  printf("enter number: ");
  scanf("%d",&number);
  for(i=0; i*i <= number;i++)
    {
      for(b=0; b*b <= number; b++)

    if (i*i + b*b==number)
     printf("%d +  %d\n",i*i,b*b);

    }
  return(0);
}
