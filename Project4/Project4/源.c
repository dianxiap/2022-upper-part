#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Bubble(int* a, int n) {
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n - i; j++) {
			
			if (a[j] > a[j +1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}



int Binarysearch(int* a, int n, int x) {

	int begin = 0;
	int end = 0;
	while (begin < end) {

		int mid = (begin + end) / 2;
		if (a[mid] < x) begin = mid + 1;
		
		else if (a[mid] > x)end = mid - 1;
		
		else return mid;
	}
	return -1;

}


long long Fac(size_t N)
{
	return N < 2 ? N : Fac(N - 1) * N;
}