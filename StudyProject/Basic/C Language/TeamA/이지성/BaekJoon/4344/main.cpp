#include <stdio.h>

int main() {
	int c; // �ݺ��� Ƚ��
	int n; // case ��  �л���
	int total[1000] = { 0 }; // ��ü �л� ���� ���� �迭
	int score; // ���� �л��� ����
	int sum; // ��.
	float avg; // ���
	int tru; // ��� �Ѵ°� ����� ������ ����. 

	printf("��� �ݺ����� : ");
	scanf_s("%d", &c);

	while (c--) {
		sum = 0;
		tru = 0;
		printf("�л� �� : ");
		scanf_s("%d", &n);

		for (int i = 0; i < n; i++) { // �л��� �� (n) ��ŭ
			scanf_s("%d", &score);
			total[i] = score;
			sum += score;
		}
		avg = sum / n;
		printf("��� : ");
		printf("%.3f%%\n", avg);
		
		for (int j = 0; j < n; j++) {
			if (avg > total[j]) {
				tru++;
			}
		}

		avg = 100 * tru / n;
		printf("��� ������ �л��� ���� : ");
		printf("%.3f%%\n", avg);
	} // end while
}