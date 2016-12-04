function findOrientation(p, q, r) {
	var value = ((q.y - p.y)*(r.x - p.x)) - ((r.y - p.y)*(q.x - p.x));

	if (value === 0)  return 0; // collinear

	return (value > 0) ? 1 : 2; // return 1 for clockwise and return 2 for anti-clockwise.
}
function buildConvexHull(points) {
	// find left most point.
	var n = points.length,
		leftMostPointIdx = 0,
		leftMostPoint = points[0],
		convexHullPoints = [];

	for (var i = 0; i < points.length; i++) {
		var eachPoint = points[i];
		if (eachPoint.x < leftMostPoint.x) {
			leftMostPointIdx = i;
			leftMostPoint = points[i];
		}
	}

	// loop through all the other points and build convex hull.
	var p = leftMostPointIdx,
		q = -1,
		r = -1,
		orientation = 0;
	do {
		convexHullPoints.push(points[p]);

		q = (p+1)%n;

		for (var i = 0; i < n; i++) {
			r = i;
			// Check if pq is more anti-clockwise or pr is more anti-clockwise
			orientation = findOrientation(points[p], points[q], points[r]);
			if (orientation === 2) {
				q = r;
			}
		}

		p = q;
	} while (p != leftMostPointIdx);

	console.log("convexHullPoints: ", convexHullPoints);
}
buildConvexHull(
	[
		{
			"x": 0,
			"y": 3
		},
		{
			"x": 1,
			"y": 1
		},
		{
			"x": 2,
			"y": 2
		},
		{
			"x": 4,
			"y": 4
		},
		{
			"x": 0,
			"y": 0
		},
		{
			"x": 1,
			"y": 2
		},
		{
			"x": 3,
			"y": 1
		},
		{
			"x": 3,
			"y": 3
		}
	]
);

buildConvexHull(
	[
		{ "x": 0, "y": 3 },
		{ "x": 2, "y": 2 },
		{ "x": 1, "y": 1 },
		{ "x": 2, "y": 1 },
		{ "x": 3, "y": 0 },
		{ "x": 0, "y": 0 },
		{ "x": 3, "y": 3 }
	]
);

