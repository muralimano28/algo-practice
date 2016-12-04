function replaceAt(idx, str, newValue) {
	return str.substr(0, idx) + newValue + str.substr(idx + newValue.length);
}
function helper(idx, n, inputStr) {
	if (idx === n || n <= 1) {
		console.log("inputStr: ", inputStr);
		return;
	}
	// swapping
	var temp = inputStr[idx];
	inputStr = replaceAt(idx, inputStr, inputStr[idx+1]);
	inputStr = replaceAt(idx+1, inputStr, temp);

	// Swapping remaining string.
	helper(idx+2, n, inputStr);
}
function stringOPermute(inputString) {
	helper(0, inputString.length, inputString);
}

stringOPermute("abcd");
stringOPermute("abcdpqrs");
stringOPermute("az");
stringOPermute("a");
stringOPermute("");
