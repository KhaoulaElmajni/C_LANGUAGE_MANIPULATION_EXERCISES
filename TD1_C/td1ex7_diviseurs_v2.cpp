#include<stdio.h>

int* lstDiviseurs(int);

int main(){
	int nbr,som=0;
	int *T;
do{
	printf("Entrer un nombre: \n");
	scanf("%d",&nbr);
	}while(nbr<0);
	T=lstDiviseurs(nbr);
	for(int i=0;i<100;i++){
		som=som+ *(T+i);
	}
	if(som==nbr)
		printf("le nombre entre est PARFAIT!");
	if(som<nbr)
		printf("le nombre entre est DIFICIENT!");
	if(som>nbr)
		printf("le nombre entre est ABONDANT!");
}

int* lstDiviseurs(int n){
int *T;
for(int i=1;i<=n/2;i++){
		if(n%i==0)
		T[i-1]=n%i;
}
return T;
}
