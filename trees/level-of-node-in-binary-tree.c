# include <stdio.h>
# include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

// Function declarations.
struct node* createNode(int value);
void printInInorder(struct node* root);
int printLevel(struct node* root, int value);
int printLevelUtil(struct node* root, int value, int level);


// Function definitions.
struct node* createNode(int value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
};
void printInInorder(struct node* root) {
	if (root == NULL)
		return;

	printInInorder(root->left);
	printf("%d\t", root->data);
	printInInorder(root->right);

	return;
};
int printLevelUtil(struct node* root, int value, int level) {
	if (!root)
		return 0;

	if (root->data == value) {
		printf("level of the value %d is %d\n", value, level);
		return 1;
	} else {
		int left, right;

		left = printLevelUtil(root->left, value, level+1);
		right = printLevelUtil(root->right, value, level+1);

		return (left || right);
	}
};
int printLevel(struct node* root, int value) {
	int level = 1;

	return printLevelUtil(root, value, level);
};
int main() {
	struct node* root = createNode(9);
	root->left = createNode(5);
	root->right = createNode(11);
	root->left->left = createNode(1);
	root->left->right = createNode(6);
	root->right->left = createNode(10);
	root->right->right = createNode(12);

	printInInorder(root);
	printf("\n");

	int check = printLevel(root, 11);
	if (!check)
		printf("Given value is not present in the tree\n");

	return 0;
};
