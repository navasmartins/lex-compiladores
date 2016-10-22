#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "token.h"

int main(void){
	
  char  entrada[200];
  Token tokenV;

  printf("Analisador Lexico - Calculadora\n");
  
  printf("Insira uma expressao aritimetica: \n");
  fgets(entrada, 200, stdin);

  analise_lexica(entrada);

  printf("\n===== Resultados da Analise=====\n");

  while (proximo_token(&tokenV) != NULL) {
    imprime_token(&tokenV);
  }

  printf("\n");

  return 0;
}
