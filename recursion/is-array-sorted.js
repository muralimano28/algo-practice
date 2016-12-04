function isArraySorted (arr, n) {
	// base case.
	if (n === 1) {
		return true;
	}

	// for other than n, do following.
	return (arr[n-1] < arr[n-2]) ? false : isArraySorted(arr, n - 1);
}

var first = isArraySorted([1, 2, 3, 4, 5], 5);
console.log("first: ", first);
var second = isArraySorted([1, 2, 1, 4, 5], 5);
console.log("second: ", second);
