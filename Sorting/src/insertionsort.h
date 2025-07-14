namespace sort
{
  void insercion(int *A , int n){
		int key;
		int j;

		for (int i = 1; i < n ; i++) {
			key = A[i];
			j = i-1;
			while (j >= 0 && A[j] > key ) {
				A[j + 1] = A[j];
				j = j - 1;
			}
			A[j + 1] = key;

		}
	}
} // namespace sort
