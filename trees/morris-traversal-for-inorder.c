# include <stdio.h>
# include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* constructNode(int value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
};

void printInorderUsingMorris(struct node* root) {
	if (root == NULL) {
		return;
	}
	struct node* curr = NULL;
	struct node* pre = NULL;

	curr = root;
	while(curr != NULL) {
		if (curr->left != NULL) {
			pre = curr->left;
			// Find rightmost element in left sub tree (inorder successor)
			while(pre->right != NULL && pre->right != curr) {
				pre = pre->right;
			}
			if (pre->right == NULL) {
				// If pre->right is null, then make curr as pre's right and move curr to curr's left.
				pre->right = curr;
				curr = curr->left;
			} else {
				// If pre->right is not null, then make it null and print curr and move to right of curr.
				pre->right = NULL;
				printf("%d ", curr->data);

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
	struct node* root = constructNode(1);

	root->left = constructNode(2);
	root->left->left = constructNode(4);
	root->left->right = constructNode(5);

	root->right = constructNode(3);

	printInorderUsingMorris(root);
	return 0;
};
