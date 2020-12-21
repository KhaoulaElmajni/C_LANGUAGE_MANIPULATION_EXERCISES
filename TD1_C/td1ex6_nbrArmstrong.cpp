#include<stdio.h>

int main()  
{ 
  int nbr, a, tmp, somme=0;  
  
  printf(" Entrez un nombre: ");
  scanf("%d", &nbr);  
  
  tmp=nbr;  
  
  while(nbr>0)  
  { 
    a=nbr%10;  
    somme=somme+(a*a*a);  
    nbr=nbr/10;  
  }  
  if(tmp==somme)  
    printf(" %d est un nombre Armstrong",tmp);  
  else  
    printf(" %d n'est pas un nombre Armstrong",tmp);  
  return 0;
} 
