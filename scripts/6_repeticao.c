#include <stdio.h>

int main()
{
    //Por fim temos laços de repetição.
    // vamos começar com o for, o laço for necessita de um início bem delimitado e de um fim também.
    //como parâmetros temos o inicio do iterador, condição parado, e o incremento para cada repetição.
    //exemplo
    int i;
    //o ++ significa i = i+1, pode colocar i = i+1 não tem problema
    for(i=0;i<10;i++)
    {
        printf("Valor de i é: %d\n",i);
    }
    //e quando sabemos a condição de parada e não sabemos por exemplo o inicio,
    //vamos supor que o usuário digite 5 numa variavel.
    int z = 5;
    //vc tem uma função que quer calcular uma divida, por exemplo, esse 5 é quantidade de meses
    //no final desses z meses quanto irá pagar?
    //para isso podemos usar while
    int divida_mensal = 50;
    int divida_total = 0;
    //veja enquanto Z, quantidade de meses for maior que zero:
    //vamos adicionar esse contador para contar os meses
    int j = 1;
    while(z>0)
    {
        divida_total = divida_total + divida_mensal;
        printf("No mês %d a divida total é de: %d\n",j,divida_total);
        //No while VC TEM QUE DECREMENTAR OU INCREMENTAR NA MÃO
        //caso n faça isso seu programa vai loopar
        j++;
        z--;
    }
    // existe uma variação do while, q é a do while.
    //a diferença do while normal pra esse, é que no while vc só roda ele se atender a condição.
    //já no do while ele vai rodar pelo menos uma vez até checar a condição.
    int n=-50;
    do
    {
        printf("Valor de N é:%d\n",n);
        n--;
    }while(n>0);
    // mesmo não atendendo os requisitos ele rodou uma vez o laço.

    return 0;
}
