#include <stdio.h>
#include <stdlib.h>

int main(int n){
	if(n < 0) return 1;
	
	int A[n];
	int k = n/2;
	int b = 0;
	while(k >= 1){
		b = 1;
		while(b != 0){
			b = 0;
			for(int i = k; i<n ;i++){
				if(A[i-k] > A[i]){
					temp = A[i];
					A[i] = A[i-k];
					A[i-k] = temp;
					b++;
				}
			}
		}
		k = k/2;
	
	}
	return 0;
}
