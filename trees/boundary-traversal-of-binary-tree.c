# include <stdio.h>
# include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void printLefts(struct node* root) {
	if (root == NULL || (root->left == NULL && root->right == NULL)) {
		return;
	} else {
		printf("%d\t", root->data);
		printLefts(root->left);
	}
};

void printLeaves(struct node* root) {
	if (!root)
		return;
	if (!root->left && !root->right) {
		printf("%d\t", root->data);
	} else {
		printLeaves(root->left);
		printLeaves(root->right);
	}
};

void printRights(struct node* root) {
	if (root == NULL || (root->left == NULL && root->right == NULL)) {
		return;
	} else {
		printRights(root->right);
		printf("%d\t", root->data);
	}
};

void printBoundary(struct node* root) {
	if (root == NULL)
		return;
	printf("%d\t", root->data);

	printLefts(root->left);

	printLeaves(root->left);
	printLeaves(root->right);

	printRights(root->right);
};

struct node* createNode(int value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
};

int main() {
	struct node* root = createNode(20);

	root->left = createNode(8);
	root->left->left = createNode(4);
	root->left->right = createNode(12);

	root->left->right->left = createNode(10);
	root->left->right->right = createNode(14);

	root->right = createNode(22);
	root->right->right = createNode(25);

	printBoundary(root);

	return 0;
};
