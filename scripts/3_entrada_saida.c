//nesse script vamos falar dessa biblioteca que todo c�digo C contem, o stdio.h
#include <stdio.h>

int main()
{
    //A biblioteca stdio.h � a abreviacao de standard input-output
    //nela encontramos as operacoes de entrada e sa�da de dados, vc deve
    //ter reparado no printf dos scripts anteriores. pois bem vamos falar dele agr.
    //pq eu n comecei com isso ent�o?
    //pq a entrada e sa�da de dados, no C est� diretamente relacionada aos tipos de dados.
    //vamos come�ar com o printf, que por padr�o � o output, ou seja a sa�da de dados em C.
    //na estrutura do printf temos primeiro o corpo, na primeira parte colocamos
    //texto e tamb�m o tipo dos operadores que vamos 'printar' na tela, vamos come�ar com exemplo
    //b�sico.
    printf("Ol� mundo!\n");
    //o '\n' no fim do corpo de texto pula uma linha.
    //veja que todo corpo de texto entre as aspas conseguimos printar na tela, agr vamos para vari�veis
    //oq dificulta um pouco as varaiveis � q al�m de adicionar a variavel, temos que adicionar no corpo
    //de texto um identificador de onde a variavel est�, esse identificador varia de acordo com o tipo
    //no geral � representado pelo mesmo simbolo do resto '%'
    //para inteiros �: %d ou %i
    //para float �: %f
    //para char �: %c para printar e %s para receber
    //no exemplo abaixo temos:
    int a = 5;
    //vamos printar o 'a' ap�s o texto como estav�mos fazendo nos scripts anteriores.
    printf("Olhe o valor de a: %d \n",a);
    //note que o %d no texto indica exatamente onde o 'a' vai ser inserido, vamos colocar ele no meio
    printf("Olhe o valor de a no meio, %d, do texto ele vale 5 mesmo!\n",a);
    //para float
    float b = 6.6;
    printf("Valor de b: %f\n",b);
    //e se eu quiser mostrar com duas casas de precis�o na tela? adicionamos o .2f na notacao
    printf("Valor de b: %.2f \n",b);
    //e com 1? 1.f? Sim!
    printf("Valor de b: %.1f \n",b);
    //e se eu quiser printar dois n�meros?
    printf("valor de b: %.1f, valor de a: %d\n",b,a);
    //basta colocar a nota��o correta em seguida adicionar os n�meros ap�s o campo de texto.

    //Agora vmos para entradas de dados scanf, que segue a mesma l�gica do printf, sendo at� mais f�cil.
    printf("Digite um n�mero na tela: \n");
    //para usarmos scanf recebemos primeiro o tipo dentro de aspas "%d" por exemplo, depois o s�mbolo '&'
    //seguido da variavel.
    int x;
    //se vc n�o digitar o & o valor n�o ser� salvo.
    scanf("%d",&x);
    printf("O valor que vc digitou foi: %d \n",x);
    //e se for float?
    printf("Digite um n�mero na tela: \n");
    float y;
    scanf("%f",&y);
    printf("O valor que vc digitou foi: %.1f \n",y);
    //lembra do tipo char?
    //e se for char?
    printf("Digite uma letra na tela: \n");
    char z;
    scanf("%s",&z);
    printf("A letra que vc digitou foi: %c \n",z);
    return 0;
}
