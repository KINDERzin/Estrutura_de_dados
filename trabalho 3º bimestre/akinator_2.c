typedef struct No {
   char texto[255];
   struct No *sim;
   struct No *nao;
} No;

typedef struct Arvore {
   struct No *raiz;
} Arvore;

void inicializar_arvore(struct Arvore *arvore) {
   arvore->raiz = NULL;
}

int eh_nulo(struct Arvore *arvore) {
   return arvore->raiz == NULL;
}

No* criarNo(char texto[255]) {
   struct No *novoNo = (struct No *)malloc(sizeof(struct No));
   
   strcpy(novoNo->texto, texto);
   novoNo->sim = NULL;
   novoNo->nao = NULL;
   
   return novoNo;
}

void popular_arvore(struct Arvore *arvore) {
    // Raiz 
    arvore->raiz = criarNo("É um mamífero?");

    // Ramo do sim (Mamíferos)
    struct No *mamiferos = criarNo("Vive na água?");
    arvore->raiz->sim = mamiferos;

    // Mamíferos Aquáticos
    struct No *mamAquaticos = criarNo("É conhecido por fazer saltos no mar?");
    mamiferos->sim = mamAquaticos;
    mamAquaticos->sim = criarNo("Golfinho");
    mamAquaticos->nao = criarNo("Baleia Orca");

    // Mamíferos Terrestres
    struct No *mamTerrestres = criarNo("É um animal doméstico?");
    mamiferos->nao = mamTerrestres;

    // Domésticos
    struct No *domesticos = criarNo("Ele late?");
    mamTerrestres->sim = domesticos;
    domesticos->sim = criarNo("Cachorro");
    domesticos->nao = criarNo("Gato");

    // Selvagens
    struct No *selvagens = criarNo("Tem tromba?");
    mamTerrestres->nao = selvagens;
    selvagens->sim = criarNo("Elefante");
    selvagens->nao = criarNo("Leão");


    // Ramo do não (Não Mamíferos)
    struct No *naoMamiferos = criarNo("É uma ave?");
    arvore->raiz->nao = naoMamiferos;

    // Aves
    struct No *aves = criarNo("Sabe voar?");
    naoMamiferos->sim = aves;
    aves->sim = criarNo("Águia");
    aves->nao = criarNo("Pinguim");

    // Répteis / Peixes
    struct No *outros = criarNo("Tem pernas?");
    naoMamiferos->nao = outros;
    outros->sim = criarNo("Jacaré");

    struct No *semPernas = criarNo("Vive no mar?");
    outros->nao = semPernas;
    semPernas->sim = criarNo("Tubarão");
    semPernas->nao = criarNo("Cobra");
}

void jogar(struct Arvore *arvore) {
   struct No *noAtual = arvore->raiz;
   char resposta;

   if(eh_nulo(arvore)) {
      printf("A árvore de conhecimento está vazia. Por favor, adicione um animal para começar.\n");
      return;
   }

   while(noAtual != NULL) {
      // Se for nó folha, mostra o animal
      if(noAtual->sim == NULL && noAtual->nao == NULL) {
         printf("%s\n", noAtual->texto);
         printf("Foi esse o animal que você pensou?\nDigite 's' para sim e 'n' para não: ");
         scanf(" %c", &resposta);
      
         // Valida a resposta do usuário
         while(resposta != 's' && resposta != 'n') {
            printf("Resposta inválida. Digite 's' para sim e 'n' para não: ");
            scanf(" %c", &resposta);
         }

         if(resposta == 's') {
            printf("Então eu acertei!\n");
            break;
         }   
         else {
            char animal[100];
            char pergunta[255];
            // Animal
            printf("Então eu errei! Qual animal você pensou?\n");
            scanf(" %[^\n]", animal);
            // Pergunta
            printf("Qual pergunta você gostaria de fazer para distinguir %s de %s?\n", animal, noAtual->texto);
            scanf(" %[^\n]", pergunta);

            // Ajuda na rotação da árvore
            struct No *auxiliar = noAtual;
            // Cria novos nós para o animal
            struct No *animalNovo = criarNo(animal);
            // e a pergunta
            struct No *animalAntigo = criarNo(noAtual->texto);

            // Atualiza o nó atual para a nova pergunta
            strcpy(noAtual->texto, pergunta);
            // Recebe o animal novo e o anterior
            noAtual->sim = animalNovo;
            noAtual->nao = animalAntigo;
         }

         break;
      }
      // Se não for nó folha, faz a pergunta
      else {
         printf("%s\n", noAtual->texto);
         printf("Digite 's' para sim e 'n' para não: ");
         scanf(" %c", &resposta);
      }

      // Valida a resposta do usuário
      while(resposta != 's' && resposta != 'n') {
         printf("Resposta inválida. Digite 's' para sim e 'n' para não: ");
         scanf(" %c", &resposta);
      }

      // Movimenta para o próximo nó com base na resposta do usuário
      if(resposta == 's')
         noAtual = noAtual->sim;

      else if(resposta == 'n') 
         noAtual = noAtual->nao;
   }
}

int main() {
   struct No no;
   struct Arvore raiz;

   char jogarNovamente;

   inicializar_arvore(&raiz);
   popular_arvore(&raiz);
   
   do {
      printf("Bem-vindo ao jogo de adivinhação de animais!\n");
      printf("Pense em um animal e eu tentarei adivinhar.\n");
      
      jogar(&raiz);

      printf("Deseja jogar novamente? (s/n): ");
      scanf(" %c", &jogarNovamente);
      
      while(jogarNovamente != 's' && jogarNovamente != 'n') {
         printf("Resposta inválida. Digite 's' para sim e 'n' para não: ");
         scanf(" %c", &jogarNovamente);
      }
   }  while(jogarNovamente == 's');

   printf("Obrigado por jogar! Até a próxima!\n");
}