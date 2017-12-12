#include "utils.h"

/* solution 1 */
/* Реализовать перевод из 10 в 2 систему счисления с использованием стека. */
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
/*  Добавить в программу “реализация стека на основе односвязного списка”
	проверку на выделение памяти. Если память не выделяется, то выводится
	соответствующее сообщение. Постарайтесь создать ситуацию, когда память
	не будет выделяться (добавлением большого количества данных).
	*/
typedef struct Node {
	int val;
	struct Node * next;
} Node;

typedef struct Stack2 {
	Node *head;
	int size;
	int max_size;
} Stack2;

void push_stack2 (Stack2 * s, int val) {
	if (s->size + 1 > s->max_size) {
		printf("Error stack size");
		return;
	}
	s->size++;
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->val = val;
	new_node->next = s->head;
	s->head = new_node;
}

int pop_stack2 (Stack2 * s) {
	s->size--;
	if (s->size < -1) {
		printf("Error stack size");
		return -1;
	}
	int val = s->head->val;
	s->head = s->head->next;
	return val;
}

/* solution 3 */
/*  Написать программу, которая определяет, является ли введенная скобочная
	последовательность правильной. Примеры правильных скобочных выражений:
	(), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
	Например: (2+(2*2)) или [2/{5*(4+7)}]
	*/
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
/*  *Создать функцию, копирующую односвязный список
	(то есть создает в памяти копию односвязного списка, без удаления первого списка).
	*/
char * copyChar (char * str) {
	char * new_str = (char *) malloc(sizeof(char) * (strlen(str) + 1));
	int i = 0;
	while ((new_str[i] = str[i++]) != '\0');
	return new_str;
}

/* solution 5 */
/* **Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную. */
typedef struct NodeSolution5 {
	char val;
	struct NodeSolution5 * next;
} NodeSolution5;

typedef struct StackSolution5 {
	NodeSolution5 * head;
	int n;
} StackSolution5;

void push_stack_solution5 (StackSolution5 * s, char val) {
	s->n++;
	NodeSolution5 * new_node = (NodeSolution5 *) malloc(sizeof(NodeSolution5));
	new_node->val = val;
	new_node->next = s->head;
	s->head = new_node;
}

char pop_stack_solution5 (StackSolution5 * s) {
	s->n--;
	if (s->n < -1) return '\0';
	char val = s->head->val;
	s->head = s->head->next;
	return val;
}

char last_stack_solution5 (StackSolution5 * s) {
	if (s->n <= -1) return '\0';
	return s->head->val;
}

void check1_solution5_char (StackSolution5 * s, char * out, int * i) {
	char c = last_stack_solution5(s);
	if (c == '*' || c == '^') {
		while (true) {
			c = last_stack_solution5(s);
			if (c == '-' || c == '+' || c == '(' || c == '\0') break;
			out[*i++] = pop_stack_solution5(s);
		}
	}
}

char * solution5 (char * in) {
	if (!solution3(in)) return "Error string incorrect";
	char * out = (char *) malloc(sizeof(char) * (strlen(in) + 1));
	StackSolution5 s;
	s.n = -1;
	char c;
	int i = 0;
	while ((c = *in++) != '\0') {
		switch (c) {
			case '(': push_stack_solution5(&s, c); break;
			case ')':
				while ((c = pop_stack_solution5(&s)) != '(')
					out[i++] = c;
				break;
			case '+':
				check1_solution5_char(&s, out, &i);
				push_stack_solution5(&s, c);
				break;
			case '-':
				check1_solution5_char(&s, out, &i);
				push_stack_solution5(&s, c);
				break;
			case '*':
				if (last_stack_solution5(&s) == '+') out[i++] = c;
				else push_stack_solution5(&s, c);
				break;
			case '/':
				check1_solution5_char(&s, out, &i);
				push_stack_solution5(&s, c);
				break;
			case '^':
				if (last_stack_solution5(&s) == '+') out[i++] = c;
				else push_stack_solution5(&s, c);
				break;
			default: out[i++] = c;
		}
	}
	while ((c = pop_stack_solution5(&s)) != '\0')
		out[i++] = c;
	out[i] = '\0';
	return out;
}

/* solution 6 */
/* *Реализовать очередь. */
typedef struct QueueNode {
	int id;
	struct QueueNode * next;
} QueueNode;

typedef struct Queue {
	QueueNode * head;
	QueueNode * rear;
	int len;
} Queue;

void push_to_queue (Queue * q, int id) {
	QueueNode * new_node = (QueueNode *) malloc(sizeof(QueueNode));
	new_node->id = id;
	if (q->len == 0) q->head = new_node;
	else if (q->len == 1) q->head->next = new_node;
	else q->rear->next = new_node;
	q->rear = new_node;
	q->len++;
}

int pop_from_queue (Queue * q) {
	if (q->len == 0) return 0;
	q->len--;
	int val = q->head->id;
	q->head = q->head->next;
	return val;
}

void solution6 () {
	Queue q;
	q.len = 0;

	printf("\tIN:\n");
	printf("1\n"); push_to_queue(&q, 1);
	printf("2\n"); push_to_queue(&q, 2);
	printf("3\n"); push_to_queue(&q, 3);
	printf("4\n"); push_to_queue(&q, 4);

	printf("\n\tOUT:\n");
	printf("%d\n", pop_from_queue(&q));
	printf("%d\n", pop_from_queue(&q));
	printf("%d\n", pop_from_queue(&q));
	printf("%d\n", pop_from_queue(&q));
}

int main () {
	printf("\n\tSOLUTION 1:\n");
	printf("%s\n", hexToBin(12));

	printf("\n\tSOLUTION 3:\n");
	printf("%d\n", solution3("(2+(2*2))"));
	printf("%d\n", solution3("(2+](2*2))"));

	printf("\n\tSOLUTION 4:\n");
	char * test = "a12b34";
	char * new = copyChar(test);
	printf("%s == %s\n", test, new);

	printf("\n\tSOLUTION 5:\n");
	printf("%s\n", solution5("(A+B)*C-(D-E)*(F+G)"));
	printf("%s\n", solution5("3+4*2/(1-5)^2"));
	printf("%s\n", solution5("3+4*2/((1-5)^2"));

	printf("\n\tSOLUTION 6:\n");
	solution6();

	return 0;	
}