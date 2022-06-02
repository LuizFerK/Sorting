#include <stdio.h>
#include <stdlib.h>

void sort(int *vet, int first, int last){
   int i, j, pivot, tmp;

   if(first < last) {
    pivot = first;
    i = first;
    j = last;

    while(i < j) {
      while (vet[i] <= vet[pivot] && i < last) i++;
      while (vet[j] > vet[pivot]) j--;

      if (i < j) {
        tmp = vet[i];
        vet[i] = vet[j];
        vet[j] = tmp;
      }
    }

    tmp = vet[pivot];
    vet[pivot] = vet[j];
    vet[j] = tmp;

    sort(vet, first, j - 1);
    sort(vet, j + 1, last);
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

  sort(vet, 0, n - 1);

  printf("Output: \n");
  for (int i = 0; i < n; i++) printf("%d ", vet[i]);
  printf("\n");

  return 0;
}