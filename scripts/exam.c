#include <stdio.h>
void jogosXTime(int v[],int *resultado,int tamanho);
int main()
{
    int i,v[13],resultado[3];
    for(i=0;i<13;i++)
    {
        printf("Digite o resultado do jogo,1 time 1 ganhou,2 time 2 ganhou e 3 para empate\n");
        scanf("%d",&v[i]);
    }
    jogosXTime(v,&resultado,13);
    printf("O time 1 ganhou:%d\n",resultado[0]);
    printf("O time 2 ganhou:%d\n",resultado[1]);
    printf("Empates:%d\n",resultado[2]);
    return 0;
}
void jogosXTime(int v[],int *resultado,int tamanho)
{
    int i;
    resultado[0]=0;
    resultado[1]=0;
    resultado[2]=0;
    for(i=0;i<tamanho;i++)
    {
        if(v[i]==1)
        {
            resultado[0]=resultado[0]+1;
        }
        else if(v[i]==2)
        {
            resultado[1]=resultado[1]+1;
        }
        else if(v[i]==3)
        {
            resultado[2]=resultado[2]+1;
        }
    }
}
