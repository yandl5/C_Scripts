#include <stdio.h>

int main()
{
    //� uma possibilidade ao if quando h� multiplos casos, para reduzir a complexidade de v�rios ifs
    //aninhados.
    //vamos definir uma vari�vel:
    int x = 10;
    switch (x)
    {
    case 5 :
        printf("O valor de X � 5");
    break;
    //o break interrompe imediatamente a execu��o do switch caso ache o valor correspondente
    case 7:
        printf("O valor de X � 7");
    break;
    case 10:
        printf("O valor de X � 10");
    break;
    //caso nada d� certo, cai no default
    default:
        printf("O valor de X � inv�lido");
    }
    //esse site explica bem direitinho:
    //http://linguagemc.com.br/o-comando-switch-case-em-c/#:~:text=%C3%89%20uma%20forma%20de%20reduzir,um%20determinado%20comando%20%C3%A9%20executado.
    return 0;
}
