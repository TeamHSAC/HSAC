#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int x, n;

	printf("1보다 큰 N과 10000보다 작거나 같은 X를 차례로 입력\n");
	scanf("%d %d", &n, &x);

	int*A=(int*)malloc(sizeof(int)*n);//n의 크기를 동적으로 갖는 수열 A생성

	printf("수열 A를 이루는 정수 %d개 입력\n", n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}//각 정수를 수열A에 순서대로 저장

	printf("입력받은 정수들중 X보다 작은수를 입력받은 순서대로 출력\n");

	for (int i = 0; i < n; i++) {
		if (A[i] < x) {
			printf("%d ", A[i]);//수열A의 i번째값이 x보다작을경우 수열A의 i번째 값을 출력한다
		}
	}

}