#include <stdio.h>
#include <stdlib.h>

void sort(int n, int *vet) {
  int tmp;

  for (int i = n-1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (vet[j] > vet[j+1]) {
        tmp = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = tmp;
      }
    }
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

  sort(n, vet);

  printf("Output: \n");
  for (int i = 0; i < n; i++) printf("%d ", vet[i]);
  printf("\n");

  return 0;
}