#include <stdio.h>
#include <math.h>//biblioteca de opera��es matem�ticas
int main()
{
    //Bem nesse t�pico vamos abordar as operacoes no C.
    //vamos come�ar declarando 7 variaveis para brincarmos
    int a = 50;
    int b = 2;
    float c = 2.5;
    float d = 3.5;
    int e;
    float f;
    int g = 3;
    //Vamos come�ar com as operacoes basicas soma, subtracao, divisao e multiplicacao
    //n h� novidades em relacao as outras linguagens.
    //soma:
    e = a + b;
    f = c + d;
    printf("Soma A + B vale: %d\n",e);
    printf("Soma C + D vale: %f\n",f);
    //subtra��o:
    e = a - b;
    f = d - c;
    printf("Subtra��o A - B e vale: %d\n",e);
    printf("Subtra��o D - C vale: %f\n",f);
    //multiplicacao:
    e = a * b;
    f = c * d;
    printf("multiplicacao A * B e vale: %d\n",e);
    printf("multiplicacao C * D vale: %f\n",f);
    //divisao:
    e = a / b;
    f = c / d;
    printf("divisao A * B e vale: %d\n",e);
    printf("divisao C * D vale: %f\n",f);
    //para valores inteiros temos o operador resto '%'
    e = a % g;
    printf("resto A/G vale: %d\n",e);
    //e se eu quiser usar raiz quadrada ou potenciacao? Posso?
    //pode mas pra isso vai ter q incluir a biblioteca: #include <math.h>
    //nesse site podemos ver algumas outras fun��es, como
    //log, seno, cosseno, tangente, arredondamento para baixo ou cima.
    //vamos a um exemplo de potencia��o e raiz quadrada
    int z = 25;
    //raiz quadrada de z:
    z = sqrt(z);
    printf("raiz quadrada de Z vale: %d\n",z);
    //sabendo que Z vale 5 agr, vamos voltar ele com potenciacao
    z = pow(z,2);
    //note que o primeiro � a base(z) e o segundo � o expoente(2)
    printf("5 ao quadrado vale: %d\n",z);
    return 0;

}
