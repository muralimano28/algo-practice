function fibonacci(a, b, n) {
	if (n === 1) {
		console.log(a);
		return;
	}
	console.log(a);
	fibonacci(b, a+b, n-1);
}

fibonacci(0, 1, 10);
