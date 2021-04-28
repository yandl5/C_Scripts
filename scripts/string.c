#include <stdio.h>
#include <string.h>
int main()
{
    char ms[10][35],vetor[350],aux[35];
    int i,j,comp;
    for(i=0;i<10;i++)
    {
        printf("Digite a string %d: \n",i);
        scanf("%s",ms[i]);
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(strcmp(ms[i],ms[j])<0)
            {
                strcpy(aux,ms[i]);
                strcpy(ms[i],ms[j]);
                strcpy(ms[j],aux);
            }
        }
    }
    strcpy(vetor,ms[0]);
    for(i=1;i<10;i++)
    {
        strcat(vetor," ");
        strcat(vetor,ms[i]);
    }
    printf("%s",vetor);
    return 0;
}
