#include "utils.h"

/* 1. Реализовать простейшую хеш-функцию. На вход функции подаётся строка, на выходе сумма кодов символов. */
int solution1 (char * str) {
	char c;
	int sum = 0;
	while (c = *str++) {
		sum+= (int) c;
	}
	return sum;
}

/*2. Переписать программу, реализующее двоичное дерево поиска.*/

typedef struct Node {
	int data;
	struct Node * left;
	struct Node * parent;
	struct Node * right;
} Node;

Node * NewNode (int data, Node * parent) {
	Node * newNode = (Node *) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->parent = parent;
	newNode->right = NULL;
}

void printTree(Node *root) {
    if (root) {
        printf("%d", root->data);

        if (root->left || root->right) {
            printf("(");

            if (root->left) {
                printTree(root->left);
            } else {
                printf("NULL");
            }

            printf(",");

            if (root->right) {
                printTree(root->right);
            } else {
                printf("NULL");
            }

            printf(")");
        }
    }
}

void postOrderTraverse (Node * root) {
    if (root) {
        postOrderTraverse(root->left);
        postOrderTraverse(root->right);
        printf("%d ", root->data);
    }
}

void inOrderTraverse (Node * root) {
	if (root) {
		inOrderTraverse(root->left);
		printf("%d ", root->data);
		inOrderTraverse(root->right);
	}
}

void preOrderTraverse (Node * root) {
	if (root) {
		printf("%d ", root->data);
		preOrderTraverse(root->left);
		preOrderTraverse(root->right);
	}
}

bool searchBinTree (Node * root, int f) {
	if (root) {
		if (root->data == f) return true;
		else if (root->data > f) return searchBinTree(root->left, f);
		else return searchBinTree(root->right, f);
	}
	return false;
}

void solution2 () {
	Node * root = NewNode(6, NULL);
	root->left = NewNode(3, root);
	root->left->left = NewNode(1, root->left);
	root->left->left->right = NewNode(2, root->left->left);
	root->left->right = NewNode(4, root->left);
	root->left->right->right = NewNode(5, root->left->right);
	root->right = NewNode(8, root);
	root->right->left = NewNode(7, root->right);
	root->right->right = NewNode(9, root->right);
	root->right->right->right = NewNode(10, root->right->right);
	printf("\tSOLUTION2A:\n");
	printf("TREE:\n");
    printTree(root);
    printf("\npre-order:\n");
    preOrderTraverse(root);
    printf("\nin-order:\n");
    inOrderTraverse(root);
    printf("\npost-order:\n");
    postOrderTraverse(root);
    printf("\n");
	printf("\tSOLUTION2B:\n");
	printf("FIND (12) => %d\n", searchBinTree(root, 12));
	printf("FIND (2) => %d\n", searchBinTree(root, 2));
	printf("FIND (10) => %d\n", searchBinTree(root, 10));
	printf("FIND (99) => %d\n", searchBinTree(root, 99));
}


int main () {
	printf("\tSOLUTION1:\n");
	printf("test => %d\n", solution1("test"));
	printf("test or test -- => %d\n", solution1("test or test --"));
	solution2();
	return 0;	
}