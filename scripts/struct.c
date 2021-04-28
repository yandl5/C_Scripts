
#include <stdio.h>
#include <string.h>

struct Livros{
    char titulo[30];
    int anoedicao, numpaginas;
    float preco;
};

int main()
{
    struct Livros livro[5],maiores[5],menores[5];
    float maiorpreco, menorpreco, preco;
    int i,quantidadeMaiores,quantidadeMenores;

    for(i=0;i<5;i++)
    {
        printf("\nDigite o t�tulo do %d livro:\n", i+1);
        scanf("%s", livro[i].titulo);

        printf("Digite o ano de edi��o do livro:\n");
        scanf("%d", &livro[i].anoedicao);

        printf("Digite o n�mero de p�ginas do livro:\n");
        scanf("%d", &livro[i].numpaginas);

        printf("Digite o pre�o do livro:\n");
        scanf("%f", &livro[i].preco);
    }
    printf("\n");
    menorpreco = livro[0].preco;
    for(i=0;i<5;i++)
    {
        if(livro[i].preco<menorpreco)
        {
            menorpreco = livro[i].preco;
        }
    }
    quantidadeMenores=0;
    for(i=0;i<5;i++)
    {
        if(livro[i].preco==menorpreco)
        {
            strcpy(menores[quantidadeMenores].titulo,livro[i].titulo);
            menores[quantidadeMenores].anoedicao=livro[i].anoedicao;
            menores[quantidadeMenores].numpaginas=livro[i].numpaginas;
            menores[quantidadeMenores].preco=livro[i].preco;
            quantidadeMenores = quantidadeMenores + 1;
        }
    }
    printf("\n");
    maiorpreco = livro[0].preco;
    for(i=0;i<5;i++)
    {
        if(livro[i].preco>maiorpreco)
        {
            maiorpreco = livro[i].preco;
        }
    }
    quantidadeMaiores=0;
    for(i=0;i<5;i++)
    {
        if(livro[i].preco==maiorpreco)
        {
            strcpy(maiores[quantidadeMaiores].titulo,livro[i].titulo);
            maiores[quantidadeMaiores].anoedicao=livro[i].anoedicao;
            maiores[quantidadeMaiores].numpaginas=livro[i].numpaginas;
            maiores[quantidadeMaiores].preco=livro[i].preco;
            quantidadeMaiores = quantidadeMaiores + 1;
        }
    }
    printf("\n");
    printf("\nOs livros com maior pre�o s�o:\n");
    for(i=0;i<quantidadeMaiores;i++)
    {
        printf("T�tulo:\n%s", maiores[i].titulo);
        printf("\nAno de edi��o:\n%d", maiores[i].anoedicao);
        printf("\nN�mero de p�ginas:\n%d", maiores[i].numpaginas);
        printf("\nPre�o:\n%.2f\n", maiores[i].preco);
    }
    printf("\n");
    printf("\nOs livros com menor pre�o s�o:\n");
    for(i=0;i<quantidadeMenores;i++)
    {
        printf("T�tulo:\n%s", menores[i].titulo);
        printf("\nAno de edi��o:\n%d", menores[i].anoedicao);
        printf("\nN�mero de p�ginas:\n%d", menores[i].numpaginas);
        printf("\nPre�o:\n%.2f\n", menores[i].preco);
    }

    return 0;
}
