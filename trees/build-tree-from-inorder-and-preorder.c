# include <stdio.h>
# include <stdlib.h>


struct node {
	char data;
	struct node* left;
	struct node* right;
};

struct node* createNode(char value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
};

int findIndex(char inArr[], int start, int end, char value) {
	for (int i = start; i <= end; i++) {
		if (inArr[i] == value)
			return i;
	}
	return 0;
};

struct node* buildTree(char inArr[], char preArr[], int start, int end) {
	static int preIdx = 0;

	printf("preIdx: %d\t start: %d\t end: %d\n", preIdx, start, end);
	if (start > end)
		return NULL;

	struct node* root = createNode(preArr[preIdx++]);

	if (start == end) {
		return root;
	} else {
		int inIdx = findIndex(inArr, start, end, root->data);
		root->left = buildTree(inArr, preArr, start, inIdx - 1);
		root->right = buildTree(inArr, preArr, inIdx + 1, end);

		return root;
	}
};

void printInOrder(struct node* root) {
	if (!root)
		return;

	printInOrder(root->left);
	printf("%c\t", root->data);
	printInOrder(root->right);
};

int main() {
	char inArr[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	char preArr[] = {'A', 'B', 'D', 'E', 'C', 'F'};

	int inArrLength = sizeof(inArr)/sizeof(inArr[0]);
	struct node* root = buildTree(inArr, preArr, 0, inArrLength - 1);
	printInOrder(root);

	return 0;
};
