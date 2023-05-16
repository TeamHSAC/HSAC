#include <stdio.h>

typedef struct {
	int real;
	int imag;
} COMPLEX;

void print_complex(COMPLEX com) {
	char sign;
	if (com.imag > 0)
		sign = '+';
	else {
		sign = '-';
		com.imag=abs(com.imag);
	}
	printf("(%d %c %di)\n", com.real, sign, com.imag);
}

COMPLEX add_complex(COMPLEX a, COMPLEX b) {
	COMPLEX new;
	new.real = a.real + b.real;
	new.imag = a.imag + b.imag;
	return new;
}

void convert(double* grades, double* scores, int size) {
	int i;
	for (int i = 0; i < size; i++) {
		*(scores + i) = *(grades + i) / 4.3 * 100;
	}
}

void main() {
	/*
	COMPLEX a, b, c;
	//a,b의 값을 지정할 부분 완성
	a.real = -3; a.imag = -2;
	b.real = -4; b.imag = -5;
	//a를 출력하는 부분 완성
	printf("a = ");
	print_complex(a);

	//b를 출력하는 부분 완성
	printf("b = ");
	print_complex(b);

	c = add_complex(a, b);
	//c를 출력하는 부분 완성
	printf("c = ");
	print_complex(c);
	*/
	double grades[10] = { 4.3,4.1,4.0,3.8,3.5,3.7,2.9,3.3,4.2,4.0 };
	double scores[10];

	convert(grades, scores, 10);

	for (int i = 0; i < 10; i++) {
		printf("%lf ", *(scores + i));
	}
}