namespace sort 
{
  void seleccion(int *A , int n) {
    int menor;
    int temp;
    for (int i = 0; i < n-1 ; i++) {
      menor = i;
      for (int j = i+1 ; j < n ; j++) {
        if (A[j] < A[menor]) {
          menor = j;
        }
      }
      temp = A[i];
      A[i] = A[menor];
      A[menor] = temp;
    }
  }
} // namespace sort