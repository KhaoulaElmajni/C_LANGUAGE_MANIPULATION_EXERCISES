#include<stdio.h>
#include<stdlib.h>

int main(){
	int nbrEntier,min ,max,som;
	double moy;
	
		do{
				printf("Entrer le nombre des elements de votre suite a condition qu il n'est pas nulle ou negatif\n");
				scanf("%d",&nbrEntier);
			}while(nbrEntier<=0);
	
	int *suite=(int*) malloc(nbrEntier * sizeof(int));
		printf("Maintenant veuillez saisir votre suite de nombre!\n");
		for(int i=0;i<nbrEntier;i++)
		{
			do{
				printf("\tl element numero %d : ",i+1);
			scanf("%d",suite+i);
			}while(*(suite+i)<0);
			
		}
		som=min=max=*(suite+0);
		for(int i=1;i<nbrEntier;i++)
		{
			
			som += *(suite+i);
			
		if(*(suite+i)<min){
			
			min=*(suite+i);
			}
			else if (*(suite+i)>max)
		{
			max = *(suite+i);
		}
		}
		
		moy=som/2;
		
		printf("Alors l element minimale de votre suite est :%d\n",min);
		printf("Alors l element maximale de votre suite est :%d\n",max);
		printf("Alors la moyenne de votre suite est :%f\n",moy);

	
}
