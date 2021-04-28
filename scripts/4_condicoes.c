#include <stdio.h>

int main()
{
    // vamos entrar em condições nesse script, acho mais prático começar pelo
    // if, que vc deve conhecer como 'se'.
    //um bloco de condicao no C começa com a palavra:
    //if(condição){bloco de isntruções}, vamos para um exemplo.
    int x = 8;
    int y = 8;
    if(x==y)
    {
        printf("X é igual a Y.\n");
    }
    // mas oque é esse '=='?, o == é um operador lógico, no C eles são:
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
        printf("X é diferente de Z.\n");
    }
    //agora vamos introduzir o else que significa se não, deve ser utilizado depois de um bloco if ou else if
    if(x==z)
    {
        printf("X é igual a Z.\n");
    }
    else
    {
        printf("X é diferente de Z.\n");
    }
    //o else não tem condição, já que é uma negativa ao que já foi proposto

    //podemos aninhar blocos de else if entre o if e o else, para dar ideia de continuidade.
    if(x==z)
    {
        printf("X é igual a Z.\n");
    }
    else if(y==z)
    {
        printf("Y é igual a Z.\n");
        //note que não entrou aqui, indo direto pro else.
    }
    else
    {
        printf("X é diferente de Z.\n");
    }
    //mas e se quisermos adicionar várias condições?
    //podemos utilizar os operadores:
    // && e
    // || ou
    //exemplo:
    int h = 15;
    int l = 18;
    int k = l + h;
    //para não confundir aconselho usar parenteses entre as condicoes
    if((h<l)&&(k>l))
    {
        printf("H é menor que L, e K é maior que L.\n");
    }
    //exemplo ou
    //note que no exemplo abaixo só uma condição é verdadeira, mas já basta para o ou.
    //caso as duas fosse falsas, não entraria.
    if((h<l)||(k<l))
    {
        printf("H é menor que L, ou K é maior que L.\n");
    }
    return 0;
}
