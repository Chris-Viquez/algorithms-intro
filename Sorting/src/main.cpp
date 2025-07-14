#include "selectionsort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"
#include "radixsort.h"

#include <iostream>
#include <random>
#include <chrono>
#include <sys/time.h>
#include <ctime>

using namespace std; 
using namespace chrono;


void printArray(int *A , int n){
    cout << "Lista:" << endl;
    for (int i = 0 ; i < n ; i++){
        cout << A[i] << " , ";
    }
    cout << endl;
}

int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<unsigned long long> dis(-1000000, 1000000);

    
    int n = 100000;
    int* A = new int[n];
    for (int i = 0 ; i < n ; i++) {
        A[i] = dis(gen);
    }

    //printArray(A,n);

    //tiempo y ordenamiento
    uint64_t time1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count();
    sort::radixsort(A , n);
    uint64_t time2 = duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count();

    //printArray(A,n);

    for (int i = 1 ; i < n ; i++) {
        if (A[i-1] > A[i]) {
            cout << "FAIL!!!" << endl;
            break;
        }
    }

    uint64_t totalTime = time2 - time1;
    cout << "Tiempo Total: " << totalTime << endl;
}
