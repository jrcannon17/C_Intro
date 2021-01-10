/*Filename: A1deprec.c *
 *Part of: Depreciation A590 program assignment *
 *Created by: Joshua Cannon *
 *Created on: 9/7/2018 *
 *Last Modified by: Joshua Cannon *
 *Last Modified on: 9/10/2018
 */

#include <stdio.h>

int main()

{
  /* Annual Depreciation = (P.Price-S.Value)/Years of Service */
  /*establish the variables needed to solve the equation as int */ 
  int pprice, yos, ad, svalue;
 /*I still need to experiment with this as the answer does not match the one in the example due to precision.*/

 
  /* svalue1 = 1;*/
  /*this was used as a test in the original.*/
 
  /*need to figure out how input can include commas and not spaces as there is no catch if a user decides to do so. */

 printf("Enter purchase price, years of service, and anuual depreciation: ");
 scanf("%d%d%d",&pprice,&yos,&ad);
 /*equation for solving problem. S is  */
 svalue = pprice - (ad*yos);

 printf("The salvage value is: %d",svalue);
 /*svalue needs to be a long float or double or is it the values themselves? I need to test this */
   return(0);
}

