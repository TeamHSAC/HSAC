#include <stdio.h>

int main() {
	int n = 0;
	int x;
	int A[100] = { 0 };
	printf("���� A�� ���� �� (n) : ");
	scanf_s("%d", &n);
	printf("�� (x) ���� ���� ���ڸ� ��� �Ұ��� : ");
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
