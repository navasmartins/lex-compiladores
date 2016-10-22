#define TRUE            1
#define FALSE           0
#define TOK_NUM         0 
#define TOK_OP          1
#define TOK_PONT        2
#define SOMA            0
#define SUB             1
#define MULT            2
#define DIV             3
#define PARESQ          0
#define PARDIR          1

typedef struct{
  int tipo;
  int valor;
} Token; 

const char *ops = "+-*/";
char *codigo;
int tamanho;
int pos;

char le_caractere(void){
  char c;

  if (pos < tamanho) {
    c = codigo[pos];
    pos++;
  }
  else
    c = -1;
  return c;
}

int operador(char c){
  int res; 

  switch (c) {
  case '+':
    res = SOMA;
    break;
    
  case '-':
    res = SUB;
    break;

  case '*':
    res = MULT;
    break;

  case '/':
    res = DIV;
    break;

  default:
    res = -1;
  }
  return res;
}

void analise_lexica(char *prog)
{
  codigo = prog;
  tamanho = strlen(codigo);
  pos = 0;
}

Token *proximo_token(Token *tok)
{
  char c;
  char valor[200];
  int  vpos = 0;

  c = le_caractere();
  
  while (isspace(c)) {
    c = le_caractere();
  }

  if (isdigit(c)) {
    tok->tipo = TOK_NUM;
    valor[vpos++] = c;
    c = le_caractere();
    while (isdigit(c)) {
      valor[vpos++] = c;
      c = le_caractere();
    }

    pos--;

    valor[vpos] = '\0';

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
  case SOMA:
    res = "SOMA";
    break;

  case SUB:
    res = "SUB";
    break;

  case MULT:
    res = "MULT";
    break;

  case DIV:
    res = "DIV";
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
    printf("TIPO DE TOKEN DESCONHECIOO\n");
  }
}


