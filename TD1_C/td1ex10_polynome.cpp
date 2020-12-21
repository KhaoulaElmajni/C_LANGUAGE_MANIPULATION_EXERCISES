#include <stdio.h>
#include <math.h>

double eval_iterative(int,float,float*,double);

main()
{

 int degre;     
 float A[10],x;
 double resultPoly;    

 do{
 	printf("Entrer le degre du polynome N.B:le degre maximale limite a 10 : ");
 scanf("%d", &degre);
 }while(degre>10 && degre<=0);
 printf("Entrer la valeur x de votre reel : ");
 scanf("%f", &x);

 resultPoly =eval_iterative(degre,x,A,resultPoly);
 printf("Valeur du polynome pour x = %.5f : %.5f\n", x, resultPoly);
 return 0;
}

double eval_iterative(int degre,float x,float* A,double resultPoly){
	for (int i=0 ; i<=degre ; i++)
    {
     printf("Quelle valeur aura votre coefficient A%d : ", i);
     scanf("%f", &A[i]);
    }
    
int i;
 for (resultPoly=0, i=0 ; i<=degre ; i++)
      {
      	resultPoly+= A[i]*pow(x,degre-i);
	  }
	  return resultPoly;
}



