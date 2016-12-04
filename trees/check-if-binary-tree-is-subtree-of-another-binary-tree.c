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

int isSame(struct node* root1, struct node* root2) {
	// if (!root1 && !root2) {
	// 	return 1;
	// } else if ((!root1 && root2) || (root1 && !root2)) {
	// 	return 0;
	// } else {
	// 	printf("root1 is %d and root2 is %d\n", root1->data, root2->data);
	// 	if ((root1->data == root2->data) && isSame(root1->left, root2->left) && isSame(root1->right, root2->right))
	// 		return 1;
	// 	else 
	// 		return 0;
	// }

	if (root1 == NULL && root2 == NULL)
		return 1;
	if (root1 == NULL || root2 == NULL)
		return 0;
	return ((root1->data == root2->data) && isSame(root1->left, root2->left) && isSame(root1->right, root2->right));
};
int checkIfSubtree(struct node* root1, struct node* root2) {
	if (!root1 && !root2) {
		return 1;
	} else if ((!root1 && root2) || (root1 && !root2)) {
		return 0;
	} else {
		if (root1->data == root2->data) {
			printf("same fn returns %d\n", isSame(root1, root2));
			return isSame(root1, root2);
		} else {
			return (checkIfSubtree(root1->left, root2) || checkIfSubtree(root1->right, root2));
		}
	}
};

void printInInorder(struct node* root) {
	if (root == NULL)
		return;

	printInInorder(root->left);
	printf("%d\t", root->data);
	printInInorder(root->right);
};

int main() {
	struct node* tree1 = createNode(26);
	tree1->left = createNode(10);
	tree1->right = createNode(3);
	tree1->left->left = createNode(4);
	tree1->left->right = createNode(6);
	tree1->left->left->right = createNode(30);
	tree1->right->right = createNode(3);

	printInInorder(tree1);
	printf("\n");

	struct node* tree2 = createNode(30);
	// tree2->left = createNode(4);
	// tree2->right = createNode(6);
	// tree2->left->right = createNode(30);

	printInInorder(tree2);
	printf("\n");

	int check = checkIfSubtree(tree1, tree2);
	if (check)
		printf("tree2 is a subtree of tree1\n");
	else 
		printf("tree2 is not a subtree of tree1\n");

	return 0;
};
