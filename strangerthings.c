
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// manual de controle do jogo
void manual(int page)
{
  if(page == 1)
  {
    printf("**_SALA DE AULA_**\n");
    printf("\n");
  }
  if(page == 2)
  {
    printf("\n+_______________________+");
    printf("\n| W - anda pra frente   |");
    printf("\n| A - anda pra esquerda |");
    printf("\n| S - anda pra trás     |");
    printf("\n| D - anda pra direita  |");
    printf("\n| --------------------- |");
    printf("\n| P - abre o portal     |");
    printf("\n+_______________________+\n");
    printf("\n");
  }
  if(page == 3)
  {
    printf("**_MUNDO INVERTIDO_**\n");
    printf("\n");
  }
  if(page == 4)
  {
    printf("\n+_________________________________+");
    printf("\n| T - São árvores                 |");
    printf("\n| C - São carros                  |");
    printf("\n| B - São casas abandonadas       |");
    printf("\n| . - São panquecas e te dão vida!|");
    printf("\n| ------------------------------- |");
    printf("\n| W - Salve o Will!!              |");
    printf("\n| S - Encontre a saída!           |");
    printf("\n+_________________________________+\n");
  }
}

// define linha e coluna do cenário como underscore
void zerar(int tam, char cenario[tam][tam])
{
  for(int l = 0; l < tam; l++)
    {
      for(int c = 0; c < tam; c++)
        {
          cenario[l][c] = '_';
        }
    }
}

// imprime linha e coluna do cenário
void imprimir(int tam, char cenario[tam][tam])
{
  for(int l = 0; l < tam; l++)
    {
      for(int c = 0; c < tam; c++)
        {
          printf("%c ", cenario[l][c]);
        }
      printf("\n");
    }
}

// inicializa elementos no cenário
void inicializarElemento(int tam, char cenario[tam][tam], char elemento, int n_elementos)
{
  for(int e = 1; e <= n_elementos; )
    {
      int el = rand()%10;
      int ec = rand()%10;

      if(cenario[el][ec] == '_')
      {
        cenario[el][ec] = elemento;
        e++;
      }
    }
}

void inicializarDemodog(int tam, char cenario[tam][tam], int n_elementos, int el, int ec)
{
  for(int d = 1; d <= n_elementos; d++)
  {
    int random = rand()%8+1;

    switch (random)
    {
    case 1:
      if(cenario[el-1][ec] == '_')
      {
        cenario[el-1][ec] = 'D';
      }
      break;
    case 2:
      if(cenario[el+1][ec] == '_')
      {
        cenario[el+1][ec] = 'D';
      }
      break;
    case 3:
      if(cenario[el][ec-1] == '_')
      {
        cenario[el][ec-1] = 'D';
      } 
      break;
    case 4:
      if(cenario[el][ec+1] == '_')
      {
        cenario[el][ec+1] = 'D';
      }
      break;
    case 5:
      if(cenario[el-1][ec-1] == '_')
      {
        cenario[el-1][ec-1] = 'D';
      }
      break;
    case 6:
      if(cenario[el+1][ec+1] == '_')
      {
        cenario[el+1][ec+1] = 'D';
      }
      break;
    case 7:
      if(cenario[el-1][ec+1] == '_')
      {
        cenario[el-1][ec+1] = 'D';
      }
      break;
    case 8:
      if(cenario[el+1][ec-1] == '_')
      {
        cenario[el+1][ec-1] = 'D';
      }
      break;
    }
  }
  printf("\nDemodogs spawnados em um raio de 9 metros quadrados!!");
}

void radar(int tam, char cenario[tam][tam], int el, int ec)
{
  // verificar se Eleven está perto de Will
  if(cenario[el-1][ec] == 'W')
  {
    inicializarDemodog(tam, cenario, 2, el, ec);
  }
  else if(cenario[el+1][ec] == 'W')
  {
    inicializarDemodog(tam, cenario, 2, el, ec);
  }
  else if(cenario[el][ec-1] == 'W')
  {
    inicializarDemodog(tam, cenario, 2, el, ec);
  }
  else if(cenario[el][ec+1] == 'W')
  {
    inicializarDemodog(tam, cenario, 2, el, ec);
  }
  else if(cenario[el-1][ec-1] == 'W')
  {
    inicializarDemodog(tam, cenario, 2, el, ec);
  }
  else if(cenario[el+1][ec+1] == 'W')
  {
    inicializarDemodog(tam, cenario, 2, el, ec);
  }
  else if(cenario[el-1][ec+1] == 'W')
  {
    inicializarDemodog(tam, cenario, 2, el, ec);
  }
  else if(cenario[el+1][ec-1] == 'W')
  {
    inicializarDemodog(tam, cenario, 2, el, ec);
  }
}

void imprimirInvisivel(int tam, char cenario[tam][tam])
{
  for (int l = 0; l < tam; l++)
  {
    for (int c = 0; c < tam; c++)
    {
      if(cenario[l][c] != 'D')
      {
        printf("%c ", cenario[l][c]);
      }
      else
      {
        printf("_ ");
      }
    }  
    printf("\n");
  }
}

int main(void)
{
  srand(time(NULL));
  char cenario[3][3];

  zerar(3, cenario);
  int willpego = 0;

  // inicia Eleven
  int el = rand()%3;
  int ec = rand()%3;
  cenario[el][ec] = 'E';
  
  //status da Eleven
  int vida = 100;
  int taxa_raiva = 0;
  int penalidade = 20;
  int status = 0;
  int soma = 0;
  int portal_aberto = 0;
  int dano = 10;

  do
    {
    manual(2);
    manual(1);
    // imprime o cenário
    imprimir(3, cenario);

    printf("\nVida: %i, Raiva: %i\n", vida, soma);

    // movimentação de Eleven
    char mov;
    printf("\n> ");
    scanf("%c", &mov);
    getchar();

    // Verificação da movimentação de Eleven
  switch (mov)
  {
  // Movimentação de Eleven, andar pra frente
  case 'w':
    if(el-1 >= 0)
    {
      if(cenario[el-1][ec] == 'P' && soma < 60)
      {
        vida -= penalidade;
        if (vida <= 0)
        {
          status = 1;
        }
        
      }
      else if(cenario[el-1][ec] == 'P' && soma >= 60)
    {
      status = 2;
    }
      cenario[el][ec] = '_';
      cenario[el-1][ec] = 'E';
      el--;
    }
    break;

  // Movimentação de Eleven, andar pra trás
  case 's':
    if(el+1 < 3)
    {
      if (cenario[el+1][ec] == 'P' && soma < 60)
      {
        vida -= penalidade;
        if (vida <= 0)
        {
          status = 1;
        }
        
      }
      else if(cenario[el+1][ec] == 'P' && soma >= 60)
    {
      status = 2;
    }
      cenario[el][ec] = '_';
      cenario[el+1][ec] = 'E';
      el++;
    }
    break;

  // Movimentação de Eleven, andar pra esquerda
  case 'a':
    if(ec-1 >= 0)
    {
      if (cenario[el][ec-1] == 'P' && soma < 60)
      {
        vida -= penalidade;
        if (vida <= 0)
        {
          status = 1;
        }
        
      }
      else if(cenario[el][ec-1] == 'P' && soma >= 60)
    {
      status = 2;
    }
      cenario[el][ec] = '_';
      cenario[el][ec-1] = 'E';
      ec--;
    }
    break;

// Movimentação de Eleven, andar pra direita
  case 'd':
    if(ec+1 < 3)
    {
      if (cenario[el][ec+1] == 'P' && soma < 60)
      {
        vida -= penalidade;
        if (vida <= 0)
        {
          status = 1;
        }
        
      }
      else if(cenario[el][ec+1] == 'P' && soma >= 60)
    {
      status = 2;
    }
      cenario[el][ec] = '_'; 
      cenario[el][ec+1] = 'E';
      ec++;
    }
    break;

  // abertura do portal
  case 'p':
    taxa_raiva = rand()%60;
    if(taxa_raiva < 60)
    {
      vida -= penalidade;
      if(vida <= 0)
      {
        status = 1;
      }
    }
    soma += taxa_raiva;
    if(soma > 100)
    {
      soma = 100;
    }
    if(soma >= 60 && portal_aberto == 0)
    {
      inicializarElemento(3, cenario, 'P', 1);
      portal_aberto = 1;
    }
    break;

  default:
    printf("\nComando inválido.");
    break;
    }
  system("@cls||clear"); 
    }
  while(status == 0);
  
  if(status == 1)
  {
    printf("Morreu.");
  }

  // mundo invertido
  else
  {
    srand(time(NULL));
    char cenario[10][10];
    char back[10][10];
    zerar(10, cenario);

  // inicializa Eleven
    int el = rand()%10;
    int ec = rand()%10;
    cenario[el][ec] = 'E';
    int buff = 5;

    int andarw = 0;
    int wl;
    int wc; 

    // inicializa Will
    if(willpego != 1)
    {
      wl = rand()%10;
      wc = rand()%10;
      cenario[wl][wc] = 'W';
    }
    
    // inicializa elementos do mundo invertido
    inicializarElemento(10, cenario, 'T', 10); // 10 árvores
    inicializarElemento(10, cenario, 'C', 5);  // 5 carros
    inicializarElemento(10, cenario, 'B', 5);  // 5 casas abandonadas
    inicializarElemento(10, cenario, '.', 20); // 10 panquecas
    inicializarElemento(10, cenario, 'D', 4);  // 4 demodogs

  do
  {
      // detector do will
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
      {
        if (cenario[i][j] == 'W' && willpego == 1)
        {
          cenario[i][j] = '_';
        } 
      }
    }

    manual(4);
    manual(3);
    imprimirInvisivel(10, cenario);
    printf("\nVida: %i, Raiva: %i\n", vida, soma);

    // radar detector do will
    radar(10, cenario, el, ec);
    
    if(cenario[el][ec] == cenario[wl][wc])
    {
      willpego = 1;
      inicializarElemento(10, cenario, 'S', 1);  // saída
    }

    char mov;

    printf("\n> ");
    scanf("%c", &mov);
    getchar();
    // movimentação de Eleven no mundo invertido
    switch (mov)
    {
    // Movimentação de Eleven, andar pra frente no mundo invertido
    case 'w':
    // verificar obstáculos - eleven
      if(el-1 >= 0 && cenario[el-1][ec] != 'T' && cenario[el-1][ec] != 'B' && cenario[el-1][ec] != 'C') 
      {
        if(cenario[el-1][ec] == 'S' && willpego == 1)
        {
          status = 0;
        }
        // navegação aleatória de will
        if(willpego != 1)
        {
          andarw = rand()%4;
          if(andarw == 0)
          {
          // verificar obstáculos - will
            if(wl-1 >= 0 && cenario[wl-1][wc] != 'T' && cenario[wl-1][wc] != 'B' && cenario[wl-1][wc] != 'C' && cenario[wl-1][wc] != 'E' && cenario[wl-1][wc] != 'S' && cenario[wl-1][wc] != 'X')
            {
              cenario[wl][wc] = '_';
              cenario[wl-1][wc] = 'W';
              wl--;
            }
          }
          else if(andarw == 1)
          {
            if(wl+1 < 10 && cenario[wl+1][wc] != 'T' && cenario[wl+1][wc] != 'B' && cenario[wl+1][wc] != 'C' && cenario[wl+1][wc] != 'E' && cenario[wl+1][wc] != 'S' && cenario[wl+1][wc] != 'D')
            {
              cenario[wl][wc] = '_';
              cenario[wl+1][wc] = 'W';
              wl++;
            }
          }
          else if(andarw == 2)
          {
            if(wc-1 >= 0 && cenario[wl][wc-1] != 'T' && cenario[wl][wc-1] != 'B' && cenario[wl][wc-1] != 'C' && cenario[wl][wc-1] != 'E' && cenario[wl][wc-1] != 'S' && cenario[wl][wc-1] != 'D')
            {
              cenario[wl][wc] = '_';
              cenario[wl][wc-1] = 'W';
              wc--;
            }
          }
          else if(andarw == 3)
        {
          if(wc+1 < 10 && cenario[wl][wc+1] != 'T' && cenario[wl][wc+1] != 'B' && cenario[wl][wc+1] != 'C' && cenario[wl][wc+1] != 'W' && cenario[wl][wc+1] != 'S' && cenario[wl][wc+1] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl][wc+1] = 'W';
            wc++;
          }
        }
        }

        if(vida < 100)
        {
          if(cenario[el-1][ec] == '.')
          {
            vida += buff;
          }
        }
        if(vida <= 100)
        {
          if(cenario[el-1][ec] == 'D')
          {
            vida -= dano;
            if(vida <= 0)
            {
              status = 1;
            }
          }
        }
        cenario[el][ec] = '_';
        cenario[el-1][ec] = 'E';
        el--;
      }
      break;

    // Movimentação de Eleven, andar pra trás no mundo invertido
    case 's':
    // verificar obstáculos - eleven
      if(el+1 < 10 && cenario[el+1][ec] != 'T' && cenario[el+1][ec] != 'B' && cenario[el+1][ec] != 'C')
      {
        if(cenario[el+1][ec] == 'S')
        {
          status = 0;
        }
        // navegação aleatória de will
        andarw = rand()%4;
        if(andarw == 0)
        {
        // verificar obstáculos - will
          if(wl-1 >= 0 && cenario[wl-1][wc] != 'T' && cenario[wl-1][wc] != 'B' && cenario[wl-1][wc] != 'C' && cenario[wl-1][wc] != 'E' && cenario[wl-1][wc] != 'S' && cenario[wl-1][wc] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl-1][wc] = 'W';
            wl--;
          }
        }
        else if(andarw == 1)
        {
          if(wl+1 < 10 && cenario[wl+1][wc] != 'T' && cenario[wl+1][wc] != 'B' && cenario[wl+1][wc] != 'C' && cenario[wl+1][wc] != 'E' && cenario[wl+1][wc] != 'S' && cenario[wl+1][wc] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl+1][wc] = 'W';
            wl++;
          }
        }
        else if(andarw == 2)
        {
          if(wc-1 >= 0 && cenario[wl][wc-1] != 'T' && cenario[wl][wc-1] != 'B' && cenario[wl][wc-1] != 'C' && cenario[wl][wc-1] != 'E' && cenario[wl][wc-1] != 'S' && cenario[wl][wc-1] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl][wc-1] = 'W';
            wc--;
          }
        }
        else if(andarw == 3)
        {
          if(wc+1 < 10 && cenario[wl][wc+1] != 'T' && cenario[wl][wc+1] != 'B' && cenario[wl][wc+1] != 'C' && cenario[wl][wc+1] != 'W' && cenario[wl][wc+1] != 'S' && cenario[wl][wc+1] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl][wc+1] = 'W';
            wc++;
          }
        }
        if(vida < 100)
        {
          if(cenario[el+1][ec] == '.')
          {
            vida += buff;
          }
        }
        if(vida <= 100)
        {
          if(cenario[el+1][ec] == 'D')
          {
            vida -= dano;
            if(vida <= 0)
            {
              status = 1;
            }
          }
        }
        cenario[el][ec] = '_';
        cenario[el+1][ec] = 'E';
        el++;

      }
      break;

      // Movimentação de Eleven, andar pra esquerda no mundo invertido
      case 'a':
    // verifica obstáculos - eleven
      if(ec-1 >= 0 && cenario[el][ec-1] != 'T' && cenario[el][ec-1] != 'B' && cenario[el][ec-1] != 'C')
      {
        if(cenario[el][ec-1] == 'S')
        {
          status = 0;
        }
        // navegação aleatória de will
        andarw = rand()%4;
        if(andarw == 0)
        {
        // verificar obstáculos - will
          if(wl-1 >= 0 && cenario[wl-1][wc] != 'T' && cenario[wl-1][wc] != 'B' && cenario[wl-1][wc] != 'C' && cenario[wl-1][wc] != 'E' && cenario[wl-1][wc] != 'S' && cenario[wl-1][wc] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl-1][wc] = 'W';
            wl--;
          }
        }
        else if(andarw == 1)
        {
          if(wl+1 < 10 && cenario[wl+1][wc] != 'T' && cenario[wl+1][wc] != 'B' && cenario[wl+1][wc] != 'C' && cenario[wl+1][wc] != 'E' && cenario[wl+1][wc] != 'S' && cenario[wl+1][wc] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl+1][wc] = 'W';
            wl++;
          }
        }
        else if(andarw == 2)
        {
          if(wc-1 >= 0 && cenario[wl][wc-1] != 'T' && cenario[wl][wc-1] != 'B' && cenario[wl][wc-1] != 'C' && cenario[wl][wc-1] != 'E' && cenario[wl][wc-1] != 'S' && cenario[wl][wc-1] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl][wc-1] = 'W';
            wc--;
          }
        }
        else if(andarw == 3)
        {
          if(wc+1 < 10 && cenario[wl][wc+1] != 'T' && cenario[wl][wc+1] != 'B' && cenario[wl][wc+1] != 'C' && cenario[wl][wc+1] != 'E' && cenario[wl][wc+1] != 'S' && cenario[wl][wc+1] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl][wc+1] = 'W';
            wc++;
          }
        }
        if(vida < 100)
        {
          if(cenario[el][ec-1] == '.')
          {
            vida += buff;
          }
        }
        if(vida <= 100)
        {
          if(cenario[el][ec-1] == 'D')
          {
            vida -= dano;
            if(vida <= 0)
            {
              status = 1;
            }
          }
        }

        cenario[el][ec] = '_';
        cenario[el][ec-1] = 'E';
        ec--;

      }
      break;

      // Movimentação de Eleven, andar pra direita no mundo invertido
      case 'd':
    // verifica obstáculos - eleven
      if(ec+1 < 10 && cenario[el][ec+1] != 'T' && cenario[el][ec+1] != 'B' && cenario[el][ec+1] != 'C')
      {
        if(cenario[el][ec+1] == 'S')
        {
          status = 0;
        }
        // navegação aleatória de will
        andarw = rand()%4;
        if(andarw == 0)
        {
        // verificar obstáculos - will
          if(wl-1 >= 0 && cenario[wl-1][wc] != 'T' && cenario[wl-1][wc] != 'B' && cenario[wl-1][wc] != 'C' && cenario[wl-1][wc] != 'E' && cenario[wl-1][wc] != 'S' && cenario[wl-1][wc] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl-1][wc] = 'W';
            wl--;
          }
        }
        else if(andarw == 1)
        {
          if(wl+1 < 10 && cenario[wl+1][wc] != 'T' && cenario[wl+1][wc] != 'B' && cenario[wl+1][wc] != 'C' && cenario[wl+1][wc] != 'E' && cenario[wl+1][wc] != 'S' && cenario[wl+1][wc] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl+1][wc] = 'W';
            wl++;
          }
        }
        else if(andarw == 2)
        {
          if(wc-1 >= 0 && cenario[wl][wc-1] != 'T' && cenario[wl][wc-1] != 'B' && cenario[wl][wc-1] != 'C' && cenario[wl][wc-1] != 'E' && cenario[wl][wc-1] != 'S' && cenario[wl][wc-1] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl][wc-1] = 'W';
            wc--;
          }
        }
        else if(andarw == 3)
        {
          if(wc+1 < 10 && cenario[wl][wc+1] != 'T' && cenario[wl][wc+1] != 'B' && cenario[wl][wc+1] != 'C' && cenario[wl][wc+1] != 'W' && cenario[wl][wc+1] != 'S' && cenario[wl][wc+1] != 'D')
          {
            cenario[wl][wc] = '_';
            cenario[wl][wc+1] = 'W';
            wc++;
          }
        }
        if(vida < 100)
        {
          if(cenario[el][ec+1] == '.')
          {
            vida += buff;
          }
        }
        if(vida <= 100)
        {
          if(cenario[el][ec+1] == 'D')
          {
            vida -= dano;
            if(vida <= 0)
            {
              status = 1;
            }
          }
        }
        cenario[el][ec] = '_';
        cenario[el][ec+1] = 'E';
        ec++;
      }
      break;

    default:
      printf("\nComando inválido.");
      break;
    }
    system("@cls||clear"); 
  } while (status == 2);
    
    if(status == 1){
      printf("Morreu.");
    }
    else
    {
      printf("Você conseguiu sobreviver e resgatar Will!");
      printf("\nVida: %i\n", vida);
    }

  }
  return 0;
}