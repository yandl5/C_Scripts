#include <stdio.h>
int main()
{
    int i,j;
    int k,l;
    int a,b,flag=0;
    int maxi=0, maxj=0;
    scanf("%d",&a);
    scanf("%d",&b);
    int m[a][b];
    int x[50][2];
    int cont=0;
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            for(k=i-1;k<=i+1;k++)
            {
                for(l=j-1;l<=j+1;l++)
                {
                    if(l>=0&&k>=0&&l<=a&&k<=b)
                    {
                        if(m[k][l]>m[i][j])
                        {
                            flag=1;
                        }
                    }
                }
            }
            if(flag==0)
            {
                x[cont][0]=i;
                x[cont][1]=j;
                cont=cont+1;
            }
            flag=0;
        }
    }
    for(i=0;i<cont;i++)
    {
        printf("%d ",x[i][0]);
        printf("%d",x[i][1]);
        printf("\n");
    }

    return 0;
}
