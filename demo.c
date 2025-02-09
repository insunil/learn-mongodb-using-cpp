/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{   // single comment  command +/
   /* multi line comment
     shift + option + A
   */
 int count=0,power,i,r,sum=0,n,temp;
printf("enter the number\n");
 scanf("%d",&n);
 temp=n;

 //count the number of digits
 while(n)
 {

     count++;
     n=n/10;
 }


 n=temp;
 //take each digit
 while(n)
 {
     r=n%10;
     power=1;
     //calculate power of each digit
     for(i=1;i<=count;i++)
     {
         power=power*r;
     }

     sum=sum+power;
     n=n/10;
 }

  if(sum==temp)
 if(sum==temp)
  {
      printf("armstrong number\n");
  }
  else
  {
      printf("not armstrong number\n");
  }



    return 0;
}
