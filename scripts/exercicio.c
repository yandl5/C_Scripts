#include <stdio.h>

int main()
{
    int sexo;
    float total,porcentagemHomens, porcentagemMulheres, homens, mulheres;
    mulheres = 0;
    homens = 0;
    sexo = 3;
    total = 0, porcentagemHomens=0,porcentagemMulheres=0;
    while(sexo!=0)
    {
        printf("Digite '1' para homem,'2' para mulher ou '0' para encerrar:\n");
        scanf("%d",&sexo);
        if(sexo==1)
        {
            homens = homens +1;
        }
        else if(sexo==2)
        {
            mulheres = mulheres +1;
        }
        else if(sexo==0)
        {
            printf("Contagem encerrada...\n");
        }
        else
        {
            printf("Valor informado inválido, repita o procedimento.\n");
        }
    }
    total = homens + mulheres;
    porcentagemHomens = homens/total *100;
    porcentagemMulheres = mulheres/total *100;
    printf("A quantidade de homens é: %0.f\n",homens);
    printf("A quantidade de mulheres é: %0.f\n",mulheres);
    printf("A porcentagem de homens é: %.2f\n",porcentagemHomens);
    printf("A porcentagem de homens é: %.2f\n",porcentagemMulheres);

    return 0;
}

