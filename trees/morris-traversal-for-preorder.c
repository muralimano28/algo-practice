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

void printPreOrder(struct node* root) {
	if (root == NULL) {
		return;
	}

	struct node* curr = NULL;
	struct node* pre = NULL;

	curr = root;
	while(curr != NULL) {
		if (curr->left != NULL) {
			pre = curr->left;

			while(pre->right != NULL && pre->right != curr) {
				pre = pre->right;
			}

			if (pre->right == NULL) {
				printf("%d ", curr->data);
				pre->right = curr;
				curr = curr->left;
			} else {
				pre->right = NULL;
				curr = curr->right;
			}
		} else {
			printf("%d ", curr->data);
			curr = curr->right;
		}
	}

	printf("\n");
};

int main() {
	struct node* root = createNode(1);

	root->left = createNode(2);
	root->left->left = createNode(4);
	root->left->right = createNode(5);

	root->right = createNode(3);

	printPreOrder(root);
	return 0;
};
