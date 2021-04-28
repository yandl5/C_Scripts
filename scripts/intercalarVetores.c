#include <stdio.h>

void lerA(int tamanho, int *a);
void lerB(int tamanho,int *b);
void gerarC(int a[], int b[], int *c, int tamanho);

int main()
{
    int a[5], b[5], c[10],i;
    lerA(5,&a);
    lerB(5,&b);
    gerarC(a,b,&c,10);
    for(i=0;i<10;i++)
    {
        printf("Valor %d de C: %d\n",i,c[i]);
    }
    return 0;
}
void lerA(int tamanho, int *a)
{
    int i;
    for(i=0;i<tamanho;i++)
    {
        printf("Digite o %d elemento de A:\n",i);
        scanf("%d",&a[i]);
    }
}
void lerB(int tamanho, int *b)
{
    int i;
    for(i=0;i<tamanho;i++)
    {
        printf("Digite o %d elemento de B:\n",i);
        scanf("%d",&b[i]);
    }
}
void gerarC(int a[],int b[], int *c,int tamanho)
{
    int i,contadorA=0,contadorB=0;
    for(i=0;i<tamanho;i++)
    {
        if(i%2==0)
        {
            c[i]=a[contadorA];
            contadorA=contadorA+1;
        }
        else
        {
            c[i]=b[contadorB];
            contadorB=contadorB+1;
        }
    }
}
