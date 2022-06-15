#include <stdio.h>
#include <stdlib.h>

void sort(int n, int *vet) {
  int min;
 
  for (int i = 0; i < n - 1; i++) {
    min = i;
    
    for (int j = i+1; j < n; j++) {
      if (vet[j] < vet[min]) {
        min = j;
      }
    }

    if (vet[min] != vet[i]) {
      int tmp = vet[i];
      vet[i] = vet[min];
      vet[min] = tmp;
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