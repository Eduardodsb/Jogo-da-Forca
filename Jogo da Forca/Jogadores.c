typedef struct _JOGADOR{
  char nome[80];
  int cod, rank;
  struct _JOGADOR *prox;
} JOGADOR;

void cadastrar(void);
void escrever(JOGADOR *jogador);
void ler_compara(int cod, int *cond);
void escrever_rank(JOGADOR *Jogador);
void atualiza_rank(int cod);

void ler_compara(int cod, int *cond){
  JOGADOR *Jogador, *p, *inicio = NULL, *p2;
  FILE *arq;

  arq = fopen("Jogadores.txt","a+");
  if (arq == NULL){
      puts("Erro de leitura");
      exit(1);
  }

  Jogador = (JOGADOR *) malloc(sizeof(JOGADOR));
  if(Jogador == NULL){
    puts("Erro - Nao foi possivel alocar");
    exit(1);
  }

  fscanf(arq,"%d %s %d", &Jogador->cod, Jogador->nome, &Jogador->rank);
  while(!feof(arq)){
    p = Jogador;
    Jogador = (JOGADOR *) malloc(sizeof(JOGADOR));
    if(Jogador == NULL){
      puts("Erro - Nao foi possivel alocar");
      exit(1);
    }
    fscanf(arq,"%d %s %d", &Jogador->cod, Jogador->nome, &Jogador->rank);
    if(inicio == NULL){
      inicio = p;
      p2 = p;
    }else{
      p2->prox = p;
      p2 = p;
      p->prox = NULL;
    }
  }
  fclose(arq);
  if(cod == -1){
    escrever_rank(inicio);
    return;
  }
  if(cod == 0){
    escrever(inicio);
    *cond = 2;
  }else{
    Jogador = inicio;
    while(Jogador->prox != NULL){
      if(cod == Jogador->cod){
        *cond = 1;
        return;
      }
      Jogador = Jogador->prox;
    }
    if(cod == Jogador->cod){
      *cond = 1;
      return;
    }
    *cond = 0;
  }
}

void escrever(JOGADOR *Jogador){
  printf("JOGADORES CADASTRADOS\n_________________\n");
  while(Jogador->prox != NULL){
    printf("Código: %d - Nome: %s\n", Jogador->cod, Jogador->nome);
    Jogador = Jogador->prox;
  }
  printf("Código: %d - Nome: %s\n", Jogador->cod, Jogador->nome);
}

void escrever_rank(JOGADOR *Jogador){
  JOGADOR temp, *inicio, *J;
  int i, j, cont=0;
  inicio = Jogador;
  printf("RANK\n_________________\n");

  while(Jogador->prox != NULL){
    cont++;
    Jogador = Jogador->prox;
  }
  cont++;

  J = (JOGADOR *) malloc(sizeof(JOGADOR)*cont);
  Jogador = inicio;
  for(i=0; i < cont; i++){
    J[i] = *Jogador;
    Jogador = Jogador->prox;
  }

  for(i=0; i<cont; i++){
    for(j=i+1; j<cont; j++){
      if(J[i].rank < J[j].rank){
        temp = J[i];
        J[i] = J[j];
        J[j] = temp;
      }
    }
  }

  for(i=0; i<cont; i++){
    printf("Código: %d - Nome: %s - Rank: %d\n", J[i].cod, J[i].nome, J[i].rank);
  }
}

void cadastra(void){
    int cod;
    int rank;
    char nome[80];
    FILE *arq;

    arq = fopen("Jogadores.txt","a+");
    if (arq == NULL){
        puts("Erro de leitura");
        exit(1);
    }

    while (fscanf(arq, "%d %s %d", &cod, nome, &rank) != EOF){}

    cod++;

    puts("POR FAVOR, INSIRA O APELIDO QUE GOSTARIA QUE SEJA CADASTRADO.");
    scanf("%s", nome);
    do {} while(getchar() != '\n');

    fprintf(arq, "%d\n", cod);
    fprintf(arq, "%s\n", nome);
    fprintf(arq, "%d\n", 0);

    fclose(arq);
    return;
}

void atualiza_rank(int cod){
  JOGADOR *Jogadorr, *p, *inicio = NULL, *inicio2,*p2;
  FILE *arq;
  int temp;

  arq = fopen("Jogadores.txt","r+");
  if (arq == NULL){
      puts("Erro de leitura");
      exit(1);
  }

  Jogadorr = (JOGADOR *) malloc(sizeof(JOGADOR));
  if(Jogadorr == NULL){
    puts("Erro - Nao foi possivel alocar");
    exit(1);
  }

  fscanf(arq,"%d %s %d", &Jogadorr->cod, Jogadorr->nome, &Jogadorr->rank);
  while(!feof(arq)){
    p = Jogadorr;
    Jogadorr = (JOGADOR *) malloc(sizeof(JOGADOR));
    if(Jogadorr == NULL){
      puts("Erro - Nao foi possivel alocar");
      exit(1);
    }
    fscanf(arq,"%d %s %d", &Jogadorr->cod, Jogadorr->nome, &Jogadorr->rank);
    if(inicio == NULL){
      inicio = p;
      p2 = p;
    }else{
      p2->prox = p;
      p2 = p;
      p->prox = NULL;
    }
  }
  inicio2 = inicio;

  while(inicio->prox != NULL){
    if(cod == inicio->cod){
      temp = inicio->rank;
      temp = (temp+100);
      inicio->rank = temp;
    }
    inicio = inicio->prox;
  }
  if(cod == inicio->cod){
    temp = inicio->rank;
    temp = (temp+100);
    inicio->rank = temp;
  }

  rewind(arq);
  inicio = inicio2;

  while(inicio->prox != NULL){
    fprintf(arq, "%d\n", inicio->cod);
    fprintf(arq, "%s\n", inicio->nome);
    fprintf(arq, "%d\n", inicio->rank);
    inicio = inicio->prox;
  }
  fprintf(arq, "%d\n", inicio->cod);
  fprintf(arq, "%s\n", inicio->nome);
  fprintf(arq, "%d\n", inicio->rank);


  fclose(arq);
}
