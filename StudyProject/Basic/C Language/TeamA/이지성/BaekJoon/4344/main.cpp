#include <stdio.h>

int main() {
	int c; // 반복할 횟수
	int n; // case 별  학생수
	int total[1000] = { 0 }; // 전체 학생 점수 저장 배열
	int score; // 각각 학생의 점수
	int sum; // 합.
	float avg; // 평균
	int tru; // 평균 넘는거 몇개인지 저장할 변수. 

	printf("몇번 반복할지 : ");
	scanf_s("%d", &c);

	while (c--) {
		sum = 0;
		tru = 0;
		printf("학생 수 : ");
		scanf_s("%d", &n);

		for (int i = 0; i < n; i++) { // 학생의 수 (n) 만큼
			scanf_s("%d", &score);
			total[i] = score;
			sum += score;
		}
		avg = sum / n;
		printf("평균 : ");
		printf("%.3f%%\n", avg);
		
		for (int j = 0; j < n; j++) {
			if (avg > total[j]) {
				tru++;
			}
		}

		avg = 100 * tru / n;
		printf("평균 못넘은 학생의 비율 : ");
		printf("%.3f%%\n", avg);
	} // end while
}