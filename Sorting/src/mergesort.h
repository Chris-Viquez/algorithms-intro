#include <limits>

namespace sort
{
  void mezcla(int *A , int p , int q , int r) {
		int n1 = q - p + 1;
		int n2 = r - q;
		int L[n1 + 1];
		int R[n2 + 1];

		for (int i = 0 ; i < n1 ; i++) {
			L[i] = A[p + i];
		}
		for (int j = 0 ; j < n2 ; j++) {
			R[j] = A[q + 1 + j];
		}
		L[n1] = std::numeric_limits<int>::max();
		R[n2] = std::numeric_limits<int>::max();

		int i = 0;
		int j = 0;
		for (int k = p ; k <= r ; k++) {
			if (L[i] <= R[j]) {
				A[k] = L[i];
				i = i + 1;
			}
			else {
				A[k] = R[j];
				j = j + 1;
			}
		}
	}

	void ordenamientoMezcla(int *A , int p , int r) {
		if (p < r) {
			int q = (p + r)/2;

			ordenamientoMezcla(A , p , q);
			ordenamientoMezcla(A , q+1 , r);

			mezcla(A , p, q , r);
		}
	}
  
  void mergesort(int *A, int n) {
		ordenamientoMezcla(A , 0 , n-1);
	}
} // namespace sort
