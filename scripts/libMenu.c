/* NAO ALTERE O CODIGO ABAIXO */
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
/* NAO ALTERE O CODIGO ACIMA */

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

int main() {
    char itensMenu[9][50] = {"MENU", "Novo", "Visualizar Cardapio", "Adicionar Prato", "Remover Prato","Busca faixa calorias","Ordem alfabetica","Ordem de preco","Sair"};
    char itensNovo[2][50] = {"NOVO", "Sair"};
    char itensSN[3][50] = {"Deseja salvar as alteracoes no arquivo cardapio?","Sim","Nao"};
    struct  Cardapio cardapio[50];
    int tam;
    tam=0;
    tam = updateCardapio(cardapio);

    menuInit();

    switch(showMenu(itensMenu, 9)) {
        case 1:
            showMenu(itensNovo, 2);
            break;
        case 2:
            printf("Visualizar Cardapio:\n");
            view(cardapio,tam);
            break;
        case 3:
            printf("Adicionar Prato:\n");
            tam = adicionarPrato(cardapio,tam,50);
            break;
        case 4:
            printf("Remover Prato:\n");
            tam = removerPrato(cardapio,tam);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        case 6:
            printf("Saindo...\n");
            break;
        case 7:
            printf("Saindo...\n");
            break;
        case 8:
            printf("Saindo...\n");
            break;
        case 9:
            printf("Saindo...\n");
            break;
    }
    menuInit();
    switch(showMenu(itensSN,3))
    {
        case 1:
            remove("cardapio.txt");
            editFile(cardapio,tam);
            break;
        case 2:
            break;
    }
    view(cardapio,tam);
    return 0;
}

void view(struct Cardapio cardapio[],int tamanho)
{
    int i;
    for(i=0;i<tamanho;i++)
    {
        if(i==(tamanho-1))
            printf("\n");
        printf("\n");
        printf("%s ",cardapio[i].nome);
        printf("RS:%s ",cardapio[i].preco);
        printf("cal: %s \n",cardapio[i].calorias);
    }
    if(tamanho==0)
    {
        printf("Cardapio Vazio\n");
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
int updateCardapio(struct Cardapio cardapio[])
{
    char linha[50];
    FILE *cardapioFile;
    cardapioFile = fopen("cardapio.txt", "r");
    char *token = NULL;
    int tamanho=0,i=0;
    if (cardapioFile == NULL)
    {
        return EXIT_FAILURE;
    }
    while(fgets(linha, sizeof linha, cardapioFile) != NULL)
    {
        token = strtok(linha," ");
        strcpy(cardapio[tamanho].nome,token);
        while(token != NULL){
            printf("\n%s", token);
            token = strtok(NULL, " ");
            if(i==0)
            {
                strcpy(cardapio[tamanho].preco,token);
            }
            else if(i==1)
            {
                strcpy(cardapio[tamanho].calorias,token);
            }
            i++;
        }
        tamanho=tamanho+1;
        i=0;
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
        if(i==tamanho-1)
        {
            fprintf(cardapioFile,"\n");
        }
    }
    fclose(cardapioFile);
}


















/* NAO ALTERE O CODIGO ABAIXO */
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
