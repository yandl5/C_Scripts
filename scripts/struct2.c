#include <stdio.h>
#include <string.h>
struct Pessoas
{
    char nome[20];
    int idade;
    float altura;
};
int main()
{
    int i,contUmMeio=0, menor, maior;
    float mediaIdade=0, mediaAltura=0, mediaUmMeio=0;
    struct Pessoas pessoas[5],pessoasUmMeio[5];
    for(i=0;i<5;i++)
    {
        printf("Digite o nome:\n");
        scanf("%s",pessoas[i].nome);
        printf("Digite a idade:\n");
        scanf("%d",&pessoas[i].idade);
        printf("Digite a altura:\n");
        scanf("%f",&pessoas[i].altura);
        mediaIdade = mediaIdade + pessoas[i].idade;
        mediaAltura = mediaAltura + pessoas[i].altura;
    }
    mediaIdade = mediaIdade/5;
    mediaAltura = mediaAltura/5;
    printf("\n");
    for(i=0;i<5;i++)
    {
        if(pessoas[i].idade>mediaIdade)
        {
            printf("%s tem idade superior a media\n",pessoas[i].nome);
        }
    }
    printf("\n");

    for(i=0;i<5;i++)
    {
        if(pessoas[i].altura<1.5)
        {
            mediaUmMeio = mediaUmMeio + pessoas[i].idade;
            contUmMeio = contUmMeio + 1;
        }
    }
    mediaUmMeio = mediaUmMeio/contUmMeio;
    printf("A media da idade das pessoas com altura inferior a 1.5m e: %f\n\n",mediaUmMeio);

    menor = 0;
    maior = 0;
    for(i=0;i<5;i++)
    {
        if(pessoas[i].idade<pessoas[menor].idade)
        {
            menor = i;
        }
        if(pessoas[i].idade>pessoas[maior].idade)
        {
            maior = i;
        }
    }
        printf("A pessoa mais nova é: %s\n",pessoas[menor]);
        printf("A pessoa mais velha é: %s\n",pessoas[maior]);

    return 0;
}
