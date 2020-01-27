#include <bits/stdc++.h>

using namespace std;

struct Point
{
	int x, y;
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
	bool operator<(const Point &p)
	{
		if(x != p.x)
			return x < p.x;
		return y < p.y;
	}
	int cross(Point &p)
	{
		return (x * p.y - p.x * y);
	}
};

// Finds the orientation of the given 3 points
int orient(Point &p1, Point &p2, Point &p3)
{
	Point v1(p2.x - p1.x, p2.y - p1.y);
	Point v2(p3.x - p2.x, p3.y - p2.y);
	int o = v1.cross(v2);
	if(o > 0)
		return 1;
	else
	if(o == 0)
		return 0;
	else
		return -1;
}

// Function to insert new point into the hull
void insert(Point &p, stack<Point> &order)
{
	Point top = order.top();
	order.pop();
	while(order.size() >= 1 && orient(order.top(), top, p) >= 0)
	{
		top = order.top();
		order.pop();
	}
	order.push(top);
	order.push(p);
}

/* Following implementation is robust to:
*	1. Repetition of points
*	2. Collinear points
*/

int32_t main()
{
	// Number of points in the plane
	int n;
	cin >> n;
	vector<Point> vp;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vp.push_back(Point(x, y));
	}

	// Handle case when n < 3
	if(n < 3)
	{
		cout << "Number of points must be greater than or equal to 3";
		return 0;
	}

	// Sort vertices by x-coordinate then by y-coordinate
	sort(vp.begin(), vp.end());

	stack<Point> order;
	order.push(vp[0]);
	order.push(vp[1]);
	
	// Construct Upper Hull
	for(int i = 2; i < n; i++)
		insert(vp[i], order);

    order.push(vp[n-2]);
	// Construct the Lower Hull
	for(int i = n - 3; i >= 0; i--)
		insert(vp[i], order);

	// Convex Hull in counter clockwise order
	cout << "Convex Hull (counter clockwise order): " << endl;
	while(!order.empty())
	{
		Point top = order.top();
		cout << top.x << " " << top.y << endl;
		order.pop();
	}
	return 0;
}