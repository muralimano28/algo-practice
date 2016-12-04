function findOrientation(p, q, r) {
	var value = ((q.y - p.y) * (r.x - p.x)) - ((r.y - p.y) * (q.x - p.x));

	return (value === 0) ? 0 : ((value > 0) ? 1 : 2)
}
function buildConvexHull(points) {
	var len = points.length,
		convexHullPoints = [];

	// Find left bottom most point.

	var min = 0;
	for (var i = 1; i < len; i++) {
		if (points[i].x < points[min].x || (points[i].x === points[min].x && points[i].y < points[min].y)) {
			min = i;
		}
	}

	// Swap first index with bottom left point (ie: min point).
	var minPoint = points.splice(min, 1)[0];
	// var temp = points[min];
	// points[min] = points[0];
	// points[0] = temp;

	// Sort remaining points (ie: n-1 points) by polar angle.
	points.sort(function(pointA, pointB) {
		var orientation = findOrientation(minPoint, pointA, pointB);

		if (orientation === 0) {
			// all three points are colinear.
			return (pointA.x === pointB.x) ? 0 : ((pointA.x < pointB.x) ? -1 : 1);
		} else if (orientation === 2) {
			return -1;
		} else {
			// orientation === 2
			return orientation;
		}
	});

	// remove colinear points and have only farthest point from minPoint in the array.
	var filteredPoints = points.filter(function(eachPoint, idx) {
		var nextPoint = points[idx + 1],
			orientation = (nextPoint) ? findOrientation(minPoint, eachPoint, nextPoint) : -1;

		if (orientation === 0) {
			return false;
		}

		return true;
	});

	var sortedArray = [minPoint].concat(filteredPoints),
		stackLen = 0,
		prev = null,
		curr = null,
		next = null,
		turns = -1;

	if (sortedArray.length < 3) {
		console.log("Convexhull is not possible with these points");
		return;
	}

	// Push first 3 points into stack.
	convexHullPoints.push(
		sortedArray[0],
		sortedArray[1],
		sortedArray[2]
	);

	for (var i = 3; i < sortedArray.length; i++) {
		stackLen = convexHullPoints.length;
		prev = convexHullPoints[stackLen - 2];
		curr = convexHullPoints[stackLen - 1];
		next = sortedArray[i];

		turns = findOrientation(prev, curr, next);

		if (turns === 1) {
			// Means next is taking a clock wise turn from current. so remove current.
			convexHullPoints.splice(stackLen - 1, 1);
		}
		// Means next is taking a anti clock wise turn from current. so push that to stack.
		convexHullPoints.push(next);
	}

	console.log("convexHullPoints: ", convexHullPoints);
}
buildConvexHull(
	[
		{ "x": 0, "y": 3 },
		{ "x": 1, "y": 1 },
		{ "x": 2, "y": 2 },
		{ "x": 4, "y": 4 },
		{ "x": 0, "y": 0 },
		{ "x": 1, "y": 2 },
		{ "x": 3, "y": 1 },
		{ "x": 3, "y": 3 }
	]
);
buildConvexHull(
	[
		{"x": 3, "y": 1},
		{"x": 4, "y": 2},
		{"x": 5, "y": 3}
	]
);
buildConvexHull(
	[
		{"x": 0, "y": 0},
		{"x": 1, "y": 0},
		{"x": 2, "y": 0}
	]
);
