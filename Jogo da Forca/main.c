#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Letreiro.c"
#include "Jogadores.c"
#include "Jogo.c"

int main(void){
  int operacao = 0, Res = 2, cod=0, cond2 = 2, *cond = &cond2, temp;

  while(operacao != 4){
    system("clear");
    letreiro();

    if(Res == 1){
      ganhou();
    }else if(Res == 0){
      perdeu();
    }
    if(cond2 == 0){
      printf("          O CODIGO NAO EXISTE. TENTE NOVAMENTE\n\n\n");
      cond2 = 2;
    }

    if(Res == 2) printf("1 - JOGAR\n");
    if(Res != 2) printf("1 - JOGAR NOVAMENTE\n");
    printf("2 - CADASTRAR JOGADOR\n");
    printf("3 - RECORDES\n");
    printf("4 - SAIR\n");

    scanf("%d", &operacao);

    if(operacao == 1){
      system("clear");
      letreiro();
      printf("DIGITE DE SEU CODIGO. CASO VOCE NAO POSSUA CADASTRO, DIGITE 0.\n\n");
      ler_compara(cod, cond); /*Utilizada pra ler e printar*/
      scanf("%d", &cod);
      if(cod == 0){
        cadastra();
      }else{
        ler_compara(cod, cond); /*Utilizado para ler e comparar*/
        temp = cod;
        if(*cond == 0){
          cod = 0;
        }
        if(*cond == 1){
          cod = 0;
          Res = jogo(temp);
        }
      }
    }
    if(operacao == 2){
      system("clear");
      letreiro();
      cadastra();
    }
    if(operacao == 3){
      system("clear");
      letreiro();
      ler_compara(-1, cond);
      getchar();
      getchar();
    }

  }
  return 0;
}
