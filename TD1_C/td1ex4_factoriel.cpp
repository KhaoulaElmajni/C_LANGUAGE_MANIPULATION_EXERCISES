#include<stdio.h>

int factoriel(int);

int main(){
	int nbr;
	
	printf("Entrer votre nombre:");
	scanf("%d",&nbr);
	if(nbr>=0)
	printf("le factoriel de %d = %d:",nbr,factoriel(nbr)); 
	else
	printf("un nombre positif est requis!");
}

int factoriel(int n){
	if(n==0)
	return 1;
	else
	return (n*factoriel(n-1));
}
