#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "token.h"

int main(void){
	
  char  row[200], *result;
  Token tokenV;
  FILE *arq;
  int countRows = 1;

  printf("Analisador Lexico - Calculadora\n");
  
  arq = fopen("source.txt", "r");
  
  if (!arq) {
    printf("O arquivo de entrada não existe");

    return 0;
  }

  while (!feof(arq)) {
    // lê uma linha arquivo de entrada com até 100 caracteres
    result = fgets(row, 100, arq);
    
    if (result) {
      analise_lexica(row);
      
      printf("\n===== Resultados de Analise da linha:%d =====\n", countRows);
      while (proximo_token(&tokenV) != NULL) {
        imprime_token(&tokenV);
      }
    }
    countRows++;
  }

  printf("\n");

  return 0;
}

