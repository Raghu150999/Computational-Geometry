#include <bits/stdc++.h>
#include "Chan.hpp"
#include <vector>

using namespace std;
using namespace std::chrono;

int32_t main()
{
    // Number of points in the plane
    int n;
    cin >> n;
    vector<Point<int>> points;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back(Point<int>(x, y));
    }
    vector<Point<int>> convexHull = Chan<int>(points).getConvexHull();
    cout << "Counter Clockwise order of Convex Hull: " << endl;
    for (Point<int> &point : convexHull)
    {
        cout << point.x << " " << point.y << endl;
    }
}