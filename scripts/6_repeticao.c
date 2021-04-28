#include <stdio.h>

int main()
{
    //Por fim temos la�os de repeti��o.
    // vamos come�ar com o for, o la�o for necessita de um in�cio bem delimitado e de um fim tamb�m.
    //como par�metros temos o inicio do iterador, condi��o parado, e o incremento para cada repeti��o.
    //exemplo
    int i;
    //o ++ significa i = i+1, pode colocar i = i+1 n�o tem problema
    for(i=0;i<10;i++)
    {
        printf("Valor de i �: %d\n",i);
    }
    //e quando sabemos a condi��o de parada e n�o sabemos por exemplo o inicio,
    //vamos supor que o usu�rio digite 5 numa variavel.
    int z = 5;
    //vc tem uma fun��o que quer calcular uma divida, por exemplo, esse 5 � quantidade de meses
    //no final desses z meses quanto ir� pagar?
    //para isso podemos usar while
    int divida_mensal = 50;
    int divida_total = 0;
    //veja enquanto Z, quantidade de meses for maior que zero:
    //vamos adicionar esse contador para contar os meses
    int j = 1;
    while(z>0)
    {
        divida_total = divida_total + divida_mensal;
        printf("No m�s %d a divida total � de: %d\n",j,divida_total);
        //No while VC TEM QUE DECREMENTAR OU INCREMENTAR NA M�O
        //caso n fa�a isso seu programa vai loopar
        j++;
        z--;
    }
    // existe uma varia��o do while, q � a do while.
    //a diferen�a do while normal pra esse, � que no while vc s� roda ele se atender a condi��o.
    //j� no do while ele vai rodar pelo menos uma vez at� checar a condi��o.
    int n=-50;
    do
    {
        printf("Valor de N �:%d\n",n);
        n--;
    }while(n>0);
    // mesmo n�o atendendo os requisitos ele rodou uma vez o la�o.

    return 0;
}
