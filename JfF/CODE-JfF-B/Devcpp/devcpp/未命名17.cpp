#include <stdio.h>
int main( )
{  int  i, sum=0;
   char  ch;
   for (i=1; i<=5; i++)
      { ch=getchar( );
         if ( ch<'0' || ch>'9' )
               continue; 
         sum++;
      }
  printf("%d\n", sum);
  return 0;
}

