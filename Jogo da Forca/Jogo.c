#define TAM 80

void gera_palavra(FILE *p, char *palavra);
int adivinha_palavra(char *letras, char *palavra, int *erradas);
int chuta_palavra(char *palavra);
int letras_digitadas(char *letras,char *adivinha,int num);
void forca(int erradas);
void categoria(char *cat);

int jogo(int cod){
  FILE *arq;
  char *palavra, *letras, *cat;
  int erradas = 0, Res;


  cat = (char *) malloc(sizeof(char) * TAM);
  if(cat == NULL){
      puts("Nao foi possivel alocar espaço na memoria");
      exit(1);
  }

  categoria(cat);

  arq = fopen(cat, "r");
  if (arq == NULL){
      puts("Erro de leitura");
      exit(1);
  }

  palavra = (char *) malloc(sizeof(char) * TAM);
  if(palavra == NULL){
      puts("Nao foi possivel alocar espaço na memoria");
      exit(1);
  }

  letras = (char *) calloc(40, sizeof(char));
  if(letras == NULL){
      puts("Nao foi possivel alocar espaço na memoria");
      exit(1);
  }
  gera_palavra(arq, palavra);
  Res= adivinha_palavra(letras,palavra, &erradas);

  if(Res == 1){
  atualiza_rank(cod);
  }
  return Res;
  }

  void categoria(char *cat){
    system("clear");
    letreiro();
    int num = 0;
    while(num == 0){
      printf("\nESCOLHA UMA CATEGORIA!\n");
      printf("1 - Animal\n");
      printf("2 - Comidas\n");
      printf("3 - Países\n");
      printf("4 - Objetos\n");
      printf("5 - Profissoes\n");

      scanf("%d", &num);
      do{} while (getchar() != '\n');

      if(num == 1){
        strcpy(cat,"Animal.txt");
      }
      if(num == 2){
        strcpy(cat,"Comidas.txt");
      }
      if(num == 3){
        strcpy(cat,"Paises.txt");
      }
      if(num == 4){
        strcpy(cat,"Objetos.txt");
      }
      if(num == 5){
        strcpy(cat,"Profissoes.txt");
      }
    }
  }

  void gera_palavra(FILE *p, char *palavra){
      char temp[TAM];
      int cont = 1;

      srand(time(NULL));

      /*Descobrir quantidade de linhas*/
      fscanf(p,"%s",temp);
      while(!feof(p)){
        fscanf(p,"%s",temp);
        cont++;
      }
      rewind(p);
      /*fim da descoberta*/

      int num_rand = rand()%cont, i;

      for (i = 0; i <= num_rand; i++){
          fgets(palavra, TAM, p);
          palavra[strlen(palavra)-2]= '\0';
      }
  }

  int adivinha_palavra(char *letras, char *palavra, int *erradas){
      char adivinha;
      char *esboco;
      int j, acertos = 0, cont =0;

      esboco = (char *) calloc(TAM, sizeof(char));
      if(esboco == NULL){
          puts("Nao foi possivel alocar espaço na memoria");
          exit (1);
      }

      system("clear");
      letreiro();
      printf("DIGITE UMA LETRA\n\n");
      /*printf("%s\n\n", palavra);*//*Utilizado para controle*/
      memset(esboco, '_', strlen(palavra));

      printf("%s\n\n", esboco);

      while(1){
          adivinha = getchar();
          do{} while (getchar() != '\n');
          printf("\n");
          system("clear");
          letreiro();

          for (j = 0; (unsigned)j < strlen(palavra); j++){
              if (adivinha == palavra[j]){
                  esboco[j] = adivinha;
                  acertos++;
                  cont++;
              }

              if (strcmp(esboco, palavra) == 0){
                  return 1;
              }
          }

          if(cont != 0){
            forca(*erradas);
            cont =0;
          }

          if (acertos == 0){
            if(letras_digitadas(letras, &adivinha, 1) == 0){
              (*erradas)++;
              forca(*erradas);
            }else{
            forca(*erradas);
            }
          }

          if (*erradas == 8){
              return 0;
          }

          printf("%s\n\n\n", esboco);
          letras_digitadas(letras, &adivinha, 0);
          acertos = 0;

      }
  }

  int letras_digitadas(char *letras, char *adivinha, int num){
      char recebe_letra[4];
      int i, contador = 0;

      recebe_letra[0] = *adivinha;
      recebe_letra[1] = '\0';

      strcat(recebe_letra, ", ");

      if (strlen(letras) == 0){
          strcat(letras, recebe_letra);
          if(num == 0){
          puts("LETRAS DIGITADAS");
          printf("%s\n", letras);
          }
          return 0;
      }else{
        for (i = 0; (unsigned)i < strlen(letras); i++){
          if (letras[i] == *adivinha){
            if(num == 0){
              printf("VOCE JA DIGITOU A LETRA: \'%c\'!\n", *adivinha);
              printf("%s\n", letras);
            }
            contador++;
            return 1;
          }
        }
        if (contador == 0){
          strcat(letras, recebe_letra);
          if(num == 0){
          puts("LETRAS DIGITADAS");
          printf("%s\n", letras);
          }
          return 0;
        }
      }
      return 0;
  }


  void forca(int erradas){
      if (erradas == 1){
          printf("_________\n");
          printf("|   |\n");
          printf("|\n");
          printf("|\n");
          printf("|\n");
          printf("|\n");
          printf("|\n");
      }

      else if (erradas == 2){
          printf("_________\n");
          printf("|   |\n");
          printf("|   o\n");
          printf("|\n");
          printf("|\n");
          printf("|\n");
          printf("|\n");
      }

      else if (erradas == 3){
          printf("_________\n");
          printf("|   |\n");
          printf("|   o\n");
          printf("|   |\n");
          printf("|\n");
          printf("|\n");
          printf("|\n");
      }

      else if (erradas == 4){
          printf("_________\n");
          printf("|   |\n");
          printf("|   o\n");
          printf("|   |\n");
          printf("|  /| ");
          printf("\n|\n");
          printf("|\n");
          printf("|\n");
      }
      else if (erradas == 5){
          printf("_________\n");
          printf("|   |\n");
          printf("|   o\n");
          printf("|   |\n");
          printf("|  /|\\ ");
          printf("\n|\n");
          printf("|\n");
          printf("|\n");
      }

      else if (erradas == 6){
          printf("_________\n");
          printf("|   |\n");
          printf("|   o\n");
          printf("|   |\n");
          printf("|  /|\\ ");
          printf("\n|   |\n");
          printf("|\n");
          printf("|\n");
      }
      else if (erradas == 7){
          printf("_________\n");
          printf("|   |\n");
          printf("|   o\n");
          printf("|   |\n");
          printf("|  /|\\ ");
          printf("\n|   |\n");
          printf("|  /\n");
          printf("|\n");
          printf("\n");
      }
      else if (erradas == 8){
          printf("_________\n");
          printf("|   |\n");
          printf("|   o\n");
          printf("|   |\n");
          printf("|  /|\\ ");
          printf("\n|   |\n");
          printf("|  / \\ ");
          printf("\n|\n");
          printf("\n");
      }
  }
/*
  int chuta_palavra(char *palavra){
      char *chuta_palavra;
      chuta_palavra = (char *) calloc(TAM, sizeof(char));
      fgets(chuta_palavra, 20, stdin);
      chuta_palavra[strlen(palavra)-1]= '\0';

      if (strcmp(chuta_palavra, palavra) == 0){
          puts("Voce acertou a palavra!");
          return 0;
      }
      else
          return 1;
  }
*/
