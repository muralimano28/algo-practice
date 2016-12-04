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

void printInorder(struct node* root) {
	if (!root)
		return;

	printInorder(root->left);
	printf("%d\t", root->data);
	printInorder(root->right);
};

int convertToSumTree(struct node* root) {
	if (!root)
		return 0;

	int oldValue = root->data;

	root->data = convertToSumTree(root->left) + convertToSumTree(root->right);

	return root->data + oldValue;
};

int main() {
	struct node* root = createNode(10);
	root->left = createNode(-2);
	root->right = createNode(6);
	root->left->left = createNode(8);
	root->left->right = createNode(-4);
	root->right->left = createNode(7);
	root->right->right = createNode(5);

	printInorder(root);
	printf("\n");

	convertToSumTree(root);

	printInorder(root);
	printf("\n");

	return 0;
};
