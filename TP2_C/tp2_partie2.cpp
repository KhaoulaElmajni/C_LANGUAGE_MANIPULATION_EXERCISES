#include <stdio.h>
#include <stdlib.h>
#include<math.h>


//declaration de la structure du polynome
typedef struct polynome{
		int degre;     
 		float A[10];
        } Polynome;

        //prototype des differents fcts utilisées
    Polynome saisir();
	void affiche(Polynome);
	double eval_iterative(Polynome,int ,double );
	Polynome derivee(Polynome );
	void racineApproche(Polynome,Polynome);

	Polynome D;

	
	double X[11],P[11];
	double X0;
	
int main(){
	
	Polynome p=saisir();
	printf("\n----------------la 1ere polynome ----------------:");
    affiche(p);
    printf("\n\n----------------le polynome derive du 1er polynome est ----------------:\n");
    D = derivee(p);
    printf("\nVeuillez Saisir la valeurs de X0 de l\'estimation initiale : ");
    scanf("%lf",&X0);
    	racineApproche(p,D);
    for(int i=0;i<=10;i++){
    	double resultPoly;
    	P[i]=eval_iterative(p,X[i],resultPoly);
	}

    for(int i=0;i<=10;i++){
    	printf("\t\tK=%d\t\tX%d = %lf\t\tP(X%d) = %lf\n",i,i,X[i],i,P[i]);
	}
    
}

void racineApproche(Polynome p, Polynome q){
	double resultPoly;
	X[0]=X0;
   for(int i=1;i<=10;i++){
   	X[i]=X[i-1]-(eval_iterative(p,X[i-1],resultPoly)/eval_iterative(q,X[i-1],resultPoly));
   }
   
}

//fct d'affichage de polynome
void affiche(Polynome p){

      printf("\nP(x)=\t");
    
        for(int i=0;i<=p.degre;i++){
            printf("(%.2f) * X ^ %d",p.A[i],i);
            if(i<p.degre)
            	printf(" + ");
            }
            
   }
   
// fct de saisir les coefficients de polynome
	Polynome saisir(){
	Polynome p;
	do{
 			printf("Entrer le degre du polynome N.B:le degre maximale limite a 10 : ");
			scanf("%d", &p.degre);
 			}while(p.degre>10 && p.degre<=0);
	
	for (int i=0 ; i<=p.degre ; i++)
    {
     printf("Quelle valeur aura votre coefficient A%d : ", i);
     scanf("%f", &p.A[i]);
    }
	return p;
}

//fct de calcule de polynome avec un réel
   double eval_iterative(Polynome p,int x,double resultPoly){
    
int i;
 for (resultPoly=0, i=0 ; i<=p.degre ; i++)
      {
      	resultPoly+=p.A[i]*pow(x,p.degre-i);
	  }
	  resultPoly+=p.A[0];
	  return resultPoly;
}

//fct de calcule de la derivée d'un polynome
Polynome derivee(Polynome p){
  Polynome D;
   for(int i=0 ;i<=p.degre;i++){
   D.A[i]=i*p.A[i];
	
   }
   
   printf("P(x)=\t");
    
        for(int i=0;i<=D.degre;i++){
        	if(D.A[i]==0)continue;
            printf("(%.2f) * X ^ %d",D.A[i],i-1);
            if(i<D.degre)
            	printf(" + ");
            }
   
return D;
}


