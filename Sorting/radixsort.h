#include <cmath>

namespace sort
{
  void ordenamientoConteo(int* A , int n , int r , int div , int* B){
		r = pow(10,r);
		div = pow(10,div);

		int max = (A[0] % r) / div; // 27 , 38 , -39
		int min = (A[0] % r) / div;
		int temp;

		for (int i = 1 ; i < n ; i++){
			temp = (A[i] % r) / div;
			if (temp > max){
				max = temp;
			}
			if (temp < min){
				min = temp;
			}
		}
		max = abs(max);
		min = abs(min);

		int k = max + min + 1 + 1;
		int* C = new int[k];

		for (int i = 0 ; i < k ; i++){
			C[i] = 0;
		}
		
		for (int j = 0 ; j < n ; j++){
			temp = (A[j] % r) / div;
			C[temp + min]++; // -8 + min(8) + 1 = 1
		}

		for (int i = 1 ; i < k ; i++){
			C[i] += C[i - 1];
			
		}

		for (int j = n-1 ; j >= 0 ; j--){
			temp = (A[j] % r) / div;
			B[C[temp + min] - 1] = A[j];
			C[temp + min]--;
		}
	}

  void radixsort(int *A, int n){
		int max = A[0];
		int min = A[0];
		for (int i = 1 ; i < n ; i++){
			if (A[i] > max){
				max = A[i];
			}
			if (A[i] < min){
				min = A[i];
			}
		}
		max = abs(max);
		min = abs(min);

		int maxDigitNum; // numero que tiene mas digitos
		if (max >= min){
			maxDigitNum = max;
		}
		else {
			maxDigitNum = min;
		}

		float b = 0; // mayor catidad de digitos necesaria para un numero en la lista
		int k = 1;
		while (maxDigitNum/k >= 1){ // 89 34 23
			b++;
			k *= 10;
		}

		int r = log10(n); // diviciones de b (digitos)
		if (r < 1){
			r = 1;
		}

		int d = ceil(b/r); // cantidad de diviciones / veces que se corre el ordenamiento por conteo
	
		int* B = new int[n]; // arreglo que usa conteo para guardar A ordenado
	
		for (int i = 1 ; i <= d; i++){
			ordenamientoConteo(A , n , r*i , r*(i-1) , B);
			for (int j = 0 ; j < n ; j++){
				A[j] = B[j];
			}
		}
	}
} // namespace sort
