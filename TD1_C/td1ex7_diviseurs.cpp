#include<stdio.h>

int main(){
	int nbr;
	printf("Entrer un nombre :\n");
	scanf("%d",&nbr);
	printf("La liste des diviseurs de %d est comme suit :\n");
	for(int i=1;i<=nbr/2;i++){
		if(nbr%i==0)
		printf("\t%d\n",nbr/i);
	}
}
