# include <stdio.h>
# include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(int value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
};

int main() {
	struct node* root = createNode(1);

	root->left = createNode(2);
	root->left->left = createNode(4);
	root->left->right = createNode(5);

	root->right = createNode(3);

	printPostOrder(root);
	return 0;
};
