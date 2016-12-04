
function createNode(value) {
	newNode = {};

	newNode.data = value;
	newNode.left = null;
	newNode.right = null;
	newNode.nextRight = null;

	return newNode;
};

function printNextRights(root) {
	if (!root)
		return;
	console.log("My value is ", root.data, " and my next right is ", (root.nextRight) ? root.nextRight.data : null);
	printNextRights(root.left);
	printNextRights(root.right);
};

function configureNextRights(root) {
	var queue = [];
	queue.push(root);

	while(queue.length) {
		for (var count = queue.length; count > 0 ; count--){
			// Pop from queue.
			var elem1 = queue.shift();

			if (count > 1) {
				elem1.nextRight = queue[0];
			} else {
				elem1.nextRight = null;
			}

			// Push elem1's children into queue.
			if (elem1.left)
				queue.push(elem1.left);
			if (elem1.right)
				queue.push(elem1.right);
		}
	}
};

function Run() {
	var root = createNode("A");
	root.left = createNode("B");
	root.right = createNode("C");
	root.left.left = createNode("D");
	root.left.right = createNode("E");
	root.right.right = createNode("F");

	configureNextRights(root);
	printNextRights(root);
};

Run();

