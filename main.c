#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

//bonus_bandeira(BB)
#define BB 3
void save_arquivo(char mat[N][N]);
int main()

{

    int matriz_dados[N][N]= {0};
    char matriz_jogador[N][N] = {'0'};
    int i,j,k,m, life=3, conta_bomba=0,dificuldade,quadrado_livre_bomba=0,primeira_mina=0, jogadas_consecutivas=0,numero_inicializacao = 0;

    ///Vendo se iniciamos as matrizes por arquivo de texto ou aleatoriamente
    while(numero_inicializacao == 0)
    {
        printf("============================================================\n");
        printf("Voce quer comecar um novo jogo ou pegar um save?(1 novo / 2 save)\n");
        scanf("%d",&numero_inicializacao);
        printf("============================================================\n");
        if((numero_inicializacao != 1) && (numero_inicializacao != 2))
        {
            system("cls"); ///windows
            ///system("clear"); ///linux*/
            printf("Voce so pode escolher entre 1 e 2\n");
        }
        else
        {
            break;
        }


    }

//(se vai inciar um novo jogo ou usar um arquivo)
///Menu para selecao de dificuldade e inserir bombas
    if(numero_inicializacao==1)
    {
        ///
        while(numero_inicializacao==1)
        {
            printf("============================================================\n");
            printf("Em qual o nivel de dificuldade que voce quer jogar ?\nDigite:\n 1 para facil\n 2 para medio\n 3 para dificil\n");
            scanf("%d",&dificuldade);
            printf("============================================================\n");

            switch (dificuldade)
            {
                /// Aqui inserimos "as bombas " na matriz de dados
                srand(time(NULL));
            case  1:
            {
                i=0;
                while(i < (N*N)*.25)
                {
                    k = rand()%(N-1);
                    m = rand()%(N-1);
                    if(matriz_dados[k][m] != 1)
                    {
                        matriz_dados[k][m] = 1;
                        i++;
                    }
                }
                quadrado_livre_bomba = ( (N*N)*.75 );
                numero_inicializacao=NULL;
            }
            break;

            case  2:
            {
                i=0;
                while(i < ((N*N)*.5))
                {
                    k=rand()%(N-1);
                    m=rand()%(N-1);
                    if(matriz_dados[k][m] != 1)
                    {
                        matriz_dados[k][m] = 1;
                        i++;
                    }
                }
                quadrado_livre_bomba =  ( (N*N)*.5) ;
                numero_inicializacao=NULL;
            }
            break;

            case 3:
            {
                i=0;
                while(i <  ( (N*N)*.75 ))
                {
                    k=rand()%(N-1);
                    m=rand()%(N-1);
                    if(matriz_dados[k][m] != 1)
                    {
                        matriz_dados[k][m] = 1;
                        i++;
                    }
                }
                quadrado_livre_bomba =  ( (N*N)*.25 );
                numero_inicializacao = NULL;
            }
            break;

            default:
            {
                system("cls"); ///windows
                ///system("clear"); ///linux*/
                printf("Voce so pode escolher uma das opcoes a abaixo digite novamente\n ");

            }
            }


        }
        /// Inicalizando a matriz jogador com '0'

        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                matriz_jogador[i][j]='0';

            }
        }
        ///

        ///
    }
    else
    {
        ///parte dos  arquivos leitura
        leitura_save(matriz_jogador);
    }
    /*
    ///pra verificar a matriz
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                printf(" %d",matriz_dados[i][j]);
            }
            printf("\n");
        }
    */

    while(life > 0 && quadrado_livre_bomba  >0 )
    {

        printf("Informe um i e um j  entre (0 e 9) \n");
        printf("Digite 112 em qualquer  cooordenada para salvar o jogo\n");
        scanf("%d%d",&i,&j);
        if(i == 112 || j == 112)
        {
            ///salvando o jogo
            escrita_save(matriz_jogador);
            ///


        }
        else
        {
            k=i;
            m=j;
            if( matriz_jogador[i][j]!='0')
            {
                printf("Voce nao pode jogar nessa posicao de novo\n");

            }
            else
            {
                ///Aqui verificamos as bombas ao redor da posicao inicial
                if(matriz_dados[i][j]!=1 )
                {
                    ///
                    if(i+1 < N)
                    {
                        if(j+1 < N)
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
                        if(j+1<N)
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
                    if(j+1<N)
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
                    quadrado_livre_bomba --;
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

            }////////////////////////////

            /// Mostrando a matriz  do jogador
            /// System clean para "atualizar a tela"
            system("cls"); ///windows
            ///system("clear"); ///linux*/
            printf("============================================================\n");
            for(i=0; i<N; i++)
            {
                for(j=0; j<N; j++)
                {
                    printf(" %c", matriz_jogador[i][j]);
                }
                printf("\n");
            }
            printf("##Ainda existem %d quadrados livres de bombas##\n", quadrado_livre_bomba);
            printf("============================================================\n");

            ///fim de mostrando a matriz do jogador

        }

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

void escrita_save(char mat[N][N])
{
    FILE * arq = fopen("file.txt", "w");
    int i, j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            fprintf(arq, "%d %d %c\n",i, j, mat[i][j]);
        }
    }
    fclose(arq);
}
void leitura_save(char mat[N][N])
{
    int i, j;
    char val;

    FILE * arq = fopen("file.txt", "r");

    if(arq != NULL)
    {
        while(fscanf(arq, "%d %d %c", &i, &j, &val) != EOF)
        {
            mat[i][j] = val;
        }
    }
    else
    {
        printf("erro ao abrir o arquivo\n");
    }

    fclose(arq);
}






