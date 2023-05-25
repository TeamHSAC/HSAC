#include <stdio.h>

int main() {
	int n = 0;
	int x;
	int A[100] = { 0 };
	printf("수열 A의 숫자 수 (n) : ");
	scanf_s("%d", &n);
	printf("몇 (x) 보다 작은 숫자를 출력 할건지 : ");
	scanf_s("%d", &x);
	int k = 0;
	for (int i=0; i < n; i++) {
		scanf_s("%d", &k);
		A[i] = k;
	}

	for (int j = 0; j < n; j++) {
		if (A[j] < x) {
			printf("%d ", A[j]);
		}
	}

}
