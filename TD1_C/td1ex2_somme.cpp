#include<stdio.h>

int main(){
	int n , i , som=0;
	printf("entrer un nombre\n");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		som+=i;
	}
	printf("%d\n",som);
}
