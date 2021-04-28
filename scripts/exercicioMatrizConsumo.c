#include <stdio.h>
int main()
{
    int i,j,k;
    float matriz[20][12], mediaMes[12],mediaAno[20], maiorConsumoAno,maiorConsumoMes,media;
    for(i=0;i<20;i++)
    {
        for(j=0;j<12;j++)
        {
            printf("Informe o consumo do mês %d, no ano %d: \n",j,i);
            scanf("%f",&matriz[i][j]);
        }
    }
    printf("\n");
    /*a*/
    media = 0;
    for(j=0;j<12;j++)
    {
        for(i=0;i<20;i++)
        {
            media = media + matriz[i][j];
        }
        mediaMes[j] = media/20;
        media = 0;
    }
    for(i=0;i<12;i++)
    {
        printf("A media do mês de %d é: %.1f\n",i,mediaMes[i]);
    }
    printf("\n");
    /*b*/
    k=0;
    for(i=0;i<12;i++)
    {
        if(mediaMes[i]>mediaMes[k])
        {
            k = i;
        }
    }
    printf("O mês de maior consumo é: %d\n",k);
    printf("\n");
    /*c*/
    media = 0;
    for(i=0;i<20;i++)
    {
        for(j=0;j<12;j++)
        {
            media = media + matriz[i][j];
        }
        mediaAno[i] = media/12;
        media = 0;
    }
    for(i=0;i<20;i++)
    {
        printf("Media no ano %d: %.1f\n",i,mediaAno[i]);
    }
    printf("\n");
    /*d*/
    printf("O mês de maior consumo é: %d\n",k);
    k=0;
    for(i=0;i<20;i++)
    {
        if(mediaAno[i]>mediaAno[k])
        {
            k = i;
        }
    }
    printf("O Ano de maior consumo é: %d\n",k);
    return 0;
}
