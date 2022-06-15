#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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
  struct timeval start, stop;
  gettimeofday(&start, NULL);

  int n;
  int *vet;

  scanf("%d", &n);

  vet = malloc(n*sizeof(int));

  for (int i = 0; i < n; i++) scanf("%d", &vet[i]);

  sort(n, vet);

  gettimeofday(&stop, NULL);
  printf("Time: %f\n", (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec)); 

  return 0;
}