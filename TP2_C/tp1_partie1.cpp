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
	void additionner(Polynome ,Polynome );
	void soustraire(Polynome ,Polynome );
	Polynome ChangerSigne(Polynome );
	int comparer(Polynome ,Polynome );
	Polynome derivee(Polynome );
	void courbe(Polynome,Polynome );
	Polynome A, B,D1,D2;
	int tabCourbe[10][10];

			

        int main(){
        	
        	int x,cmp;
        	double resultPoly;  
			Polynome p=saisir();
        	Polynome q=saisir();
        	Polynome pn,qn;
        	printf("\n----------------la 1ere polynome ----------------:");
        	affiche(p);
        	printf("\n\n----------------la 2eme polynome ----------------:");
        	affiche(q);
        	printf("\n\n----------------l\'addition des deux polynomes ----------------:");
        	additionner(p,q);
     		affiche(A);
     		printf("\n\n----------------la soustraction des deux polynomes ----------------:");
     		soustraire(p,q);
        	affiche(B);
        	
         printf("\n\n----------------le polynome derive du 1er polynome est ----------------:\n");
        D1 = derivee(p);
        
        printf("\n\n----------------le polynome derive du 2eme polynome est ----------------:\n");
        D2 = derivee(q);
        
         printf("\n----------------La comparaison des 2 polynomes :----------------\n");
        
        cmp=comparer(p,q);
        if(cmp==0)
        	printf("\nles Deux Polynomes sont egaux.\n");
        else if(cmp==1)
        	printf("\nle 1er polynome est superieur du 2eme.\n");
        	
        else if(cmp==(-1))
        	printf("\nle 1er polynome est inferieur du 2eme.\n");
        	
     	printf("\nEntrer la valeur x de votre reel : \n");
 		scanf("%d", &x);
		 resultPoly =eval_iterative(p,x,resultPoly);  	
        printf("\nValeur de la 1ere polynome pour x = %d : %.5f\n", x, resultPoly);
        
        resultPoly =eval_iterative(q,x,resultPoly);  	
        printf("\nValeur de la 2eme polynome pour x = %d : %.5f\n", x, resultPoly);
        
        printf("\n----------------Apres le changement de signe de la 1ere polynome:----------------\n");
        pn=ChangerSigne(p);
        affiche(p);
        printf("\n----------------Apres le changement de signe de la 2eme polynome:----------------\n");
        qn=ChangerSigne(q);
        affiche(q);
        printf("\n\n----------------La courbe du 1er et le 2eme polynome :----------------\n");
        courbe(p,q);
         
		
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
//fct d'affichage de polynome
void affiche(Polynome p){

      printf("\nP(x)=\t");
    
        for(int i=0;i<=p.degre;i++){
            printf("(%.2f) * X ^ %d",p.A[i],i);
            if(i<p.degre)
            	printf(" + ");
            }
            
          //printf("%.2f",p.A[0]);
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
//fct d'addition de 2 polynomes
void additionner(Polynome p,Polynome q){
	
	if(p.degre==q.degre){
		A.degre = p.degre;
  for (int i = 0; i <= p.degre; i++)
    A.A[i] = p.A[i] + q.A[i];
}
	else if(p.degre>q.degre){
		A.degre = p.degre;
		for (int i = 0; i < p.degre; i++)
		{	
			 A.A[i]  = p.A[i] + q.A[i];
		}
	}
	else if(p.degre<q.degre){
		A.degre = q.degre;
		for (int i = 0; i < q.degre; i++)
		{		
			 A.A[i] = p.A[i] + q.A[i];
		}
	}

}
//fct de soustraction de 2 polynomes
void soustraire(Polynome p,Polynome q){
		if(p.degre==q.degre){
		B.degre = p.degre;
  for (int i = 0; i <= p.degre; i++)
    B.A[i] = p.A[i] - q.A[i];
}
	else if(p.degre>q.degre){
		B.degre = p.degre;
		for (int i = 0; i < p.degre; i++)
		{	
			 B.A[i]  = p.A[i] - q.A[i];
		}
	}
	else if(p.degre<q.degre){
		B.degre = q.degre;
		for (int i = 0; i < q.degre; i++)
		{		
			 B.A[i] = p.A[i] - q.A[i];
		}
	}
}
//fct de changement de signe d'un polynome
Polynome ChangerSigne(Polynome p){
	for (int i = 0; i <= p.degre; i++)
    p.A[i] = -p.A[i];
    return p;
}
//fctr de comparaison de 2 polynomes
int comparer(Polynome p,Polynome q){
	if(p.degre==q.degre){		
  for (int i = 0; i <= p.degre; i++){
  	if(p.A[i]!=q.A[i])
   return 0;
   else return 1;
  }
}
	
else if(p.degre>q.degre){
	
		return 1;
	}
	else if(p.degre<q.degre){
		return -1;
	}	
}
//fct de calcule de la derivée d'un polynome
Polynome derivee(Polynome p){
  Polynome D;
   for(int i=0 ;i<=p.degre;i++){
   D.A[i]=i*p.A[i];
   //tab[i]=i*p.A[i];
	
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
//fct de trace de la courbe d'un polynome
void courbe(Polynome p,Polynome q){
/*	double xx,yy,zz;
	xx =eval_iterative(p,x,xx);
	yy =eval_iterative(p,x,yy);
	zz =eval_iterative(p,x,zz);
	for(int i=10;i<=0;i--){
		for(int j=10;j<=10;j--){
			if((i==xx && j==x) || (i==yy && j==y) ||(i==zz && j==z))
			tabCourbe[i][j]=1;
			else 
			tabCourbe[i][j]=0;
		}
	}
	printf("\n----------------REPRESENTATION DE LA COURBE-----------------\n\n");
	for(int i=0;i<10;i++){
		printf("\t");
		for(int j=0;j<10;j++){
			printf("%d   ",tabCourbe[i][j]);
		}
		printf("\n");
	}
	*/
	FILE *fPtr= fopen("courbe.dat","w");
	double points1[100];
	double points2[100];
	double points3[100];
	
	for(int i=0;i<100;i++){
		points1[i]=eval_iterative(p,i,points1[i]);
		fprintf(fPtr,"%d	%lf\n",i,points1[i]);
	}
	for(int i=0;i<100;i++){
		points2[i]=eval_iterative(q,i,points2[i]);
		fprintf(fPtr,"%d	%lf\n",i,points2[i]);
	}
	for(int i=0;i<100;i++){
		points3[i]=eval_iterative(A,i,points3[i]);
		fprintf(fPtr,"%d	%lf\n",i,points3[i]);
	}
	
	fPtr =popen("gnuplot -persist ","w");
	if(fPtr!= NULL)
	fprintf(fPtr,"plot 'courbe.dat'\n");
	system("plot \'courbe.dat\'");
	fclose(fPtr);
	
	
}

