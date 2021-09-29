#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//NAME:yClouder
//DATE:28/09/2021

void printar_table(int x, int tab1[x][x]);

void jogar(int x, int tab1[x][x]);

int main()
{
    int nivel, i, j, randon_n, pot, k;

    srand(time(NULL));

    //MENU
    printf("        ..#######. .########.##.....#.#######.#######.##......########\n");
    printf("        .##.....#. .##.....#.##.....#......##......##.##......##......\n");
    printf("        .##.....#. .##.....#.##.....#.....##......##..##......##......\n");
    printf("        ..#######. .########.##.....#....##......##...##......######..\n");
    printf("        .##.....#. .##.......##.....#...##......##....##......##......\n");
    printf("        .##.....#. .##.......##.....#..##......##.....##......##......\n");
    printf("        ..#######. .##........#######.#######.#######.#######.########\n");
    printf("\n\n");

    printf("ENTER THE GAME DIFFICULTY LEVEL(3, 4, 5): ");
    scanf("%d", &nivel);

    while(nivel != 3 && nivel != 4 && nivel != 5)
    {
        printf("        ENTER THE GAME DIFFICULTY LEVEL(3, 4, 5): ");
        scanf("%d", &nivel);
    }

    //MAIN TABLE STATEMENT
    int tab1[nivel][nivel];

    pot = pow(nivel, 2);

    for(i = 0; i<nivel; i++)
    {
        for(j = 0; j< nivel; j++)
        {
            tab1[i][j] = -1;
        }
    }

    //CREATE TABLE TO COMPARE IF THE NUMBERS IN THE 1 TABLE ARE REPEATED
    int tab2[pot];

    for(i = 0; i < pot; i++)
    {
        tab2[i] = i;
    }

    //PUTTING RANDOM VALUES IN THE MAIN TABLE
    printf("\n");

    for(i=0; i < nivel; i++)
    {
        for(j=0; j < nivel; j++)
        {
            randon_n = rand() % pot;

            for(k=0; k < pot; k++)
            {
                //CHECK IF THE NUMBER IS REPEATED
                if(tab2[k] == randon_n)
                {
                    tab1[i][j]= randon_n;
                    tab2[k] = -1;
                    break;
                }
            }
            if(tab1[i][j] != randon_n)
            {
                j--;
            }
        }
    }

    //PRINT THE TABLE
    system("cls");
    printar_table(nivel, tab1);

    //MUVS
    jogar(nivel, tab1);
    system("cls");
    printf("         #####  #     #  #####  #######  #####   #####  #######\n");
    printf("        #     # #     # #     # #       #     # #     # #     # \n");
    printf("        #       #     # #       #       #       #       #     # \n");
    printf("         #####  #     # #       #####    #####   #####  #     # \n");
    printf("              # #     # #       #             #       # #     # \n");
    printf("        #     # #     # #     # #       #     # #     # #     # \n");
    printf("         #####   #####   #####  #######  #####   #####  ####### \n");
    return 0;
}

void printar_table(int x, int tab1[x][x])
{
    int i, j;

    printf("\n       |---------------------------------------|\n");
    printf("\n");
    for(i=0; i < x; i++)
    {

        if(x == 5)
        {
            printf("             ");
        }
        else if(x == 4)
        {
            printf("                ");
        }
        else
        {
            printf("                  ");
        }
        for(j=0; j < x; j++)
        {
            if(tab1[i][j] < 10)
            {
                printf("[ %d ]", tab1[i][j]);
            }
            else
            {
                printf("[%d ]", tab1[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("       |---------------------------------------|\n");
    printf("\n");
}

void jogar(int x, int tab1[x][x])
{
    int cont= 0, cont2=1, qtd = 0, movimento, i, j, k = 0, cparada = 0, pot;
    int resposta[x][x];

    //STOP CASE
    for(i=0; i < x; i++)
    {
        for(j=0; j< x; j++)
        {
            resposta[i][j] = cont2;
            cont2++;
        }
    }
    resposta[x-1][x-1] = 0;

    pot = pow(x, 2);

    //MUV OPTIONS

    do
    {

        printf("ENTRE COM A DIRECAO DO ZERO(SETAS; UP, DOWN, LEFT, RIGHT): ");
        movimento = getch();
        movimento = getch();

        if(movimento == 72)//up
        {
            for(i=0; i < x; i++)
            {
                for(j=0; j < x; j++)
                {
                    if(tab1[i][j] == 0)
                    {
                        if(i-1 < 0)
                        {
                            k = 1;
                            printf("\n");
                            break;
                        }
                        tab1[i][j] = tab1[i-1][j];
                        tab1[i-1][j] = 0;
                        i = x;
                        j = x;
                    }
                }
            }
        }
        else if(movimento == 75)//left
        {
            for(i=0; i < x; i++)
            {
                for(j=0; j < x; j++)
                {
                    if(tab1[i][j] == 0)
                    {
                        if(j-1 < 0)
                        {
                            k = 1;
                            printf("\n");
                            break;
                        }
                        tab1[i][j] = tab1[i][j-1];
                        tab1[i][j-1] = 0;
                        i = x;
                        j = x;
                    }

                }
            }
        }

        else if(movimento == 80)//down
        {
            for(i=0; i < x; i++)
            {
                for(j=0; j < x; j++)
                {
                    if(tab1[i][j] == 0)
                    {
                        if(i+1 > x-1)
                        {
                            k = 1;
                            printf("\n");
                            break;
                        }
                        tab1[i][j] = tab1[i+1][j];
                        tab1[i+1][j] = 0;
                        i = x;
                        j = x;
                    }

                }
            }
        }

        else if(movimento == 77)//right
        {
            for(i=0; i < x; i++)
            {
                for(j=0; j < x; j++)
                {
                    if(tab1[i][j] == 0)
                    {
                        if(j + 1 > x - 1)
                        {
                            k = 1;
                            printf("\n");
                            break;
                        }
                        tab1[i][j] = tab1[i][j+1];
                        tab1[i][j+1] = 0;
                        i = x;
                        j = x;
                    }

                }
            }
        }
        system("cls");
        if(k==1)
        {
            printf("            Enter a valid value!\n");
        }
        else
        {
            qtd++;
        }
        printar_table(x, tab1);
        printf("        MUVS: %d\n", qtd);
        k = 0;

        //VERIFY THE CORECT ANSWER!
        cparada = 0;

        for(i=0; i < x; i++)
        {
            for(j=0; j < x; j++)
            {
                if(tab1[i][j] == resposta[i][j]){
                    cparada++;
                }
            }
        }
    }
    while(cparada!=pot);
}
