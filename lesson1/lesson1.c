#include <stdio.h>
#include <float.h>
#include <assert.h>
#include <stdbool.h>

int tpow (int a, int n) {
	int _a = a;
	for (int i = 1; i < n; i++) {
		a*= _a;
	}
	return a;
}

void solution1();
void solution2();
void solution3();
void solution4();
void solution5();
void solution6();
void solution7();
void solution8();
void solution9();
void solution10();
void solution11();
void solution12();
void solution13();
void solution14();
void solution15();
void menu();

int main () {
	// debug
	if (false) {
		solution15();
		return 0;
	}
	int sel = 0;
	do {
		menu();
		scanf("%i", &sel);
		printf("RESULT: \n");
		switch (sel) {
			case 1: solution1(); break;
			case 2: solution2(); break;
			case 3: solution3(); break;
			case 4: solution4(); break;
			case 5: solution5(); break;
			case 6: solution6(); break;
			case 7: solution7(); break;
			case 8: solution8(); break;
			case 9: solution9(); break;
			case 10: solution10(); break;
			case 11: solution11(); break;
			case 12: solution12(); break;
			case 13: solution13(); break;
			case 14: solution14(); break;
			case 15: solution15(); break;
			case 0: printf("Exit\n"); break;
			default: printf("Wrong selected\n");
		}
		printf("\n\n");
	} while (sel != 0);
	return 0;
}

void menu () {
	for (int i = 1; i < 16; i++)
		printf("%d - solution %d\n", i, i);
	printf("0 - exit\n");
	printf("select: ");
}

void solution1 () {
	float m, h;
	printf("m[kg] = ");
	scanf("%f", &m);
	printf("h[m] = ");
	scanf("%f", &h);
	printf("Индекс массы тела = %.1f\n", m / (h * h));
}

void solution2 () {
	int a, b, c, d, max;
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("c = ");
	scanf("%d", &c);
	printf("d = ");
	scanf("%d", &d);
	max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	if (max < d) max = d;
	printf("max = %d\n", max);
}

void solution3 () {
	int a = 10, b = 15, c = 0;
	printf("START: a = %d b = %d\n", a, b);
	c = a;
	a = b;
	b = c;
	printf("CHANGE1: a = %d b = %d\n", a, b);
	a = a ^ b;
	b = a ^ b;
	a = b ^ a;
	printf("CHANGE2: a = %d b = %d\n", a, b);
}

void solution4 () {
	int sq;
	printf("Sqrt from = ");
	scanf("%d", &sq);
	int arr[sq+1], i, max = 0;
	printf("sqrt(%d) = ", sq);
	for (i = 0; i <= sq; i++)
		arr[i] = 0;
	while (sq > 1) {
		for (i = 2; i <= sq; i++) {
			if (sq % i == 0) {
				arr[i]++;
				sq/= i;
				if (max < i) max = i;
				break;
			}
		}
	}
	int a = 1, b = 1;
	for (i = 2; i <= max; i++) {
		if (arr[i] > 0) {
			if (arr[i] > 1) {
				if (arr[i] % 2 == 0) {
					a*= tpow(i, arr[i] / 2);
				} else {
					arr[i]--;
					b*= i;
					a*= tpow(i, arr[i] / 2);
				}
			} else {
				b*= i;
			}
		}
	}
	if (b > 1) {
		printf("%d sqrt(%d)\n", a, b);
	} else {
		printf("%d\n", a);
	}
}

void solution5 () {
	int month = 0;
	printf("Please write a number of month: ");
	scanf("%d", &month);
	if (month == 12 || month == 1 || month == 2) printf("Now is winter.");
	if (2 < month && month < 6) printf("Now is spring.");
	if (5 < month && month < 9) printf("Now is summer.");
	if (8 < month && month < 12) printf("Now is autumn.");
	printf("\n");
}

void solution6 () {
	int age = 0;
	printf("Введите возраст од 1 - 150 = ");
	scanf("%d", &age);
	assert(age < 150);
	assert(age > 0);
	printf("Вам %d ", age);
	if (age == 1 || age == 101) printf("год\n");
	else if (age < 5 || (100 < age && age < 105)) printf("года\n");
	else printf("лет\n");
}

void solution7 () {
	int x1, y1, x2, y2;
	printf("x1 = ");
	scanf("%d", &x1);
	printf("y1 = ");
	scanf("%d", &y1);
	printf("x2 = ");
	scanf("%d", &x2);
	printf("y2 = ");
	scanf("%d", &y2);
	assert(x1 > 0);
	assert(y1 > 0);
	assert(x2 > 0);
	assert(y2 > 0);
	assert(x1 < 9);
	assert(y1 < 9);
	assert(x2 < 9);
	assert(y2 < 9);

	int tab[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == j) tab[i][j] = 0;
			else if ((i % 2 == 0 && j % 2 != 0) || (j % 2 == 0 && i % 2 != 0)) tab[i][j] = 1;
			else tab[i][j] = 0;
		}
	}

	if (tab[x1][y1] == tab[x2][y2]) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

void solution8 () {
	int a, b;
	printf("insert a = ");
	scanf("%d", &a);
	printf("insert b = ");
	scanf("%d", &b);
	assert(a < b);
	assert(a > 0);
	assert(b > 0);
	for (int i = a; i <= b; i++) {
		int pow = i * i;
		printf("%d => %d %d\n", i, pow, pow * i);
	}
}

void solution9 () {
	int N, K;
	printf("insert N = ");
	scanf("%d", &N);
	printf("insert K = ");
	scanf("%d", &K);
	assert(N >= 0);
	assert(K > 0);
	printf("%d / %d = ", N, K);
	if (N == 0) printf("0");
	else if (N == K) printf("1");
	else if (N < K) {

		// printf("%d(%d)", c, N);
	} else {
		int c = 0;
		while (N >= K) {
			c++;
			N-= K;
		}
		printf("%d(%d)", c, N);
	}
	printf("\n");
}

void solution10 () {
	int n, t = 0;
	printf("insert N = ");
	scanf("%d", &n);
	assert(n > 0);
	while (n > 0) {
		if ((n % 10) % 2 == 0) {
			t = 1;
			break;
		}
		n/= 10;
	}

	if (t) printf("False\n");
	else printf("True\n");
}

void solution11 () {
	int suma, insert, i = 0;
	printf("to done insert 0\n");
	do {
		printf("insert number = ");
		scanf("%d", &insert);
		if (insert % 10 == 8) {
			suma+= insert;
			i++;
		}
	} while (insert != 0 && i < 100);
	printf("%d\n", suma / i);
}

void solution12 () {
	int tab[3] = { 10, 74, 45 }, max;
	max = tab[0];
	if (tab[1] > max) max = tab[1];
	if (tab[2] > max) max = tab[2];
	printf("max(%d, %d, %d) = %d\n", tab[0], tab[1], tab[2], max);
}

void solution13 () {
	printf("empty\n");
}

void solution14 () {
	printf("empty\n");
}

void solution15 () {
	int n;
	printf("insert n = ");
	scanf("%d", &n);
	assert(n > 0);
	int tab[n+1];
	for (int i = 0; i < n + 1; i++)
		tab[i] = 1;
	tab[0] = 0;
	tab[1] = 0;
	for (int i = 2; i < n+1; i++) {
		if (tab[i] != 0) {
			for (int j = i * 2; j < n + 1; j+=i) {
				tab[j] = 0;
			}
			printf("%d ", i);
		}
	}
	printf("\n");
}