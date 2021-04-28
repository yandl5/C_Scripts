#include <stdio.h>

int main()
{
    // vamos entrar em condi��es nesse script, acho mais pr�tico come�ar pelo
    // if, que vc deve conhecer como 'se'.
    //um bloco de condicao no C come�a com a palavra:
    //if(condi��o){bloco de isntru��es}, vamos para um exemplo.
    int x = 8;
    int y = 8;
    if(x==y)
    {
        printf("X � igual a Y.\n");
    }
    // mas oque � esse '=='?, o == � um operador l�gico, no C eles s�o:
    // == igual a
    // != diferente de
    // < menor que
    // > maior que
    // <= menor igual que
    // >= maior igual que

    //vamos para outro exemplo
    int z = 9;
    if(x!=z)
    {
        printf("X � diferente de Z.\n");
    }
    //agora vamos introduzir o else que significa se n�o, deve ser utilizado depois de um bloco if ou else if
    if(x==z)
    {
        printf("X � igual a Z.\n");
    }
    else
    {
        printf("X � diferente de Z.\n");
    }
    //o else n�o tem condi��o, j� que � uma negativa ao que j� foi proposto

    //podemos aninhar blocos de else if entre o if e o else, para dar ideia de continuidade.
    if(x==z)
    {
        printf("X � igual a Z.\n");
    }
    else if(y==z)
    {
        printf("Y � igual a Z.\n");
        //note que n�o entrou aqui, indo direto pro else.
    }
    else
    {
        printf("X � diferente de Z.\n");
    }
    //mas e se quisermos adicionar v�rias condi��es?
    //podemos utilizar os operadores:
    // && e
    // || ou
    //exemplo:
    int h = 15;
    int l = 18;
    int k = l + h;
    //para n�o confundir aconselho usar parenteses entre as condicoes
    if((h<l)&&(k>l))
    {
        printf("H � menor que L, e K � maior que L.\n");
    }
    //exemplo ou
    //note que no exemplo abaixo s� uma condi��o � verdadeira, mas j� basta para o ou.
    //caso as duas fosse falsas, n�o entraria.
    if((h<l)||(k<l))
    {
        printf("H � menor que L, ou K � maior que L.\n");
    }
    return 0;
}
