#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
 srand(time(NULL));
 //variaveis iniciais
 int tam=20; //tamanho do mapa
 char cenario[tam][tam];//matriz do cenario
 char tecla_digitada; 
 char saida ='s';
 char ponto = '.';
 int q_balas = 0;
  
 
 //iniciar a matriz
  for(int linha=0;linha<tam;linha++)
  {
   printf("\n");
   for(int coluna=0;coluna < tam;coluna++)
   {
     cenario[linha][coluna]= ponto;
     //printf("%c ", cenario[linha][coluna]);
     /*imprime a matriz preenchida apenas com os caracteres, sem os obstaculos e zumbis, que representam lugares "vazios" que Rick pode andar*/
   }
  }

 //estabalecer coordenada do personagem no cenário
  char personagem = 'R';
  int linha_p = rand()%tam;
  int coluna_p = rand()%tam;

  cenario[linha_p][coluna_p]=personagem;

  printf("\n");
  
 //determinar quantidade dos obstaculos
  int n_carros=4;
  int n_arvores=7;
  int n_pedras=8;
  int n_balas=4;
  
 //estabalecer coordenadas dos carros no cenário
  for(int carros=0;carros <n_carros;)
  {
    int carro_linha=rand()%tam;
    int carro_coluna=rand()%tam;
    printf("\n");
    if(cenario[carro_linha][carro_coluna]== ponto)
    {
      cenario[carro_linha][carro_coluna]= 'C';
      carros++;
    }
  }

 //estabalecer coordenadas das arvores no cenário
  for(int arvore=0;arvore<n_arvores;)
  {
    int arvore_linha=rand()%tam;
    int arvore_coluna=rand()%tam;
    printf("\n");
    if(cenario[arvore_linha][arvore_coluna]== ponto)
    {
      cenario[arvore_linha][arvore_coluna]= 'A';
      arvore++;
    }
  }
  
 //estabalecer coordenadas das pedras no cenário
   for(int pedra=0;pedra<n_pedras;)
   {
    int pedra_linha=rand()%tam;
    int pedra_coluna=rand()%tam;
    printf("\n");
    if(cenario[pedra_linha][pedra_coluna] == ponto)
    {
      cenario[pedra_linha][pedra_coluna]= 'P';
      pedra++;
    }
   }

 //estabalecer coordenadas das balas no cenário
   for(int bala=0;bala<n_balas;)
   {
    int bala_linha=rand()%tam;
    int bala_coluna=rand()%tam;
    printf("\n");
    if(cenario[bala_linha][bala_coluna]== ponto)
    {
      cenario[bala_linha][bala_coluna]= 'B';
      bala++;
    }
   }
 //estabalecer coordenadas dos zumbis no cenário
  int n_zumbis=15;
  for(int zumbi=0;zumbi<n_zumbis;)
  {
    int zumbi_linha=rand()%tam;
    int zumbi_coluna=rand()%tam;
    printf("\n");
    if(cenario[zumbi_linha][zumbi_coluna]== ponto)
    {
      cenario[zumbi_linha][zumbi_coluna]= 'z';
      zumbi++;
    }
  }
 //estabalecer coordenada da saída no cenário
  int saida_linha;
  int saida_coluna;
  for(int saida=0;saida<1;)
  {
   int saida_linha=rand()%tam;
   int saida_coluna=rand()%tam;
   printf("\n");
   if(cenario[saida_linha][saida_coluna]== ponto)
   {
     cenario[saida_linha][saida_coluna]= 'S';
     saida++;
   }
  }

 //MOVIMENTACÃO DE RICK

 do{   
    //inicializando a tela do jogo
      printf("\nBem vindo ao jogo The Walking Dead! \nControle o personagem Rick até uma saída em algum local do mapa, \ncolete balas e mate os zumbis, ou morra.\n");
      printf("\nLegenda: R - Rick / z - zumbi / A - Árvore / B - Bala \n         C - Carro parado / S -Saída\n");

      //atualizar mapa
      for(int linha=0;linha<tam;linha++)
      {
        printf("\n");
        for(int coluna=0;coluna < tam;coluna++)
        {
          printf("%c ", cenario[linha][coluna]);
        }
      }
    
     printf("\n");
     printf("\tBalas: %i\n", q_balas);
          
     printf("\nw - cima / s - baixo / d - direita / a - esquerda\n");
     printf("R:(%i,%i)\t", linha_p,coluna_p);
     printf("Movimento: ");
     scanf("%c", &tecla_digitada);  
     getchar();

    //movimentos e condições
      if(tecla_digitada == 'w' && linha_p > 0)//Rick sobe
      {
        if(cenario[linha_p - 1][coluna_p] == ponto || cenario[linha_p - 1][coluna_p] =='B' || cenario[linha_p - 1][coluna_p] =='z'  || cenario[linha_p - 1][coluna_p] =='S')
        {
          if(cenario[linha_p - 1][coluna_p] == ponto)//impede que Rick ultrapasse os obstaculos
          {
            linha_p--;
            cenario[linha_p][coluna_p] = personagem;
            cenario[linha_p + 1][coluna_p] = ponto;
          }
          else if(cenario[linha_p - 1][coluna_p] =='B')//contagem de balas
          { 
            q_balas++;
            linha_p--;
            cenario[linha_p][coluna_p] = personagem;
            cenario[linha_p + 1][coluna_p] = ponto;
          }
          else if(cenario[linha_p - 1][coluna_p] =='S')//Rick alcança a saida
          { 
            linha_p--;
            cenario[linha_p][coluna_p] = personagem;
            cenario[linha_p + 1][coluna_p] = ponto;
            printf("\n\n***Rick fugiu (Você venceu o jogo)***\n");
            return(0);
          }
          else if(cenario[linha_p - 1][coluna_p] =='z')//"matar" zumbis e diminuir o numero de balas QUANDO OS ZUMBIS ESTAVAM "FIXOS" NO TABULEIRO
          { 
            if(q_balas<1)
            {
              q_balas--;
              linha_p--;
              cenario[linha_p][coluna_p] = personagem;
              cenario[linha_p + 1][coluna_p] = ponto;
              printf("\n\nRick foi morto por um zumbi (Você perdeu o jogo)\n");
              return(0);
            }
            if(q_balas>0)
            {
              q_balas--;
              linha_p--;
              cenario[linha_p][coluna_p] = personagem;
              cenario[linha_p + 1][coluna_p] = ponto;
              printf("\n\nRick matou um zumbi\n");
            }
          }

        }  
      }
      else if(tecla_digitada == 's'  && linha_p < tam - 1)//Rick desce
      {
        if(cenario[linha_p + 1][coluna_p] == ponto || cenario[linha_p + 1][coluna_p] == 'B'|| cenario[linha_p + 1][coluna_p] == 'z'|| cenario[linha_p + 1][coluna_p] =='S')
        {
          if(cenario[linha_p + 1][coluna_p] == ponto)//impede que Rick ultrapasse os obstaculos
          {
            linha_p++;
            cenario[linha_p][coluna_p] = personagem;
            cenario[linha_p - 1][coluna_p] = ponto;
          }
          else if(cenario[linha_p + 1][coluna_p] == 'B')//contagem de balas
          {
            q_balas++;
            linha_p++;
            cenario[linha_p][coluna_p] = personagem;
            cenario[linha_p - 1][coluna_p] = ponto;
          }
          else if(cenario[linha_p + 1][coluna_p] =='S')//Rick alcança a saida
          { 

            linha_p++;
            cenario[linha_p][coluna_p] = personagem;
            cenario[linha_p - 1][coluna_p] = ponto;
            printf("\n\n***Rick fugiu (Você venceu o jogo)***\n");
            return(0);
          }
          else if(cenario[linha_p + 1][coluna_p] == 'z')//"matar" zumbis e diminuir o numero de balas QUANDO OS ZUMBIS ESTAVAM "FIXOS" NO TABULEIRO.
          {
            if(q_balas<1)
            {
              q_balas--;
              linha_p++;
              cenario[linha_p][coluna_p] = personagem;
              cenario[linha_p - 1][coluna_p] = ponto;
              printf("\n\nRick foi morto por um zumbi (Você perdeu o jogo)\n");
              return(0);
            }
            if(q_balas>0)
            {
              linha_p++;
              q_balas--;
              cenario[linha_p][coluna_p] = personagem;
              cenario[linha_p - 1][coluna_p] = ponto;
              printf("\n\nRick matou um zumbi\n");
            }
          }
        } 
      }
      else if(tecla_digitada == 'a'  && coluna_p > 0)//Rick move-se para a esquerda
      {
        if(cenario[linha_p][coluna_p - 1] == ponto || cenario[linha_p][coluna_p - 1] == 'B' || cenario[linha_p][coluna_p - 1] == 'z' || cenario[linha_p][coluna_p - 1] =='S')
        {
          if(cenario[linha_p][coluna_p - 1] == ponto)//impede que Rick ultrapasse os obstaculos
          {
            coluna_p--;
            cenario[linha_p][coluna_p] = personagem;
            cenario[linha_p][coluna_p + 1] = ponto;
          }
          else if(cenario[linha_p][coluna_p - 1] == 'B')//contagem de balas
          {
            q_balas++;
            coluna_p--;
            cenario[linha_p][coluna_p] = personagem;
            cenario[linha_p][coluna_p + 1] = ponto;
          }
          else if(cenario[linha_p][coluna_p - 1] =='S')//Rick alcança a saida
          { 

            coluna_p--;
            cenario[linha_p][coluna_p] = personagem;
            cenario[linha_p][coluna_p + 1] = ponto;
            printf("\n\n***Rick fugiu (Você venceu o jogo)***\n");
            return(0);
          }
          else if (cenario[linha_p][coluna_p - 1] == 'z')//"matar" zumbis e diminuir o numero de balas QUANDO OS ZUMBIS ESTAVAM "FIXOS" NO TABULEIRO
          {
            if(q_balas<1)
            {
              q_balas--;
              coluna_p--;
              cenario[linha_p][coluna_p] = personagem;
              cenario[linha_p][coluna_p+1] = ponto;
              printf("\n\nRick foi morto por um zumbi (Você perdeu o jogo)\n");
              return(0);
            }
            if(q_balas>0)
            {
              coluna_p--;
              q_balas--;
              cenario[linha_p][coluna_p] = personagem;
              cenario[linha_p][coluna_p + 1] = ponto;
              printf("\n\nRick matou um zumbi\n");
            }
          }
        }
      }
      else if(tecla_digitada == 'd'  && coluna_p < tam - 1)//Rick move-se para a direita
      {

        if(cenario[linha_p][coluna_p + 1] == ponto || cenario[linha_p][coluna_p + 1] == 'B' || cenario[linha_p][coluna_p + 1] == 'z' || cenario[linha_p][coluna_p + 1] =='S')
        {
          if(cenario[linha_p][coluna_p + 1] == ponto)//impede que Rick ultrapasse os obstaculos
          {
            coluna_p++;
            cenario[linha_p][coluna_p] = personagem;
            cenario[linha_p][coluna_p - 1] = ponto;
          }
          else if(cenario[linha_p][coluna_p + 1] == 'B')//contagem de balas
          {
            q_balas++;
            coluna_p++;
            cenario[linha_p][coluna_p] = personagem;
            cenario[linha_p][coluna_p - 1] = ponto;
          }
          else if(cenario[linha_p][coluna_p + 1] =='S')//Rick alcança a saida
          { 

            coluna_p++;
            cenario[linha_p][coluna_p] = personagem;
            cenario[linha_p][coluna_p - 1] = ponto;
            printf("\n\n***Rick fugiu (Você venceu o jogo)***\n");
            return(0);
          }
          else if(cenario[linha_p][coluna_p + 1] == 'z')//"matar" zumbis e diminuir o numero de balas QUANDO OS ZUMBIS ESTAVAM "FIXOS" NO TABULEIRO
          {
            if(q_balas<1)
            {
              q_balas--;
              coluna_p++;
              cenario[linha_p][coluna_p] = personagem;
              cenario[linha_p][coluna_p-1] = ponto;
              printf("\n\nRick foi morto por um zumbi (Você perdeu o jogo)\n");
              return(0);
            }
            if(q_balas>0)
            {
              coluna_p++;
              q_balas--;
              cenario[linha_p][coluna_p] = personagem;
              cenario[linha_p][coluna_p-1] = ponto;
              printf("\n\nRick matou um zumbi\n");
            }
          }
        }
      }
      else //caso seja digitado uma tecla invalida para movimento
      {
        printf("Digite uma tecla válida\n");
      } 

      //Zumbi desce
        if(cenario[linha_p - 3][coluna_p] == 'z')//casa 3
        {
          if(cenario[linha_p -2][coluna_p] == ponto)//Zumbi não atravessa obstáculo
          {
           cenario[linha_p - 3][coluna_p] = '.';
           cenario[linha_p -2][coluna_p] = 'z';
          }
        }
        else if(cenario[linha_p - 2][coluna_p] == 'z')//casa 2
        {
          if(cenario[linha_p - 1][coluna_p] == ponto)//Zumbi não atravessa obstáculo
          {
           cenario[linha_p - 2][coluna_p] = '.';
           cenario[linha_p - 1][coluna_p] = 'z';
          }
        }
        else if (cenario[linha_p - 1][coluna_p] == 'z')//casa 1
        {
         if (q_balas > 0) //Rick gasta uma bala no zumbi(decrementa)
         {
           cenario[linha_p - 1][coluna_p] = ponto;
           q_balas--;
         }
         else //Rick foi morto por um zumbi
         {
           cenario[linha_p - 1][coluna_p] = '.';
           cenario[linha_p][coluna_p] = 'z';
           printf("\n\n***Rick foi morto por um zumbi (Fim de jogo)***\n");
           return(0);
         }
        } 

      //Zumbi sobe
        if(cenario[linha_p + 3][coluna_p] == 'z')//casa 3
        {
          if(cenario[linha_p + 2][coluna_p] == ponto)//Zumbi não atravessa obstáculo
          {
           cenario[linha_p + 3][coluna_p] = '.';
           cenario[linha_p + 2][coluna_p] = 'z';
          }
        }
        else if(cenario[linha_p + 2][coluna_p] == 'z')//casa 2
        {
          if(cenario[linha_p + 1][coluna_p] == ponto)//Zumbi não atravessa obstáculo
          {
           cenario[linha_p + 2][coluna_p] = '.';
           cenario[linha_p + 1][coluna_p] = 'z';
          }
        }
        else if (cenario[linha_p +1][coluna_p] == 'z')//casa 1
        {
         if (q_balas > 0) //Rick gasta uma bala no zumbi(decrementa)
          {
            cenario[linha_p +1][coluna_p ] = ponto;
            q_balas--;
          }
         else //Rick foi morto por um zumbi
          {
            cenario[linha_p +1][coluna_p] = '.';
            cenario[linha_p][coluna_p] = 'z';
            printf("\n\n***Rick foi morto por um zumbi (Fim de jogo)***\n");
          return(0);
          }
        }

      //Zumbi move-se para a esquerda
        if(cenario[linha_p][coluna_p +3] == 'z')//casa 3
        {
          if(cenario[linha_p][coluna_p +2] == ponto)//Zumbi não atravessa obstáculo
          {
           cenario[linha_p ][coluna_p +3] = '.';
           cenario[linha_p][coluna_p +2] = 'z';
          }
        }
        else if(cenario[linha_p][coluna_p +2] == 'z')//casa 2
        {
          if(cenario[linha_p][coluna_p +1] == ponto)//Zumbi não atravessa obstáculo
          {
           cenario[linha_p][coluna_p +2] = '.';
           cenario[linha_p][coluna_p +1] = 'z';
          }
        }
        else if (cenario[linha_p][coluna_p + 1] == 'z')//casa 1
        {
         if (q_balas > 0) //Rick gasta uma bala no zumbi(decrementa)
         {
           cenario[linha_p][coluna_p + 1] = ponto;
           q_balas--;
         }
         else //Rick foi morto por um zumbi
         {
           cenario[linha_p][coluna_p + 1] = '.';
           cenario[linha_p][coluna_p] = 'z';
           printf("\n\n***Rick foi morto por um zumbi (Fim de jogo)***\n");
           return(0);
         }
        }

      //Zumbi move-se para a direita
        if(cenario[linha_p][coluna_p - 3] == 'z')//casa 3
        {
          if(cenario[linha_p][coluna_p - 2] == ponto)//Zumbi não atravessa obstáculo
          {
           cenario[linha_p][coluna_p - 3] = '.';
           cenario[linha_p][coluna_p - 2] = 'z';
          }
        }
        else if(cenario[linha_p][coluna_p - 2] == 'z')//casa 2
        {
          if(cenario[linha_p][coluna_p - 1] == ponto)//Zumbi não atravessa obstáculo
          {
           cenario[linha_p][coluna_p - 2] = '.';
           cenario[linha_p][coluna_p - 1] = 'z';
          }
        
        }
        else if (cenario[linha_p][coluna_p - 1] == 'z')//casa 1
        {
         if (q_balas > 0) //Rick gasta uma bala no zumbi(decrementa)
         {
           cenario[linha_p][coluna_p - 1] = ponto;
           q_balas--;
         }
         else //Rick foi morto por um zumbi
         {
           cenario[linha_p][coluna_p - 1] = '.';
           cenario[linha_p][coluna_p] = 'z';
           printf("\n\n***Rick foi morto por um zumbi (Fim de jogo)***\n");
           return(0);
         }
        }
    
      system("clear");

  }while (q_balas >=0);

 return 0;
}       
