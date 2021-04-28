#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdlib.h>

int main()
{
    FILE *note;
    int *content;
    int n,m,i,j,valor,cont=0;
    content = (int*)malloc(2056);
    printf("Digite a quantidade nxm matriz\n",&n,&m);
    scanf("%d%d",&n,&m);
    srand(time(NULL));
    note = fopen("number.txt", "w");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            valor = rand()%15;
            content[cont] = valor;
            fprintf(note,"%d ",valor);
            printf("%d ",valor);
            cont++;
        }
        fprintf(note,"\n",valor);
        printf("\n");
    }
    free(content);
    fclose(note);

}
