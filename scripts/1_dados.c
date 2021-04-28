//Uma coisa que difere o C da linguagem q vc tava vendo
//� a tipagem forte, ou  seja, todas as vari�veis que vc declarar
//devem ter seu tipo declarado, nesse script vou mostrar como se
//declara uma vari�vel, e os diferentes e mais comuns tipos em C
#include <stdio.h>
//biblioteca para bool
#include<stdbool.h>

int main()
{
    //vamos come�ar:
    //Para declarar uma vari�vel voc� deve colocar o tipo dela
    //q � uma palavra reservada da linguagem, seguido do seu nome
    //no fim deve-se adicionar ";" para que seja definido fim do bloco.
    //exemplo:
    char a;
    //mas o que seria um tipo char?
    //char � o tipo b�sico do c que representa um �nico charactere, � representado
    //por um byte, vamos fazer uma atribui��o de valor com operador = e ver o resultado
    //n�o se preocupe com o printf irei explicar ele em outro script.
    a = 'N';
    printf("Variavel a vale: %c\n",a);
    //certo mas e se eu quiser representar algo que tenha mais de um byte, como
    //um n�mero por exemplo, a pergunta que devemos fazer �, o n�mero q vc quer
    //representar � inteiro? 0,55,44,-45,-95. Ou � fracion�rio? 2.5,1.6,0.5,-9.6.
    //para  n�meros inteiros usamos a palavra reservada int.
    int b;
    //vamos atribuir um valor a b.
    b = 55;
    //vamos ver o valor de b.
    printf("Variavel b vale: %d\n",b);
    //mas e se eu quiser usar n�meros fracion�rios?
    //para n�meros fracion�rios usamos float.
    float c;
    //atribuindo valor a c.
    c = 1.85;
    //vamos ver o valor de c.
    printf("Variavel c vale: %f\n",c);
    //uma outra representa��o bastante �til, � a verdadeiro ou falso,
    //representamos verdadeiro como 1 e falso como 0.
    //ent�o vc concorda que n h� necessidade de existir um tipo inteiro pra isso?
    //pq o tipo inteiro ocupa mais espa�o.
    //para verdadeiro ou falso usamos bool.
    //para usar bool adicionamos l� em cima a biblioteca: #include<stdbool.h>
    //pq bool n � um tipo nativo do C.
    bool e;
    //atribuindo valor um verdadeiro
    e = 1;
    //vamos observar e:
    printf("Variavel e vale: %d\n",e);
    //mas oq acontece se eu por exemplo declarar um n�mero inteiro num ponto flutuante?
    //com esse exemplo acho q vc vai entender o pq dessa tipagem forte no C.
    int f;
    //vamos adicionar um valor float para f.
    f = 2.56;
    //vamos ver o que acontece.
    printf("Variavel e vale: %d\n",f);
    //Como vc pode ver n salvamos o valor decimal de f, a perda de informa��es e at� erros
    //podem comprometer programas, por isso a import�ncia de tipos em C.
    return 0;
}
