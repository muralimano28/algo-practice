# include <stdio.h>
# include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
	struct node* next;
};

struct node* createNode(int value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->next = NULL;

	return newNode;
};
void populateNextPointer(struct node* root, struct node** next) {
	if (root) {
		populateNextPointer(root->right, next);

		root->next = *next;
		*next = root;

		populateNextPointer(root->left, next);
	}
};
void printNextPointers(struct node* root) {
	if (!root)
		return;
	printNextPointers(root->left);
	if (root->next != NULL) {
		printf("%d 's next is %d\n", root->data, root->next->data);
	} else {
		printf("%d 's next is null\n", root->data);
	}
	printNextPointers(root->right);
};
int main() {
	struct node* root = createNode(10);
	root->left = createNode(8);
	root->right = createNode(12);
	root->left->left = createNode(3);

	struct node* next = NULL;
	populateNextPointer(root, &next);
	printNextPointers(root);
	return 0;
};
