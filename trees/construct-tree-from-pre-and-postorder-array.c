# include <stdio.h>
# include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
};

struct node* constructTree(int pre[], int post[], int start, int end, int* preIdx) {

	if (start > end) {
		return NULL;
	}
	// Construct root from preIdx.
	struct node* root = createNode(pre[*preIdx]);

	// Increment preIdx to point next element in pre array.
	++*preIdx;

	if (start == end) {
		return root;
	}

	// Find index of preIdx value in post array.
	// Here last element is not checked bcoz in post last element is the root element.
	int postIdx = -1;
	for (int i = 0; i < end; i++) {
		if (pre[*preIdx] == post[i]) {
			postIdx = i;
			break;
		}
	}

	root->left = constructTree(pre, post, start, postIdx, preIdx);
	root->right = constructTree(pre, post, postIdx + 1, end - 1, preIdx);

	return root;
};

void printInOrder(struct node* root) {
	if (!root)
		return;
	printInOrder(root->left);
	printf("%d ", root->data);
	printInOrder(root->right);
};

int main() {
	int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
	int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};

	int size = sizeof(pre)/sizeof(pre[0]);
	int preIdx = 0;

	struct node* root = constructTree(pre, post, 0, size-1, &preIdx);

	printInOrder(root);
	printf("\n");

	return 0;
}
