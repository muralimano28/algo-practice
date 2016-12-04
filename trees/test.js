var count = -1;
function test() {
	var arr = [1,2,3,4,5];
	print(arr, 0);
}
function print(arr, idx) {
	if (idx >= 5)
		return;
	count++;
	console.log("Count: ", count);
	print(arr, idx + 1);
	console.log("Printing: ", arr[idx]);
};
test();
