# include <stdio.h>
# include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

// void printTreeInInorder(struct node* root);
struct node* createNode(int data);
int printAnscestor(struct node* root, int value);

// void printTreeInInorder(struct node* root) {
// 	if (root == NULL)
// 		return;
// 
// 	printTreeInInorder(root->left);
// 	printf("%d\t", root->data);
// 	printTreeInInorder(root->right);
// };

struct node* createNode(int data) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
};

int printAnscestor(struct node* root, int value) {
	if (root == NULL) {
		return 0;
	} else if (root->data == value) {
		return 1;
	} else {
		int leftSubtree = 0,
			rightSubtree = 0;

		leftSubtree = printAnscestor(root->left, value);
		rightSubtree = printAnscestor(root->right, value);

		if (leftSubtree || rightSubtree) {
			printf("%d\t", root->data);
			return 1;
		} else {
			return 0;
		}
	}
};

int main() {

	struct node* root = createNode(9);
	root->left = createNode(5);
	root->right = createNode(11);
	root->left->left = createNode(1);
	root->left->right = createNode(6);
	root->right->left = createNode(10);
	root->right->right = createNode(12);

	// printTreeInInorder(root);

	int check = printAnscestor(root, 13);
	if (!check)
		printf("Given value is not in the tree\n");

	printf("\n");
	return 0;
};
