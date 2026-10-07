#ifndef VETOR_DESORDENADO_H
#define VETOR_DESORDENADO_H

typedef enum {
   false, true
} boolean;

typedef struct VetorVd {
   int tamanho;
   int* vetor;
} VetorVd;

boolean eh_nulo_vd(struct VetorVd* vetor);
void inicializa_vetor_vd(struct VetorVd *vetor);
void popular_vetor_vd(struct VetorVd *vetor, int tamanho);
void retornar_numeros_desordenados(struct VetorVd* vetor, int numero, int *comparacoes);

#endif