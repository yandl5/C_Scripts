#include <stdio.h>

int main()
{
    //é uma possibilidade ao if quando há multiplos casos, para reduzir a complexidade de vários ifs
    //aninhados.
    //vamos definir uma variável:
    int x = 10;
    switch (x)
    {
    case 5 :
        printf("O valor de X é 5");
    break;
    //o break interrompe imediatamente a execução do switch caso ache o valor correspondente
    case 7:
        printf("O valor de X é 7");
    break;
    case 10:
        printf("O valor de X é 10");
    break;
    //caso nada dê certo, cai no default
    default:
        printf("O valor de X é inválido");
    }
    //esse site explica bem direitinho:
    //http://linguagemc.com.br/o-comando-switch-case-em-c/#:~:text=%C3%89%20uma%20forma%20de%20reduzir,um%20determinado%20comando%20%C3%A9%20executado.
    return 0;
}
