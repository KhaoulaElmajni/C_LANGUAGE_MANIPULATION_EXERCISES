#include <stdio.h>

long pgcd (long a, long b);
int main ()
{
   int x,max,y,z;

      printf ("Donnez une valeur maximale a ne pas depasser:\n");
	  scanf("%d", &max);
 
   for (x=1;x<max;x++)
   {
      
      for (y=1;y<max;y++)
      {
         
         for (z=1;z<max;z++)
        {
         if( (x*x+y*y==z*z) & (x<y) & (y<z)  & pgcd(x,y)==1 & pgcd(x,z)==1 & pgcd(z,y)==1)
         {
               printf ("(%d,%d,%d)\n", x, y, z);
            }
         }
      }
   }
   }
   
   long pgcd (long x, long y) {
  long r;
   
  while (1) {
    r = x % y;
    if (r == 0)
      return y;
    x = y;
    y = r;
  }
}
