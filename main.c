#include  <stdio.h>
#include <stdlib.h>
#include<time.h>
#define N 10
#define M 10
#define DF 25
#define DM 50
#define DD 75
//bonus_bandeira(BB)
#define BB 3

int main()

{

    int matriz_dados[N][M]= {0};
    char matriz_jogador[N][M]= {'0'};
    int i,j,k,m, life=3,conta_bomba=0,dificuldade,quadrado_livre_bomba=0,primeira_mina=0, jogadas_consecutivas=0;

//Tem que implementar a  parte de perguntas
//(se vai inciar um novo jogo ou usar um arquivo)
    srand(time(NULL));
    printf("============================================================\n");
    printf("Em qual o nivel de dificuldade que voce quer jogar ?\nDigite:\n 1 para facil\n 2 para medio\n 3 para dificil\n");
    scanf("%d",&dificuldade);
    printf("============================================================\n");

///Menu para selecao de dificuldade e inserir bombas

    switch (dificuldade)
    {
    /// Aqui inserimos "as bombas " na matriz de dados

    case  1:
    {
        i=0;
        while(i < DF)
        {
            k=rand()%9;
            m=rand()%9;
            if(matriz_dados[k][m] != 1)
            {
                matriz_dados[k][m] = 1;
                i++;
            }
        }
        quadrado_livre_bomba = DD;
    }
    break;

    case  2:
    {
        i=0;
        while(i < DM)
        {
            k=rand()%9;
            m=rand()%9;
            if(matriz_dados[k][m] != 1)
            {
                matriz_dados[k][m] = 1;
                i++;
            }
        }
        quadrado_livre_bomba = DM;
    }
    break;

    case 3:
    {
        i=0;
        while(i < DD)
        {
            k=rand()%9;
            m=rand()%9;
            if(matriz_dados[k][m] != 1)
            {
                matriz_dados[k][m] = 1;
                i++;
            }
        }
        quadrado_livre_bomba = DF;
    }
    break;

    default:
        printf("Você so pode escolher os as opcoes a cima digite novamente\n 1 para facil\n 2 para medio\n 1 para dificil");
    }

/*
///pra verificar a matriz
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            printf(" %d",matriz_dados[i][j]);
        }
        printf("\n");
    }
*/
/// Inicalizando a matriz jogador com '0'

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            matriz_jogador[i][j]='0';

        }
    }

///
    while(life>0 && quadrado_livre_bomba >0)
    {

        printf("Informe um i e um j \n");
        scanf("%d%d",&i,&j);
        k=i;
        m=j;
        ///Aqui verificamos as bombas ao redor da posicao inicial
        if(matriz_dados[i][j]!=1)
        {
            ///
            if(i+1<N)
            {
                if(j+1<M)
                {
                    if(matriz_dados[i+1][j+1]==1)
                        conta_bomba++;
                }
                if(j-1>=0)
                {
                    if(matriz_dados[i+1][j-1]==1)
                        conta_bomba++;
                }
                if(matriz_dados[i+1][j]==1)
                    conta_bomba++;
            }
            if(i-1>=0)
            {
                if(j+1<M)
                {
                    if(matriz_dados[i-1][j+1]==1)
                        conta_bomba++;
                }
                if(j-1>=0)
                {
                    if(matriz_dados[i-1][j-1]==1)
                        conta_bomba++;
                }
                if(matriz_dados[i-1][j]==1)
                    conta_bomba++;
            }
            if(j+1<M)
            {
                if(matriz_dados[i][j+1]==1)
                    conta_bomba++;
            }
            if(j-1>=0)
            {
                if(matriz_dados[i][j-1]==1)
                    conta_bomba++;
            }


            ///Adicionando 48 ao numero de bombas ao redor (48 equivale a  0 como char somado com a variacao de "conta_bomba" pode ir ate 56 que é
            /// o maximo de bombas que podem estar ao redor  da posicao escolhida)
            matriz_jogador[k][m]=48+conta_bomba;
            conta_bomba=0;
            quadrado_livre_bomba-- ;
            /// primeira jogada que nao foi uma bomba
            primeira_mina = 1;
            jogadas_consecutivas++;


        }


        else
        {

            if(primeira_mina)
            {
                 matriz_jogador[i][j]='B';
                 life--;
                 jogadas_consecutivas=0;
            }
            else
            {
                matriz_jogador[i][j]='F';
                jogadas_consecutivas=0;
            }
        }
        /// 5 eh o limite especulado de jogadas consecutivas para obter o bonus
        if(jogadas_consecutivas == 5)
        {
            ///colocando as bandeiras aleatorias
            i = 0;
            while(i < BB)
            {
                k=rand()%9;
                m=rand()%9;
                if(matriz_dados[k][m] == 1 && matriz_jogador[k][m]!= 'F')
                {
                    matriz_jogador[k][m] = 'F';
                }
                i++;
            }
            jogadas_consecutivas=0;
        }



        /// Mostrando a matriz  do jogador
        /// System clean para "atualizar a tela"
        system("cls"); ///windows
        ///system("clear"); ///linux
        printf("============================================================\n");
        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                printf(" %c", matriz_jogador[i][j]);
            }
            printf("\n");
        }
        printf("##Ainda existem %d quadrados livres de bombas##\n", quadrado_livre_bomba);
        printf("============================================================\n");

        ///fim de mostrando a matriz do jogador
    }
    if(!quadrado_livre_bomba)
    {
        printf("Voce ganhou o jogo !!!");
    }
    else
    {
        printf("Voce perdeu o jogo !!!\nPERDEDOOOOORR!!!");
    }


    return 0;
}







