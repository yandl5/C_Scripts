#ifdef _WIN32
    #include <Windows.h>
    #include <conio.h>
    HANDLE _hConsole;
    int _termOrigColor;
#else
    #define _POSIX_C_SOURCE 1
    #define _POSIX_SOURCE 1
    #define _XOPEN_SOURCE 700
    #include <termios.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void menuInit();
int getkey();
int showMenu(char options[][50], int tam);

struct Cardapio
{
    char nome[50];
    char preco[50];
    char calorias[50];
};

void view(struct Cardapio cardapio[],int tamanho);
int adicionarPrato(struct Cardapio cardapio[],int tamanho, int max);
int removerPrato(struct Cardapio cardapio[],int tamanho);
int updateCardapio(struct Cardapio cardapio[]);
void editFile(struct Cardapio cardapio[],int tamanho);
void pratoNome(struct Cardapio cardapio[],int tamanho);
void faixaCalorias(struct Cardapio cardapio[],int tamanho);
void ordemAlfabetica(struct Cardapio cardapio[],int tamanho);
void ordemPreco(struct Cardapio cardapio[],int tamanho);

int main() {
    char itensMenu[10][50] = {"MENU", "Visualizar Cardapio", "Adicionar Prato", "Remover Prato", "Buscar prato por nome", "Busca faixa calorias", "Cardápio Ordenado", "Ordem de preco", "Sair"};
    char itensNovo[2][50] = {"CARDAPIO", "Sair"};
    char itensSN[3][50] = {"Deseja salvar as alteracoes no arquivo cardapio?","Sim","Nao"};
    char sn[50];
    struct  Cardapio cardapio[50];
    int tam;
    tam=0;
    tam = updateCardapio(cardapio);

    menuInit();
    while (1) {
    switch(showMenu(itensMenu, 9)) {
        case 1:
            printf("Visualizar Cardapio:\n");
            view(cardapio,tam);
            break;
        case 2:
            printf("Adicionar Prato:\n");
            tam = adicionarPrato(cardapio,tam,50);
            break;
        case 3:
            printf("Remover Prato:\n");
            tam = removerPrato(cardapio,tam);
            break;
        case 4:
            printf("%s ...\n", itensMenu[5]);
            pratoNome(cardapio,tam);
            break;
        case 5:
            printf("%s ...\n", itensMenu[6]);
            faixaCalorias(cardapio,tam);
            break;
        case 6:
            printf("%s ...\n", itensMenu[7]);
            ordemAlfabetica(cardapio,tam);
            break;
        case 7:
            printf("%s ...\n", itensMenu[8]);
            ordemPreco(cardapio,tam);
            break;
        case 8:
            printf("Saindo...\n");
            printf("Deseja salvar as alteracoes(S/N)?");
            scanf("%s",sn);
            if(strcmp(sn,"S")==0 || strcmp(sn,"s")==0)
            {
                editFile(cardapio,tam);
            }
            exit(0);
            break;
    }
    printf("Pressione qualquer tecla para continuar ...\n");
    getkey();
    }
    return 0;
}

void view(struct Cardapio cardapio[],int tamanho)
{
    int i;
    for(i=0;i<tamanho;i++)
    {
        printf("===============================\n");
        printf("%s ",cardapio[i].nome);
        printf("R$:%s ",cardapio[i].preco);
        printf("cal: %s",cardapio[i].calorias);  // calorias ja vem com um \n do arquivo
        if(i==(tamanho-1))
            printf("==============================\n");
    }
    if(tamanho==0)
    {
        printf("====================\n");
        printf("Cardapio Vazio\n");
        printf("====================\n");
    }
}
int adicionarPrato(struct Cardapio cardapio[],int tamanho, int max)
{
    if(tamanho+1<max)
    {
        printf("Digite o nome do prato:\n");
        scanf("%s",cardapio[tamanho].nome);
        printf("Digite o preco do prato:\n");
        scanf("%s",cardapio[tamanho].preco);
        printf("Digite a quantidade de calorias do prato:\n");
        scanf("%s",cardapio[tamanho].calorias);
        strcat(cardapio[tamanho].calorias,"\n");
        return tamanho+1;
    }
    return tamanho;
}
int removerPrato(struct Cardapio cardapio[],int tamanho)
{
    char prato[50];
    int i, posicao=-2;
    printf("Digite o nome do prato que deseja remover do cardapio:\n");
    scanf("%s",prato);
    for(i=0;i<tamanho;i++)
    {
        if(strcmp(prato,cardapio[i].nome)==0)
        {
            posicao=i;
        }
    }
    if(posicao==-2)
    {
        printf("Nome nao encontrado\n");
        return tamanho;
    }
    else if(posicao==tamanho-1)
    {
        return tamanho-1;
    }
    else
    {
        for(i=posicao;i<tamanho-1;i++)
        {
            strcpy(cardapio[i].nome,cardapio[i+1].nome);
            strcpy(cardapio[i].preco,cardapio[i+1].preco);
            strcpy(cardapio[i].calorias,cardapio[i+1].calorias);
        }
        return tamanho-1;
    }
}
void pratoNome(struct Cardapio cardapio[],int tamanho)
{
    int i,posicao=-1;
    char prato[50];
    printf("Digite o nome do prato: \n");
    scanf("%s",prato);
    for(i=0;i<tamanho;i++)
    {
        if(strcmp(prato,cardapio[i].nome)==0)
        {
            posicao = i;
        }
    }
    if(posicao!=-1)
    {
        printf("Nome do prato: %s\n",cardapio[posicao].nome);
        printf("Preco do prato: %s\n",cardapio[posicao].preco);
        printf("Quantidade de calorias: %s\n",cardapio[posicao].calorias);
    }
    else
    {
        printf("Prato nao encontrado. \n");
    }
}
void faixaCalorias(struct Cardapio cardapio[],int tamanho)
{
    int limiteInferior, limiteSuperior;
    int i;
    printf("Insira o limite inferior:\n");
    scanf("%d",&limiteInferior);
    printf("Insira o limite superior:\n");
    scanf("%d",&limiteSuperior);
    for(i=0;i<tamanho;i++)
    {
        if(atoi(cardapio[i].calorias)>limiteInferior)
        {
            if(atoi(cardapio[i].calorias)<limiteSuperior)
            {
                printf("Nome do prato: %s\n",cardapio[i].nome);
                printf("Preco do prato: %s\n",cardapio[i].preco);
                printf("Quantidade de calorias: %s\n",cardapio[i].calorias);
            }
        }
    }
}
void ordemAlfabetica(struct Cardapio cardapio[],int tamanho)
{
    int i,j, posicoes[tamanho];
    char auxNome[50], auxPreco[50],auxCalorias[50];
    struct Cardapio copia[50];
    for(i=0;i<tamanho;i++)
    {
        strcpy(copia[i].nome,cardapio[i].nome);
        strcpy(copia[i].preco,cardapio[i].preco);
        strcpy(copia[i].calorias,cardapio[i].calorias);
    }
    for(i=0;i<tamanho;i++)
    {
        for(j=0;j<tamanho;j++)
        {
            if(strcmp(copia[j].nome,copia[i].nome)>0)
            {
                strcpy(auxNome,copia[j].nome);
                strcpy(copia[j].nome,copia[i].nome);
                strcpy(copia[i].nome,auxNome);

                strcpy(auxPreco,copia[j].preco);
                strcpy(copia[j].preco,copia[i].preco);
                strcpy(copia[i].preco,auxPreco);

                strcpy(auxCalorias,copia[j].calorias);
                strcpy(copia[j].calorias,copia[i].calorias);
                strcpy(copia[i].calorias,auxCalorias);
            }
        }
    }
    for(i=0;i<tamanho;i++)
    {
        printf("Nome do prato: %s\n",copia[i].nome);
        printf("Preco do prato: %s\n",copia[i].preco);
        printf("Quantidade de calorias: %s\n",copia[i].calorias);
    }
}
void ordemPreco(struct Cardapio cardapio[],int tamanho)
{
    int i,j, posicoes[tamanho];
    char auxNome[50], auxPreco[50],auxCalorias[50];
    struct Cardapio copia[50];
    for(i=0;i<tamanho;i++)
    {
        strcpy(copia[i].nome,cardapio[i].nome);
        strcpy(copia[i].preco,cardapio[i].preco);
        strcpy(copia[i].calorias,cardapio[i].calorias);
    }
    for(i=0;i<tamanho;i++)
    {
        for(j=0;j<tamanho;j++)
        {
            if(atof(copia[j].preco)>atof(copia[i].preco))
            {
                strcpy(auxNome,copia[j].nome);
                strcpy(copia[j].nome,copia[i].nome);
                strcpy(copia[i].nome,auxNome);

                strcpy(auxPreco,copia[j].preco);
                strcpy(copia[j].preco,copia[i].preco);
                strcpy(copia[i].preco,auxPreco);

                strcpy(auxCalorias,copia[j].calorias);
                strcpy(copia[j].calorias,copia[i].calorias);
                strcpy(copia[i].calorias,auxCalorias);
            }
        }
    }
    for(i=0;i<tamanho;i++)
    {
        printf("Nome do prato: %s\n",copia[i].nome);
        printf("Preco do prato: %s\n",copia[i].preco);
        printf("Quantidade de calorias: %s\n",copia[i].calorias);
    }
}
int updateCardapio(struct Cardapio cardapio[])
{
    char linha[200];
    FILE *cardapioFile;
    char *token = NULL;
    int tamanho=0,i=0;

	cardapioFile = fopen("cardapio.txt", "r");
	if (cardapioFile == NULL)
    {
        return 0;
    }
    while(fgets(linha, sizeof linha, cardapioFile) != NULL)
    {
        //printf ("linha = %s\n", linha);
        token = strtok(linha," ");
        // lendo nome
        if (token != NULL)
            strcpy(cardapio[tamanho].nome,token);
        else
            break;
        // lendo preco
        token = strtok(NULL, " ");
        if (token != NULL)
            strcpy(cardapio[tamanho].preco,token);
        else
            break;
        //lendo calorias
        token = strtok(NULL, " ");
        if (token != NULL)
            strcpy(cardapio[tamanho].calorias,token);
        else
            break;
        tamanho=tamanho+1;
    }
    fclose(cardapioFile);
    return tamanho;
}
void editFile(struct Cardapio cardapio[],int tamanho)
{
    FILE *cardapioFile;
    int i;
    cardapioFile = fopen("cardapio.txt", "w");
    for(i=0;i<tamanho;i++)
    {
        fprintf(cardapioFile,"%s ",cardapio[i].nome);
        fprintf(cardapioFile,"%s ",cardapio[i].preco);
        fprintf(cardapioFile,"%s",cardapio[i].calorias);
    }
    fclose(cardapioFile);
}



void menuInit() {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO info;
    _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleScreenBufferInfo(_hConsole, &info))
        _termOrigColor = info.wAttributes;
#endif
}

int getkey() {
    int c;
#ifdef _WIN32
    c = getch();
#else
    struct termios org_opts, new_opts;
    /*-----  store old settings -----------*/
    tcgetattr(STDIN_FILENO, &org_opts);
    /*---- set new terminal parms --------*/
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    /*new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);*/
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    c = fgetc(stdin);
    /*------  restore old settings ---------*/
    tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
#endif
    return(c);
}

void drawMenu(char options[][50], int tam, int opc) {
    int i;
#ifdef _WIN32
    system("cls");
    SetConsoleTextAttribute(_hConsole, 10);
    printf("\n\n\t\t  %s\n\n", options[0]);
    SetConsoleTextAttribute(_hConsole, _termOrigColor);
#else
    printf("\033[2J");
    printf("\033[100A");
    printf("\n\n\t\t  \033[0;32m %s\n\n", options[0]);
    printf("\033[0m");
#endif

    for(i = 1; i < tam; i++) {
        if(i == opc) {
#ifdef _WIN32
            printf("\t\t");
            SetConsoleTextAttribute(_hConsole, 240);
            printf(" %s \n", options[i]);
            SetConsoleTextAttribute(_hConsole, _termOrigColor);
#else
            printf("\t\t\033[30;47m %s \n", options[i]);
            printf("\033[0m");
#endif
        }
        else
            printf("\t\t %s \n", options[i]);
    }
}

int showMenu(char options[][50], int tam){
	int opc = 1;
    int k, u = 0, p = 0;

    p++;
    drawMenu(options, tam, opc);
    while(1) {
        k = getkey();
#ifdef _WIN32
        if(u == 0xe0) {
            if(k == 0x48) {
                if(opc == 1)
                    opc = tam - 1;
                else
                    opc--;
            } else if(k == 0x50) {
                if(opc == tam - 1)
                    opc = 1;
                else
                    opc++;
            }
            drawMenu(options, tam, opc);
        } else if(k == 0xd)
            break;
#else
        if(p == 0x1b && u == 0x5b) {
            if(k == 0x41) {
                if(opc == 1)
                    opc = tam - 1;
                else
                    opc--;
            } else if(k == 0x42) {
                if(opc == tam - 1)
                    opc = 1;
                else
                    opc++;
            }
            drawMenu(options, tam, opc);
        } else if(k == '\n')
            break;
#endif
        p = u;
        u = k;
    }
	return opc;
}
