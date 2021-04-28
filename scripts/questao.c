#include <stdio.h>
#include "math.h"
int main()
{
    int v[20], i, j, maiorIndice;
    int maiorDiferenca, auxiliar;
    for(i=0;i<20;i++)
    {
        printf("Digite um valor para o vetor:\n");
        scanf("%d",&v[i]);
    }
    for(i=0;i<20;i++)
    {
        printf("%d\n",v[i]);
    }
    maiorIndice = 0;
    maiorDiferenca = sqrt(pow((v[0] - v[1]),2));
    printf("%d\n",maiorDiferenca);
    for(i=1;i<19;i++)
    {
        auxiliar = sqrt(pow((v[i] - v[i+1]),2));
        if(auxiliar>maiorDiferenca)
        {
            maiorDiferenca = auxiliar;
            maiorIndice = i;
        }
    }
    j = maiorIndice+1;
    printf("Os elementos estão na posição: %d e %d\n",maiorIndice, j);
    printf("A diferença entre eles é: %d\n",maiorDiferenca);
    return 0;
}
