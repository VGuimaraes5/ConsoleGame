/*

*/

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

enum sentido
{
    CIMA = 72,
    ESQUERDA = 75,
    DIREITA = 77,
    BAIXO = 80
};

enum tamanhos
{
    ALTURA = 26,
    LARGURA = 26
};

struct variaveis
{
    int x;
    int y;
    int aux;
    int efetuado;
    int tipo;
    char mapa[ALTURA][LARGURA];
    char ant, antsuperior;
};

typedef struct variaveis variavel;

variavel heroi, disparo[1000], inimigo[20], jogo, bomba[1000];

int direcao;
char comando;
int pontos;
int vida = 3;

void posicao_tela(int X, int Y)
{

    COORD coord = {X, Y};
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, coord);
}

void apagar_tela()
{
    DWORD n;
    DWORD size;
    COORD coord = {0};
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(h, &csbi);


    size = csbi.dwSize.X * csbi.dwSize.Y;


    FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
    GetConsoleScreenBufferInfo(h, &csbi);
    FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);

    SetConsoleCursorPosition(h, coord);
}

void delay()
{

    int tempo;
    tempo = 20;

    clock_t goal = tempo + clock();
    while (goal > clock())
        ;
}

void construir_mapa()
{

    for (int i = 0; i < ALTURA; i++)
    {
        for (int j = 0; j < LARGURA; j++)
        {
            if (i == ALTURA - 1)
            {
                if (j % 7 == 0){
                    jogo.mapa[i][j] = ' ';
                    jogo.mapa[i][j+1] = ' ';
                    jogo.mapa[i][j-1] = ' ';
                    jogo.mapa[i][j-2] = ' ';
                    continue;

                }
                else
                    jogo.mapa[i][j] = '=';
            }
            else
                jogo.mapa[i][j] = ' ';
        }
    }
}

void construir_player()
{
    if(direcao == DIREITA)
        jogo.mapa[heroi.y - 2][heroi.x] = '>';
    else if(direcao == ESQUERDA)
        jogo.mapa[heroi.y - 2][heroi.x] = '<';
    else
        jogo.mapa[heroi.y - 2][heroi.x] = '@';
    jogo.mapa[heroi.y- 1][heroi.x -1] = '/';
    jogo.mapa[heroi.y- 1][heroi.x + 1] = '\\';
    jogo.mapa[heroi.y - 1][heroi.x] = 'I';
    jogo.mapa[heroi.y][heroi.x-1 ] = '/';
    jogo.mapa[heroi.y][heroi.x + 1] = '\\';
}

void apagar_player()
{
    jogo.mapa[heroi.y - 2][heroi.x] = ' ';
    jogo.mapa[heroi.y- 1][heroi.x -1] = ' ';
    jogo.mapa[heroi.y- 1][heroi.x +1] = ' ';
    jogo.mapa[heroi.y - 1][heroi.x] = ' ';
    jogo.mapa[heroi.y][heroi.x -1] = ' ';
    jogo.mapa[heroi.y][heroi.x + 1] = ' ';
}

void imprimir_mapa()
{

    construir_player();

    for (int i = 0; i < ALTURA; i++)
    {
        posicao_tela(1, i);
        for (int j = 0; j < LARGURA; j++)
        {
            printf(" %c", jogo.mapa[i][j + jogo.aux]);
        }
    }
}

void controle_direita()
{
    if (heroi.x+1 == LARGURA || jogo.mapa[heroi.y][heroi.x + 2] != ' ')
    {
    }
    else
    {
        if (heroi.x > (LARGURA - (ALTURA / 2)) || heroi.x < (ALTURA / 2))
        {
            heroi.x += 1;
        }
        else
        {
            heroi.x += 1;
            jogo.aux += 1;
        }
    }
}

void controle_esquerda()
{
    if (heroi.x-1 == 0 || jogo.mapa[heroi.y][heroi.x - 2] != ' ')
    {
    }
    else
    {
        if (heroi.x < (ALTURA / 2) + 1 || heroi.x > (LARGURA - (ALTURA / 2) + 1))
        {
            heroi.x -= 1;
        }
        else
        {
            heroi.x -= 1;
            jogo.aux -= 1;
        }
    }
}

void controle_pulo()
{

    imprimir_mapa();
    apagar_player();
}

void controle()
{

    switch (comando)
    {

    case -32: // VALOR QUE TODA SETA RETORNA E DEVE SER DESPREZADO
        break;

    case CIMA:
        if (jogo.mapa[heroi.y - 1][heroi.x] == 'H')
            heroi.y -= 1;
        direcao = CIMA;
        break;

    case BAIXO:
        if (jogo.mapa[heroi.y + 1][heroi.x] == 'H')
            heroi.y += 1;

        break;

    case ESQUERDA:
        controle_esquerda();
        direcao = ESQUERDA;
        break;

    case DIREITA: // direita
        controle_direita();
        direcao = DIREITA;
        break;

    case ' ':
        if (jogo.mapa[heroi.y - 1][heroi.x] != '=' || jogo.mapa[heroi.y + 1][heroi.x] != ' ')
        {
            heroi.y -= 1;
            controle_pulo();
            if (direcao == DIREITA)
            {
                controle_direita();
                controle_pulo();
                if (jogo.mapa[heroi.y - 1][heroi.x] == '=')
                {
                }
                else
                {
                    heroi.y -= 1;

                    controle_pulo();
                    controle_direita();
                    controle_pulo();
                    if (jogo.mapa[heroi.y + 1][heroi.x] == '=')
                    {
                    }
                    else
                    {
                        heroi.y += 1;

                        controle_pulo();
                        controle_direita();
                        controle_pulo();
                    }
                }
            }
            else if (direcao == ESQUERDA)
            {
                controle_esquerda();
                controle_pulo();
                if (jogo.mapa[heroi.y - 1][heroi.x] != '=')
                {
                    heroi.y -= 1;

                    controle_pulo();
                    controle_esquerda();
                    controle_pulo();
                    if (jogo.mapa[heroi.y - 1][heroi.x] != '=')
                    {
                        heroi.y += 1;

                        controle_pulo();
                        controle_esquerda();
                        controle_pulo();
                    }
                }
            }
            else if (direcao == CIMA)
            {
                controle_pulo();
                heroi.y -= 1;
                controle_pulo();
                heroi.y += 1;
                controle_pulo();
            }

            if (jogo.mapa[heroi.y + 1][heroi.x] != '=')
            {
                heroi.y += 1;
            }
        }

        break;

    default:
        posicao_tela(ALTURA + 2, (ALTURA / 2));
        printf("JOGO PAUSADO");
        posicao_tela(ALTURA - 8, ((ALTURA / 2) + 2));
        printf("ESCOLHA UMA DIRECAO PARA RETORNAR");
        getch();
        break;
    }
}

void obstaculo()
{

    for (int j = 10; j < 30; j++)
    {
        if (j > 20 && j < 30)
            jogo.mapa[ALTURA - 3][j] = '=';
    }
    for (int j = 15; j < 35; j++)
    {
        if (j > 25 && j < 35)
            jogo.mapa[ALTURA - 5][j] = '=';
    }
    for (int j = 20; j < 40; j++)
    {
        if (j > 30 && j < 40)
            jogo.mapa[ALTURA - 7][j] = '=';
    }
    for (int j = 25; j < 45; j++)
    {
        if (j > 35 && j < 45)
            jogo.mapa[ALTURA - 9][j] = '=';
    }
}

int main()
{

    system("mode con:cols=55 lines=40"); // dimensionamento da tela
    setlocale(LC_ALL, "");               // usa a localiza�ao do sistema operacional
    srand(time(NULL));

    construir_mapa();
    //obstaculo();

    for (;;)
    {
        heroi.x = ALTURA / 2;
        heroi.y = ALTURA - 2;
        direcao = CIMA;

        for (;;)
        {

            imprimir_mapa();
            delay();

            if (kbhit())
            {
                comando = getch();
                apagar_player();
                controle();
            }

            if (jogo.mapa[heroi.y + 1][heroi.x] == ' '
                && jogo.mapa[heroi.y + 1][heroi.x+1] == ' '
                && jogo.mapa[heroi.y + 1][heroi.x-1] == ' ')
            {
                apagar_player();
                heroi.y += 1;
                controle_pulo();
            }
        }
    }

    return 0;
}
