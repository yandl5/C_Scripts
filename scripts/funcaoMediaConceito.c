#include <stdio.h>

char conceito(float media);

int main()
{
    float media;
    char conceitoRecebido;
    scanf("%f",&media);
    conceitoRecebido = conceito(media);
    printf("Conceito: %c",conceitoRecebido);
}

char conceito(float media)
{
    if(media>=0 && media<=4.9)
    {
        return 'D';
    }
    else if(media>=5 && media<=6.9)
    {
        return 'C';
    }
    else if(media>=7 && media<=8.9)
    {
        return 'B';
    }
    else if(media>=9 && media<=10)
    {
        return 'A';
    }
    else
    {
        return NULL;
    }
}
