function fac(n) {
	if (n === 1 || n === 0) {
		return 1;
	}
	return n * fac(n-1);
};
function printEachRow(arr, r, n) {
	if (r < 0) {
		console.log(arr.join(" "));
		return;
	}
	var value = fac(n)/(fac(r) * fac(n-r));
	arr[r] = value;
	printEachRow(arr, r-1, n);
};
function printPascalsTriangle(n) {
	for (var i = 0; i < n; i++) {
		var arr = [];
		printEachRow(arr, i, i);
	}
};

printPascalsTriangle(5);
