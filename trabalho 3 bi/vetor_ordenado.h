#ifndef VETOR_ORDENADO_H
#define VETOR_ORDENADO_H

typedef enum {
   false, true
} boolean;

typedef struct VetorVo {
   int tamanho;
   int* vetor;
} VetorVo;

boolean eh_nulo_vo(struct VetorVo* vetor);
void inicializa_vetor_vo(struct VetorVo *vetor);
void popular_vetor_vo(struct VetorVo *vetor, int tamanho);
void ordenar_vetor_vo(struct VetorVo *vetor);
void retornar_numeros_ordenados(struct VetorVo* vetor, int numero, int *comparacoes);

#endif