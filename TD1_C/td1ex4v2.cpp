#include<stdio.h>

int factoriel(int);

int main(){
for(int i =0;i<=10;i++){
	printf("le factoriel de %d = %d\n",i,factoriel(i)); 
 	}
}

int factoriel(int n){
	if(n==0)
	return 1;
	else
	return (n*factoriel(n-1));
}
