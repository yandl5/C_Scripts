#include <stdio.h>

int main()
{
    int vetorUm[5],vetorDois[5],vetorFinal[5];
    int i, j, k, contador=0;
    int flag=1;
    for(i=0;i<5;i++)
    {
        printf("Insira valor no vetor um:\n");
        scanf("%d",&vetorUm[i]);
        printf("Insira valor no vetor dois:\n");
        scanf("%d",&vetorDois[i]);
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(vetorUm[i]==vetorDois[j])
            {
                if(contador!=0)
                {
                    for(k=0;k<contador;k++)
                    {
                        if(vetorUm[i]==vetorFinal[k])
                        {
                            flag=0;
                        }
                    }
                    if(flag!=0)
                    {
                        vetorFinal[contador] = vetorUm[i];
                        contador = contador+1;
                    }
                    else
                    {
                        flag=1;
                    }
                }
                else
                {
                    vetorFinal[contador] = vetorUm[i];
                    contador = contador+1;
                }
            }
        }
    }
    for(k=0;k<contador;k++)
    {
        printf("%d ",vetorFinal[k]);
    }
    return 0;
}
