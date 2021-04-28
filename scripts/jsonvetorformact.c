#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *fromJsonString_int(char in[],int size);
double *fromJsonString_double(char in[],int size);
int sizeString(char in[]);
_Bool checktype(char in[]);
int main()
{
    char in[100];
    //in = (char*)malloc(sizeof(char)*100);
    int *json;
    int i;
    double *jsonF;
    scanf("%s",in);
    printf("Xablau feroz\n");
    int size;
    size=sizeString(in);
    if(checktype(in))
    {
        printf("Xablau feroz2\n");
        jsonF = fromJsonString_double(in,size);
        for(i=0;i<size;i++)
        {
            printf("%lf ",jsonF[i]);
        }
    }
    else
    {
        printf("Xablau feroz3\n");
        json = fromJsonString_int(in,size);
        printf("Xablau feroz4\n");
        for(i=0;i<size;i++)
        {
            printf("%d ",json[i]);
        }
    }
    printf("\n");
    return 0;
}
_Bool checktype(char in[])
{
    int check=0;
    int i=0;
    while(in[i]!='\0')
    {
        if(in[i]=='.')
        {
            check=1;
        }
        i++;
    }
    if(check==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int *fromJsonString_int(char in[],int size)
{
    int *pointer;
    pointer = (int*)malloc(sizeof(int)*size);
    int sizeIn;
    int i=1;
    sizeIn=strlen(in);
    char *token=strtok(in,",");
    pointer[0]=atoi(token);
    while(i<size) {
        token = strtok(NULL, ",");
        pointer[i]=atoi(token);
        i++;
    }
    return pointer;
}
double *fromJsonString_double(char in[],int size)
{
    double *pointerF;
    pointerF = (double*)malloc(sizeof(double)*size);
    int sizeIn;
    int i=1;
    sizeIn=strlen(in);
    char *token=strtok(in,",");
    pointerF[0]=atof(token);
    while(i<size) {
        token = strtok(NULL, ",");
        pointerF[i]=strtod(token,NULL);
        i++;
    }
    return pointerF;
}
int sizeString(char in[])
{
    int cont=0;
    int i=0;
    while(in[i]!='\0')
    {
        if(in[i]==',')
        {
            cont=cont+1;
        }
        i++;
    }
    return cont+1;
}

