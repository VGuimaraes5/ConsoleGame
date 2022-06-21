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
    LARGURA = 26,
    ALTURA_CORDA = 18
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

struct seguimentos
{
    variavel um;
    variavel dois;
    variavel tres;
    variavel quatro;
    variavel cinco;
    variavel seis;
    variavel sete;
    variavel oito;
    variavel nove;
    variavel dez;
};

typedef struct seguimentos segui;

segui seguimento;

variavel heroi, jogo;

int direcao;
char comando;
int pontos;
int vida = 3;
int cont = 0;
int direcao_corda;

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

void construir_corda()
{
    jogo.mapa[seguimento.dez.y][seguimento.dez.x] = '|';
    jogo.mapa[seguimento.nove.y][seguimento.nove.x] = '|';
    jogo.mapa[seguimento.oito.y][seguimento.oito.x] = '|';
    jogo.mapa[seguimento.sete.y][seguimento.sete.x] = '|';
    jogo.mapa[seguimento.seis.y][seguimento.seis.x] = '|';
    jogo.mapa[seguimento.cinco.y][seguimento.cinco.x] = '|';
    jogo.mapa[seguimento.quatro.y][seguimento.quatro.x] = '|';
    jogo.mapa[seguimento.tres.y][seguimento.tres.x] = '|';
    jogo.mapa[seguimento.dois.y][seguimento.dois.x] = '|';
    jogo.mapa[seguimento.um.y][seguimento.um.x] = '|';
}

void apagar_corda()
{
    jogo.mapa[seguimento.dez.y][seguimento.dez.x] = ' ';
    jogo.mapa[seguimento.nove.y][seguimento.nove.x] = ' ';
    jogo.mapa[seguimento.oito.y][seguimento.oito.x] = ' ';
    jogo.mapa[seguimento.sete.y][seguimento.sete.x] = ' ';
    jogo.mapa[seguimento.seis.y][seguimento.seis.x] = ' ';
    jogo.mapa[seguimento.cinco.y][seguimento.cinco.x] = ' ';
    jogo.mapa[seguimento.quatro.y][seguimento.quatro.x] = ' ';
    jogo.mapa[seguimento.tres.y][seguimento.tres.x] = ' ';
    jogo.mapa[seguimento.dois.y][seguimento.dois.x] = ' ';
    jogo.mapa[seguimento.um.y][seguimento.um.x] = ' ';
}

void controle_corda()
{

    if (direcao_corda == DIREITA && cont % 3 == 0)
    {

        apagar_corda();

        seguimento.um.x += 3;
        seguimento.dois.x += 3;
        seguimento.tres.x += 3;
        seguimento.quatro.x += 3;
        seguimento.cinco.x += 2;
        seguimento.seis.x += 2;
        seguimento.sete.x += 2;
        seguimento.oito.x += 1;
        if (seguimento.nove.x < (LARGURA / 2) + 1)
            seguimento.nove.x += 1;
    }

    if (seguimento.um.x > (LARGURA / 2) + 6)
        direcao_corda = ESQUERDA;

    if (direcao_corda == ESQUERDA && cont % 3 == 0)
    {

        apagar_corda();

        seguimento.um.x -= 3;
        seguimento.dois.x -= 3;
        seguimento.tres.x -= 3;
        seguimento.quatro.x -= 3;
        seguimento.cinco.x -= 2;
        seguimento.seis.x -= 2;
        seguimento.sete.x -= 2;
        seguimento.oito.x -= 1;
        if (seguimento.nove.x > (LARGURA / 2) - 1)
            seguimento.nove.x -= 1;
    }

    if (seguimento.um.x < (LARGURA / 2) - 4)
        direcao_corda = DIREITA;
}

void construir_mapa()
{

    for (int i = 0; i < ALTURA; i++)
    {
        for (int j = 0; j < LARGURA; j++)
        {
            if (i == ALTURA - 1)
            {
                if (j % 7 == 0)
                {
                    jogo.mapa[i][j] = ' ';
                    jogo.mapa[i][j + 1] = ' ';
                    jogo.mapa[i][j - 1] = ' ';
                    jogo.mapa[i][j - 2] = ' ';
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
    if (direcao == DIREITA)
        jogo.mapa[heroi.y - 2][heroi.x] = '>';
    else if (direcao == ESQUERDA)
        jogo.mapa[heroi.y - 2][heroi.x] = '<';
    else
        jogo.mapa[heroi.y - 2][heroi.x] = '@';
    jogo.mapa[heroi.y - 1][heroi.x - 1] = '/';
    jogo.mapa[heroi.y - 1][heroi.x + 1] = '\\';
    jogo.mapa[heroi.y - 1][heroi.x] = 'I';
    jogo.mapa[heroi.y][heroi.x - 1] = '/';
    jogo.mapa[heroi.y][heroi.x + 1] = '\\';
}

void apagar_player()
{
    jogo.mapa[heroi.y - 2][heroi.x] = ' ';
    jogo.mapa[heroi.y - 1][heroi.x - 1] = ' ';
    jogo.mapa[heroi.y - 1][heroi.x + 1] = ' ';
    jogo.mapa[heroi.y - 1][heroi.x] = ' ';
    jogo.mapa[heroi.y][heroi.x - 1] = ' ';
    jogo.mapa[heroi.y][heroi.x + 1] = ' ';
}

void imprimir_mapa()
{

    construir_player();
    construir_corda();
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
    if (heroi.x + 1 != LARGURA && jogo.mapa[heroi.y][heroi.x + 2] == ' ')
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
    if (heroi.x - 1 != 0 && jogo.mapa[heroi.y][heroi.x - 2] == ' ')
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

void controle_queda()
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
            controle_queda();
            if (direcao == DIREITA)
            {
                controle_direita();
                controle_queda();
                if (jogo.mapa[heroi.y - 1][heroi.x] != '=')
                {
                    heroi.y -= 1;

                    controle_queda();
                    controle_direita();
                    controle_queda();
                    if (jogo.mapa[heroi.y + 1][heroi.x] != '=')
                    {
                        heroi.y += 1;

                        controle_queda();
                        controle_direita();
                        controle_queda();
                    }
                }
            }
            else if (direcao == ESQUERDA)
            {
                controle_esquerda();
                controle_queda();
                if (jogo.mapa[heroi.y - 1][heroi.x] != '=')
                {
                    heroi.y -= 1;

                    controle_queda();
                    controle_esquerda();
                    controle_queda();
                    if (jogo.mapa[heroi.y - 1][heroi.x] != '=')
                    {
                        heroi.y += 1;

                        controle_queda();
                        controle_esquerda();
                        controle_queda();
                    }
                }
            }
            else if (direcao == CIMA)
            {
                controle_queda();
                heroi.y -= 1;
                controle_queda();
                heroi.y += 1;
                controle_queda();
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

void main()
{

    system("mode con:cols=55 lines=40");
    setlocale(LC_ALL, "");
    srand(time(NULL));

    construir_mapa();
    // obstaculo();

    for (;;)
    {
        heroi.x = ALTURA / 2;
        heroi.y = ALTURA - 2;
        direcao = CIMA;

        seguimento.um.x = LARGURA / 2;
        seguimento.um.y = ALTURA_CORDA;

        seguimento.dois.x = LARGURA / 2;
        seguimento.dois.y = ALTURA_CORDA - 1;

        seguimento.tres.x = LARGURA / 2;
        seguimento.tres.y = ALTURA_CORDA - 2;

        seguimento.quatro.x = LARGURA / 2;
        seguimento.quatro.y = ALTURA_CORDA - 3;

        seguimento.cinco.x = LARGURA / 2;
        seguimento.cinco.y = ALTURA_CORDA - 4;

        seguimento.seis.x = LARGURA / 2;
        seguimento.seis.y = ALTURA_CORDA - 5;

        seguimento.sete.x = LARGURA / 2;
        seguimento.sete.y = ALTURA_CORDA - 6;

        seguimento.oito.x = LARGURA / 2;
        seguimento.oito.y = ALTURA_CORDA - 7;

        seguimento.nove.x = LARGURA / 2;
        seguimento.nove.y = ALTURA_CORDA - 8;

        seguimento.dez.x = LARGURA / 2;
        seguimento.dez.y = ALTURA_CORDA - 9;

        direcao_corda = DIREITA;

        for (;;)
        {

            imprimir_mapa();
            delay();
            cont++;
            if (kbhit())
            {
                comando = getch();
                apagar_player();
                controle();
            }

            if (jogo.mapa[heroi.y + 1][heroi.x] == ' ' && jogo.mapa[heroi.y + 1][heroi.x + 1] == ' ' && jogo.mapa[heroi.y + 1][heroi.x - 1] == ' ')
            {
                apagar_player();
                heroi.y += 1;
                controle_queda();
            }
            controle_corda();
        }
    }
}
