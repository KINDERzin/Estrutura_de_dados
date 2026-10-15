#include <stdlib.h>
#include <stdio.h>

#include "boolean.h"
#include "vetor_desordenado.h"

boolean eh_nulo_vd(struct VetorDesordenado* vetor) {
   return vetor->vetor == NULL;
}

void inicializa_vetor_vd(struct VetorDesordenado *vetor) {
   vetor->tamanho = 0;
   vetor->vetor = NULL;
}

void popular_vetor_vd(struct VetorDesordenado *vetor, int tamanho) {
   vetor->tamanho = tamanho;
   vetor->vetor = (int*) malloc(tamanho * sizeof(int));

   for(int i = 0; i < tamanho; i++)
      vetor->vetor[i] = rand();
}

void retornar_numeros_desordenados(struct VetorDesordenado* vetor, int numero, int *comparacoes) {
   for(int i = 0; i < vetor->tamanho; i++) {
      (*comparacoes)++;
      if(vetor->vetor[i] == numero) 
         return;
   }
}