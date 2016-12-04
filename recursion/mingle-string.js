function mingle(stringA, stringB, outputArr, i, n) {
	if (i === n) {
		console.log(outputArr.join(""));
		return;
	}
	outputArr.push(
		stringA[i],
		stringB[i]
	);

	mingle(stringA, stringB, outputArr, i+1, n);
}
function mingleString(stringA, stringB, n) {
	var outputArr = [],
		startIdx = 0;
	mingle(stringA, stringB, outputArr, startIdx, n);
}

mingleString("abc", "xyz", 3);
mingleString("hacker", "ranker", 6);
mingleString("abcde", "pqrst", 5);
