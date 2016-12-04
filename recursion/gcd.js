function findGCD(x, y) {
	var a = (x > y) ? x : y,
		b = (x > y) ? y : x,
		q = a/b,
		r = a%b;

	console.log("q: ", q);
	console.log("r: ", r);

	if (r === 0) {
		return b;
	}

	return findGCD(b, r);
}

console.log("GCD of 10, 45 is: ", findGCD(10, 45));
console.log("GCD of 1701, 3768 is: ", findGCD(1701, 3768));
