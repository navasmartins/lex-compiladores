#define TRUE              1
#define FALSE             0
#define TOK_NUM           0 
#define TOK_OP            1
#define TOK_PONT          2
#define ADICAO            0
#define SUBTRACAO         1
#define MULTIPLICACAO     2
#define DIVISAO           3
#define PARESQ            0
#define PARDIR            1

typedef struct{
  int tipo;
  int valor;
} Token; 

const char *ops = "+-*/";
char *codigo;
int length;
int position;

char le_caractere(void){
  char c;

  if (position < length) {
    c = codigo[position];
    position++;
  }
  else
    c = -1;
  return c;
}

int operador(char c){
  int res; 

  switch (c) {
  case '+':
    res = ADICAO;
    break;
    
  case '-':
    res = SUBTRACAO;
    break;

  case '*':
    res = MULTIPLICACAO;
    break;

  case '/':
    res = DIVISAO;
    break;

  default:
    res = -1;
  }
  return res;
}

void analise_lexica(char *prog)
{
  codigo = prog;
  length = strlen(codigo);
  position = 0;
}

Token *proximo_token(Token *tok)
{
  char c;
  char valor[200];
  int  vposition = 0;

  c = le_caractere();
  
  while (isspace(c)) {
    c = le_caractere();
  }

  if (isdigit(c)) {
    tok->tipo = TOK_NUM;
    valor[vposition++] = c;
    c = le_caractere();
    while (isdigit(c)) {
      valor[vposition++] = c;
      c = le_caractere();
    }

    position--;

    valor[vposition] = '\0';

    tok->valor = atoi(valor);
  }
  else if (strchr(ops, c) != NULL) {
    tok->tipo  = TOK_OP;
    tok->valor = operador(c);
  }
  else if (c == '(' || c == ')') {
    tok->tipo  = TOK_PONT;
    tok->valor = (c == '(' ? PARESQ : PARDIR);
  }
  else
    return NULL;

  return tok;
}

char *operador_str(int op)
{
  char *res;

  switch (op) {
  case ADICAO:
    res = "ADICAO";
    break;

  case SUBTRACAO:
    res = "SUBTRACAO";
    break;

  case MULTIPLICACAO:
    res = "MULTIPLICACAO";
    break;

  case DIVISAO:
    res = "DIVISAO";
    break;

  default:
    res = "NENHUM";
  }

  return res;
}

void imprime_token(Token *tok)
{
  printf("Tipo: ");
  switch (tok->tipo) {
  case TOK_NUM:
    printf("Numero \t -- Valor: %d\n", tok->valor);
    break;

  case TOK_OP:
    printf("Operador \t -- Valor: %s\n", operador_str(tok->valor));
    break;

  case TOK_PONT:
    printf("Pontuacao  -- Valor: %s\n", (tok->valor == PARESQ ? "PARESQ" : "PARDIR"));
    break;

  default:
    printf("ESTE TOKEM NAO FOI IDENTIFICADO NA REGRA DESTA LINGUAGEM\n");
  }
}


