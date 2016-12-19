const NODE = {
	data: 0,
	left: null,
	right: null
};

function createNode(value) {
	var newNode = JSON.parse(JSON.stringify(NODE));

	newNode.data = value;
	newNode.left = null;
	newNode.right = null;

	return newNode;
}

function traversePreOrder(root) {
	if (!root) {
		return;
	}

	var stack = [];

	// push root to stack.
	stack.push(root);

	// Loop until stack is empty.
	while(stack.length) {
		// Pop top element.
		poppedElem = stack.pop();

		// Print popped element.
		process.stdout.write(poppedElem.data + " ");

		// Push popped elements childrens.
		if (poppedElem.right) {
			stack.push(poppedElem.right);
		}
		if (poppedElem.left) {
			stack.push(poppedElem.left);
		}
	}
	process.stdout.write("\n");
}

var root = createNode(10);

root.left = createNode(8);
root.left.left = createNode(3);
root.left.right = createNode(5);

root.right = createNode(2);
root.right.left = createNode(2);

traversePreOrder(root);
