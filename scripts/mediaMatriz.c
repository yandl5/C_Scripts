#include <stdio.h>
int main()
{
    float notas[10][3], medias[10][2], auxiliar,auxiliarB;
    int i, j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Digite a nota %d do aluno %d\n",j,i);
            scanf("%f",&notas[i][j]);
        }
        medias[i][0] = i;
        medias[i][1] = (notas[i][0]+notas[i][1]+notas[i][2])/3;
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(medias[i][1]<medias[j][1])
            {
                auxiliar = medias[i][1];
                medias[i][1] = medias[j][1];
                medias[j][1] = auxiliar;

                auxiliarB = medias[i][0];
                medias[i][0] = medias[j][0];
                medias[j][0] = auxiliarB;
            }
        }
    }
    for(i=0;i<10;i++)
    {
        printf("Aluno %.0f, ",medias[i][0]);
        printf("média: %f\n",medias[i][1]);
    }
    return 0;
}
