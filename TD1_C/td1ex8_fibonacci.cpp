#include<stdio.h>

int Fibonacci (int);

int main(){
		int nbr;
	do{
	printf("Entrer un nombre: \n");
	scanf("%d",&nbr);
	}while(nbr<0);
		printf("le terme Un de la suite de Fibonacci est : %d\n",Fibonacci(nbr));
}

int Fibonacci (int n)
{
if (n==0 || n==1)
return (1);
else
return ( Fibonacci(n-1)+Fibonacci(n-2));
}
