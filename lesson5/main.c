#include "utilus.h"

/* solution 1 */
typedef struct StackBin {
	char text[100];
	int n;
	int len;
} StackBin;

void t_push_bin_stack (StackBin * s, int val) {
	s->text[++s->n] = val + '0';
	s->len++;
}

char t_pop_bin_stack (StackBin * s) {
	s->len--;
	return s->text[s->n--];
}

char * hexToBin (int hex) {
	StackBin s;
	s.len = 0;
	s.n = -1;
	while (hex > 0) {
		t_push_bin_stack(&s, hex % 2);
		hex/= 2;
	}
	char * bin = (char *) malloc(sizeof(char) * s.n);
	int i = 0;
	while (s.n > -1)
		bin[i++] = t_pop_bin_stack(&s);
	bin[i] = '\0';
	return bin;
}

/* solution 2 */

/* solution 3 */
typedef struct StackEx {
	char exs[100];
	int n;
	int len;
} StackEx;

void t_push_ex_stack (StackEx * s, char val) {
	s->exs[++s->n] = val;
	s->len++;
}

char t_pop_ex_stack (StackEx * s) {
	s->len--;
	return s->exs[s->n--];
}

bool solution3 (char * str) {
	printf("%s\n", str);

	StackEx s;
	s.len = -1;
	s.n = 0;

	int i = 0;
	char c;
	do {
		c = str[i++];
		switch (c) {
			case '[': t_push_ex_stack(&s, c); break;
			case '(': t_push_ex_stack(&s, c); break;
			case '{': t_push_ex_stack(&s, c); break;
			case ']':
				if (s.len == -1) return false;
				if (t_pop_ex_stack(&s) != '[') return false;
				break;
			case '}':
				if (s.len == -1) return false;
				if (t_pop_ex_stack(&s) != '{') return false;
				break;
			case ')':
				if (s.len == -1) return false;
				if (t_pop_ex_stack(&s) != '(') return false;
				break;
		}
	} while (c != '\0');

	if (s.len > -1) return false;
	return true;
}

/* solution 4 */


int main () {

	// printf("%d\n", solution3("(2+(2*2))"));
	// printf("%d\n", solution3("(2+](2*2))"));

	printf("%s\n", hexToBin(12));

	
}