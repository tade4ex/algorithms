#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "t_pow.h"
#include "t_dec2bin.h"
#include "t_calculator.h"

void menu();
void solution1();
void solution2a();
void solution2b();
void solution2c();

int main() {
	// debug
	if (false) {
		for (int x = 0; x < 24; x++)
			printf("%d\n", t_dec2bin_rec(x));
		return 0;
	}
	int sel = 0;
	do {
		menu();
		scanf("%i", &sel);
		printf("RESULT: \n");
		switch (sel) {
			case 1: solution1(); break;
			case 2: solution2a(); break;
			case 3: solution2b(); break;
			case 4: solution2c(); break;
			case 0: printf("Exit\n"); break;
			default: printf("Wrong selected\n");
		}
		printf("\n\n");
	} while (sel != 0);
	return 0;
}

void menu () {
	printf("1 - solution 1\n");
	printf("2 - solution 1a\n");
	printf("3 - solution 1b\n");
	printf("4 - solution 1c\n");
	printf("0 - exit\n");
	printf("select: ");
}

void solution1 () {
	int dec;
	printf("Insert dec = ");
	scanf("%d", &dec);
	printf("%d(10) = %d(2)\n", dec, t_dec2bin_rec(dec));
}

void solution2a () {
	int a, n;
	printf("Insert a = ");
	scanf("%d", &a);
	printf("Insert n = ");
	scanf("%d", &n);
	printf("%d^%d = %d\n", a, n, t_pow(a, n));
}

void solution2b () {
	int a, n;
	printf("Insert a = ");
	scanf("%d", &a);
	printf("Insert n = ");
	scanf("%d", &n);
	printf("%d^%d = %d\n", a, n, t_pow_rec(a, n));
}

void solution2c () {
	int a, n;
	printf("Insert a = ");
	scanf("%d", &a);
	printf("Insert n = ");
	scanf("%d", &n);
	printf("%d^%d = %d\n", a, n, t_pow_rec_2(a, n));
}