#include <stdio.h> 
int  main( )
{  
	int count=0;
int  x, y, z;
 for (x=1; x<20; x++)
     for (y=1; y<33; y++)
          for (z=3; z<100; z+=3)
               if (5*x+3*y+z/3==100 && x+y+z==100)
               {
               		printf("x=%d, y=%d, z=%d\n", x, y, z);
               		count++;
			   }
	printf("%d\n",count);
	return 0;
}
