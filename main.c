#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int *vector; 
  int vector_size; 
  int temp_position;
  int i;
  int item_to_look_for;
  bool item_found = false;
  int vector_start, middle, vector_end;

  printf("========= Algoritimo de busca binaria =========");
  printf("\n");
  
  printf("Voce deve criar uma lista de numeros inteiros ordenados....");
  printf("\n\n");

  printf("Digite a quantidade de itens que deseja adicionar na lista: ");
  scanf("%d", &vector_size);

  vector = (int *) malloc(vector_size * sizeof(int));

  if (vector == NULL) {
    printf("Erro ao alocar o vetor!");
    return (1);
  } else {
    for (i = 0; i < vector_size; i++) {
      printf("Digite o item numero %d da lista: ", i + 1);
      scanf("%d", &temp_position);
      
      vector[i] = temp_position;
    }

    printf("Digite o elemento que deseja pesquisar na lista: ");
    scanf("%d", &item_to_look_for);

    vector_start = 0;
    vector_end = vector_size - 1;

    while (vector_start <= vector_end) {
      middle = (vector_start + vector_end) / 2;

      if (item_to_look_for == vector[middle]) {
        item_found = true;
        break;
      } else if (item_to_look_for < vector[middle]) {
        vector_end = middle - 1;
        continue;
      } else if (item_to_look_for > vector[middle]) {
        vector_start = middle + 1;
        continue;
      } else {
        item_found = false;
        break;
      }
    }

    if (item_found) {
      printf("O item %d foi encontrado na posicao %d da lista!", item_to_look_for, middle + 1);
    } else {
      printf("O item informado nao existe na lista!");
    }
    
    return 0;
  }



}