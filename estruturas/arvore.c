typedef enum {
   false,
   true
} boolean;

typedef struct No {
   int numero;
   struct No* direita;
   struct No* esquerda;
} No;

typedef struct Arvore {
   struct No* raiz;
} Arvore;

void inicializar_arvore(struct Arvore *arv) {
   arv->raiz = NULL;
}

boolean ehNula(struct No* noAtual) {
   return noAtual == NULL;
}

struct No* criar_no(int numero) {
   No *novoNo = (struct No*) malloc(sizeof(struct No)); 

   novoNo->numero = numero;
   novoNo->direita = NULL;
   novoNo->esquerda = NULL;

   return novoNo;
}

No* inserirNo(struct No* noAtual, int numero) {
   if(ehNula(noAtual))
      noAtual = criarNo(numero);

   else if(noAtual->numero < numero)
      noAtual->esquerda = inserirNo(noAtual, numero);

   else if(noAtual->numero > numero)
      noAtual->direita = inserirNo(noAtual, numero);

   return noAtual;
}

struct No* antecessor(struct No* noAtual, struct No* noAntecessor) {
   if(noAntecessor->direita == NULL)
      noAntecessor->direita = antecessor(noAtual, noAntecessor->direita);

   else {
      No* aux;
      
      noAtual->numero = noAntecessor->numero;
      
      aux = noAntecessor;
      
      noAntecessor = noAntecessor->esquerda;
      
      free(aux);
   }

   return noAntecessor;
}

struct No* remocao(int numero, struct No* noAtual) {
   No* aux;

   if(noAtual == NULL)
      return NULL;

   else if(numero < noAtual->numero)
      noAtual->esquerda = remocao(numero, noAtual->esquerda);

   else if(numero > noAtual->direita)
      noAtual->direita = remocao(numero, noAtual->direita);

   else
      noAtual->esquerda = antecessor(noAtual, noAtual->esquerda);

   return noAtual;   
}

void popular_arvore(struct Arvore* arv) {
   struct No* n1 = (struct No*)malloc(sizeof(struct No));
   struct No* n2 = (struct No*)malloc(sizeof(struct No));
   struct No* n3 = (struct No*)malloc(sizeof(struct No));
   struct No* n4 = (struct No*)malloc(sizeof(struct No));
   struct No* n5 = (struct No*)malloc(sizeof(struct No));
   struct No* n6 = (struct No*)malloc(sizeof(struct No));
   struct No* n7 = (struct No*)malloc(sizeof(struct No));
   struct No* n8 = (struct No*)malloc(sizeof(struct No));

   n1->numero = 12; // Raiz
   n2->numero = 5;
   n3->numero = 19;
   n4->numero = 2;
   n5->numero = 8;
   n6->numero = 14;
   n7->numero = 23;
   n8->numero = 27;

   // Conectando os nós
   n1->esquerda = n2;
   n1->direita = n3;

   n2->esquerda = n4;
   n2->direita = n5;

   n3->esquerda = n6;
   n3->direita = n7;

   n4->esquerda = NULL;
   n4->direita = NULL;

   n5->esquerda = NULL;
   n5->direita = NULL;

   n6->esquerda = NULL;
   n6->direita = NULL;

   n7->esquerda = NULL;
   n7->direita = n8; 

   n8->esquerda = NULL;
   n8->direita = NULL;

   arv->raiz = n1;
}

void pre_ordem(struct No* noAtual) {
   if(noAtual !=  NULL) {
      printf("%d \n", noAtual->numero);
      pre_ordem(noAtual->esquerda);
      pre_ordem(noAtual->direita);
   }
}

void em_ordem(struct No* noAtual) {
   if(noAtual !=  NULL) {
      em_ordem(noAtual->esquerda);
      printf("%d \n", noAtual->numero);
      em_ordem(noAtual->direita);
   }
}

void pos_ordem(struct No* noAtual) {
   if(noAtual !=  NULL) {
      pos_ordem(noAtual->esquerda);
      pos_ordem(noAtual->direita);
      printf("%d \n", noAtual->numero);
   }
}

int main() {
   struct Arvore arvore;

   inicializar_arvore(&arvore);

   popular_arvore(&arvore);

   pre_ordem(&arvore);
   em_ordem(&arvore);
   pos_ordem(&arvore);
}