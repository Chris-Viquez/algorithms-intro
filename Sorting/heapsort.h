namespace sort 
{
  void corregirCima(int* A , int n, int k){
		int l = 2*k + 1;
		int r = 2*(k+1);
		int j;

		if (l < n && A[l] > A[k]){
			j = l;
		}
		else {
			j = k;
		}

		if (r < n && A[r] > A[j]){
			j = r;
		}

		int temp;
		if (k != j) {
			temp = A[k];
			A[k] = A[j];
			A[j] = temp;

			corregirCima(A , n , j);
		}
	}
	
	void monticulizar(int* A , int n){
		for (int k = (n-1)/2 ; k >= 0 ; k--) {
			corregirCima(A , n , k);
		} 
	}

	int extraerMaximo(int* A , int n){
		int m = A[0];
		A[0] = A[n-1];
		corregirCima(A, n , 0);
		return m;
	}

  void heapsort(int *A, int n){
		monticulizar(A , n);
		while (n>0){
			A[n-1] = extraerMaximo(A,n-1);
			n--;
		}
	}
} // namespace sort