#include <stdio.h>

int menor_numero(int vetor[], int tamanho, int posicao) {
   // Pode ser que a posicação passada já seja o menor número
   int menor = posicao;

   for(int i = posicao + 1; i < tamanho; i++)
      if(vetor[i] < vetor[posicao])
         menor = i;

   return menor;
}

void trocar(int* a, int* b) {
   int aux = *a;

   *a = *b;
   *b = aux;
}

void selection_sort(int vetor[], int tamanho) {
   int posicao_menor;

   for(int i = 0; i < tamanho - 1; i++) {
      posicao_menor = menor_numero(vetor, tamanho, i);
      trocar(&vetor[i], &vetor[posicao_menor]);
   }
}

int main() {

   int vetor_teste[5];

   printf("Insira 5 numeros:\n");
   for(int i = 0; i < 5; i++) {
      printf("Numero %d: ", (i + 1));
      scanf("%d", &vetor_teste[i]);
   }

   printf("\nVETOR INSERIDO\n");
   for(int i = 0; i < 5; i++)
      printf("%d ", vetor_teste[i]);
   printf("\n");

   selection_sort(vetor_teste, 5);

   printf("\nVETOR ORDENADO\n");
   for(int i = 0; i < 5; i++) {
      printf("%d ", vetor_teste[i]);
   }
   printf("\n");

   return 0;
}