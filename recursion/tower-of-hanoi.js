function toh(n, fromPeg, toPeg, auxPeg) {
	// base case.
	if (n === 1) {
		console.log("Moving disk no. 1 from " + fromPeg + " to " + toPeg);
		return;
	}

	// Move n-1 disks from A to B using C as auxillary peg.
	toh(n-1, fromPeg, auxPeg, toPeg);

	// Move nth disk from A to C.
	console.log("Moving disk no." + n + " from " + fromPeg + " to " + toPeg);

	// Move disks in B to C using A as auxillary.
	toh(n-1, auxPeg, toPeg, fromPeg);
}

// Calling toh function.
toh(3, 'A', 'C', 'B');
