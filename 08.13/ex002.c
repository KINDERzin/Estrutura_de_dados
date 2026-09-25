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

No* apenas_folha(struct No* noAtual) {
   if(noAtual != NULL) {
      apenas_folha(noAtual->esquerda);
      if(noAtual->esquerda == NULL && noAtual->direita == NULL)
         printf("Nó folha: %d", noAtual->numero);
      apenas_folha(noAtual->direita);
   }
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

int main() {
   struct Arvore arvore;

   inicializar_arvore(&arvore);

   apenas_folha(&arvore.raiz);
}