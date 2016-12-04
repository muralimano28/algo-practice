# include <stdio.h>
# include <stdlib.h>

struct node {
	char data;
	struct node* left;
	struct node* right;
	struct node* nextRight;
};

struct node* createNode(char value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
};

void printNextRights(struct node* root) {
	while (root) {
		printf("%c\t", root->data);
		root = root->nextRight;
	}
};

void configureNextRights(struct node* root) {
	// push root to the queue.
};

int main() {
	struct node* root = createNode("A");
	root->left = createNode("B");
	root->right = createNode("C");
	root->left->left = createNode("D");
	root->left->right = createNode("E");
	root->right->right = createNode("F");

	configureNextRights(root, queue);
	printNextRights(root);
	return 0;
};
