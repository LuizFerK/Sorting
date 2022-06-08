#include <stdio.h>
#include <stdlib.h>

void sort(int *vet, int len){
  for (int i = 1; i < len; i++) {
    int temp = vet[i];
    int j = i-1;

    while(j >= 0 && vet[j] > temp) {
      vet[j+1] = vet[j];
      j--;
    }
    
    vet[j+1] = temp;
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

  sort(vet, n);

  printf("Output: \n");
  for (int i = 0; i < n; i++) printf("%d ", vet[i]);
  printf("\n");

  return 0;
}