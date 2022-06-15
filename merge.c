#include <stdio.h>
#include <stdlib.h>

void sort(int *vet, int first, int middle, int last) {
  int *aux = malloc((last - first + 1) * sizeof(int));

  int i = first;
  int j = middle + 1;
  int k = 0;

  while (i <= middle && j <= last) {
    if (vet[i] <= vet[j]) {
      aux[k] = vet[i];
      i++;
    } else {
      aux[k] = vet[j];
      j++;
    }

    k++;
  }

  while (i <= middle) {
    aux[k] = vet[i];
    i++;
    k++;
  }

  while (j <= last) {
    aux[k] = vet[j];
    j++;
    k++;
  }

  for (int i = first; i <= last; i++) {
    vet[i] = aux[i - first];
  }

  free(aux);
}

void merge(int *vet, int first, int last) {
  int middle;

  if (first < last) {
    middle = (first + last) / 2;

    merge(vet, first, middle);
    merge(vet, middle + 1, last);
    sort(vet, first, middle, last);
  }
}

int main() {
  int n;
  int *vet;

  scanf("%d", &n);

  vet = malloc(n*sizeof(int));

  for (int i = 0; i < n; i++) scanf("%d", &vet[i]);

  printf("Input: \n");
  for (int i = 0; i < n; i++) printf("%d ", vet[i]);
  printf("\n");

  merge(vet, 0, n - 1);

  printf("Output: \n");
  for (int i = 0; i < n; i++) printf("%d ", vet[i]);
  printf("\n");

  return 0;
}