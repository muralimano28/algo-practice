const NODE = {
	data: null,
	left: null,
	right: null
};

function createNode(value) {
	var newNode = JSON.parse(JSON.stringify(NODE));

	newNode.data = value;

	return newNode;
};

function findMax(inArr, start, end) {
	var max = -1000,
		maxIdx = -1;

	for (var i = start; i <= end; i++) {
		if (inArr[i] > max) {
			max = inArr[i];
			maxIdx = i;
		}
	}

	return maxIdx;
};

function printInorder(root) {
	if (!root)
		return;
	printInorder(root.left);
	process.stdout.write(root.data + "\t");
	printInorder(root.right);
};

function constructSplBT(inArr, start, end) {
	if (start > end)
		return null;

	var idx = findMax(inArr, start, end),
		root = createNode(inArr[idx]);

	if (start === end) {
		// only one variable is there. So return node.
		return root;
	} else {
		root.left = constructSplBT(inArr, start, idx - 1);
		root.right = constructSplBT(inArr, idx + 1, end);

		return root;
	}
};

var inArr = [5, 10, 40, 30, 28];
var root = constructSplBT(inArr, 0, inArr.length - 1);
printInorder(root);
process.stdout.write("\n");
