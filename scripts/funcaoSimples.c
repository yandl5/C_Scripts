#include<stdio.h>

int mostramaiorvalor(int vetor[], int tamanho);

int main()
{
    int maiorMain,v[5],i;
    maiorMain = mostramaiorvalor(v,5);
    printf("O maior valor do vetor é: %d",maiorMain);
    return 0;
}
int mostramaiorvalor(int vetor[], int tamanho)
{
    int i, maior;

    printf("Digite os valores do vetor:\n");

    for(i=0;i<tamanho;i++){
        scanf("%d", &vetor[i]);
    }
    maior = vetor[0];
    for(i=0;i<tamanho;i++)
    {
        if(vetor[i]>maior)
        {
            maior = vetor[i];
        }
    }
    return maior;
}
