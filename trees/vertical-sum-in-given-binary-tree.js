const NODE = {
	data: 0,
	left: null,
	right: null
};

function printInorder(root) {
	if (!root)
		return;

	printInorder(root.left);
	console.log(root.data);
	printInorder(root.right);
};

function findVerticalSum(root, hdistance, hash) {
	if (!root)
		return;

	findVerticalSum(root.left, hdistance - 1, hash);

	if (hash[hdistance]) {
		hash[hdistance] += root.data;
	} else {
		hash[hdistance] = root.data;
	}

	findVerticalSum(root.right, hdistance + 1, hash);
};

function createNode(value) {
	var newNode = JSON.parse(JSON.stringify(NODE));

	newNode.data = value;

	return newNode;
};

var root = createNode(1);

root.left = createNode(2);
root.left.left = createNode(4);
root.left.right = createNode(5);

root.right = createNode(3);
root.right.left = createNode(6);
root.right.right = createNode(7);

var hash = {
};

printInorder(root);

findVerticalSum(root, 0, hash);

console.log("hash: ", hash);
