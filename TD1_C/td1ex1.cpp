#include <stdio.h>
int main()
{
    int A;
    printf("Veuillez Entrez une annee: ");
    scanf("%d",&A);
    if(A % 4 == 0)
    {
        if( A % 100 == 0)
        {
            if ( A % 400 == 0)
                printf("%d pas une annee bissextile", A);
            else
                printf("%d est une annee bissextile", A);
        }
        else
            printf("%d est une annee bissextile", A );
    }
    else
        printf("%d pas une annee bissextile", A);
    return 0;
}
