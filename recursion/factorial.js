function findFactorial(n) {
	// base case.
	if (n === 1) {
		return 1;
	}
	return n * findFactorial(n-1);
}

var value = findFactorial(5);
console.log("5! is: ", value);
