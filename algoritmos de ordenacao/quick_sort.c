#include <stdio.h>

void troca(int* a, int* b) {
   int aux = *a;

   *a = *b;
   *b = aux;
}

int particiona(int vetor[], int inicio, int fim) {
   int aux = inicio;

   for(int i = inicio + 1; i <= fim; i++)
      if(vetor[i] < vetor[inicio]) {
         aux++;
         troca(&vetor[i], &vetor[aux]);
      }

   troca(&vetor[inicio], &vetor[aux]);
   
   return aux;
}

void quick_sort(int vetor[], int inicio, int fim) {
   if(inicio < fim) {
      int p = particiona(vetor, inicio, fim);
      quick_sort(vetor, inicio, p - 1);
      quick_sort(vetor, p + 1, fim); 
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

   quick_sort(vetor_teste, 0, 4);

   printf("\nVETOR ORDENADO\n");
   for(int i = 0; i < 5; i++)
      printf("%d ", vetor_teste[i]);
   printf("\n");

   return 0;
}