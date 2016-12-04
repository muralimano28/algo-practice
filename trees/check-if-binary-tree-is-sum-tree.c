# include <stdio.h>
# include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void printInInorder(struct node* root) {
	if (root == NULL)
		return;

	printInInorder(root->left);
	printf("%d\t", root->data);
	printInInorder(root->right);
};

struct node* createNode(int value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
};

int findSum(struct node* root) {
	if (!root)
		return 0;

	// return root->data + findSum(root->left) + findSum(root->right);

	if (!root->left && !root->right) {
		return root->data;
	} else {
		return 2*root->data;
	}
};

int checkSumTree(struct node* root) {
	if (!root || (!root->left && !root->right))
		return 1;

	int leftSum = 0,
		rightSum = 0;

	leftSum = findSum(root->left);
	rightSum = findSum(root->right);

	if (checkSumTree(root->left) && checkSumTree(root->right) && (root->data == leftSum + rightSum))
		return 1;
	else
		return 0;
};

int main() {
	struct node* root = createNode(26);
	root->left = createNode(10);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(6);
	root->right->right = createNode(3);

	printInInorder(root);
	printf("\n");

	int check = checkSumTree(root);
	if (check)
		printf("true\n");
	else
		printf("false\n");

	return 0;
};
