namespace sort
{
  int particion(int* A , int inicio , int fin){
		int x = A[fin];
		int i = inicio - 1;
		int temp;
		for (int j = inicio ; j <= fin-1 ; j++){
			if (A[j] <= x){
				i++;
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		temp = A[i+1];
		A[i+1] = A[fin];
		A[fin] = temp;
		return i+1;
	}

	void ordenamientoRapido(int* A , int inicio , int fin){
		if (fin > inicio){
			int i = particion(A , inicio , fin);
			ordenamientoRapido(A , inicio , i-1);
			ordenamientoRapido(A , i+1 , fin);
		}
	}
  
  void quicksort(int *A, int n){
		ordenamientoRapido(A , 0 , n-1);
	}
} // namespace sort
