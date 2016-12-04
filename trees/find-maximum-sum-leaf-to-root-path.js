const NODE = {
	data: null,
	left: null,
	right: null
};
var Max = -1000, // Negative bigger value
	MaxNode = null;

function createNode(value) {
	var newNode = JSON.parse(JSON.stringify(NODE));

	newNode.data = value;

	return newNode;
};

function findMaxSumLeafToRootPath(root, sum) {
	if (!root)
		return;

	if (!root.left && !root.right) {
		// Leaf node.
		if (Max < (sum + root.data)) {
			// update Max and Max node.
			Max = sum + root.data;
			MaxNode = root;
		}
	} else {
		findMaxSumLeafToRootPath(root.left, sum + root.data);
		findMaxSumLeafToRootPath(root.right, sum + root.data);
	}
};

function printMaxRootToLeaf(root) {
	if (!root)
		return false;
	if (root.data === MaxNode.data || printMaxRootToLeaf(root.left) || printMaxRootToLeaf(root.right)) {
		// console.log(root.data);
		process.stdout.write(root.data + "\t");
		return true;
	}
	return false;
};

var root = createNode(10);

root.left = createNode(-2);
root.left.left = createNode(8);
root.left.right = createNode(-4);

root.right = createNode(7);

findMaxSumLeafToRootPath(root, 0);
console.log("MaxNode: ", MaxNode);
console.log("Max: ", Max);
printMaxRootToLeaf(root);
