#include <stdio.h>
int main()
{
    int matriz[30][12],i,j,k,trimestre[30][4],contador=0,quantidade=0,maior;
    for(i=0;i<30;i++)
    {
        for(j=0;j<12;j++)
        {
            printf("Informe quantidade do produto %d, vendido no mês %d:\n",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
    k=0;
    for(i=0;i<30;i++)
    {
        for(j=0;j<12;j++)
        {
            quantidade=quantidade+matriz[i][j];
            if(contador==2)
            {
                trimestre[i][k]=quantidade;
                quantidade=0;
                k=k+1;
                contador=0;
            }
            else
            {
                contador++;
            }
        }
        k=0;
        quantidade=0;
        contador=0;
    }
    printf("\n");
    for(i=0;i<30;i++)
    {
        maior=trimestre[i][0];
        k=0;
        for(j=0;j<4;j++)
        {
            if(trimestre[i][j]>maior)
            {
                maior = trimestre[i][j];
                k = j;
            }
        }
        printf("Quantidade do produto %d, no trimestre %d: %d\n",i,k,maior);
    }
    return 0;
}
