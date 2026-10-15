#include <stdlib.h>
#include <stdio.h>

#include "boolean.h"
#include "vetor_ordenado.h"

boolean eh_nulo_vo(struct VetorOrdenado* vetor) {
   return vetor->vetor == NULL;
}

void inicializa_vetor_vo(struct VetorOrdenado *vetor) {
   vetor->tamanho = 0;
   vetor->vetor = NULL;
}

void popular_vetor_vo(struct VetorOrdenado *vetor, int tamanho) {
   vetor->tamanho = tamanho;
   vetor->vetor = (int*) malloc(tamanho * sizeof(int));

   for(int i = 0; i < tamanho; i++)
      vetor->vetor[i] = rand();
}

void ordenar_vetor_vo(struct VetorOrdenado *vetor) {
   int aux;
   bool ordenado;

   for(int i = 0; i < vetor->tamanho; i++) {
      ordenado = true;
      for(int j = 0; j < vetor->tamanho - 1; j++)
         if(vetor->vetor[j] > vetor->vetor[j + 1]) {
            ordenado = false;
            aux = vetor->vetor[j];

            vetor->vetor[j] = vetor->vetor[j + 1];
            vetor->vetor[j + 1] = aux;
         }   
      
      if(ordenado) return;
   }      
}

void retornar_numeros_ordenados(struct VetorOrdenado* vetor, int numero, int *comparacoes) {
   // Tamanmho -> 0 até (n - 1)
   int esq = 0;
   int dir = vetor->tamanho - 1; 
   

   while (esq <= dir) {
      int meio = (esq + dir) / 2;

      if (numero == vetor->vetor[meio]) {
         (*comparacoes) += 1;
         return;
      }
      
      else if (numero < vetor->vetor[meio]) {
         (*comparacoes) += 2;
         dir = meio - 1;
      }
      else if (numero > vetor->vetor[meio]) {
         (*comparacoes) += 3;
         esq = meio + 1;
      }   
   }
}