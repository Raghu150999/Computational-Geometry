#include <bits/stdc++.h>
#include "JarvisStep.hpp"
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
    vector<Point<int>> convexHull;
    Point<int> pivot(points[0]);
    for (Point<int> &point : points)
    {
        if (point < pivot)
            pivot = point;
    }
    Point<int> currPivot = pivot;
    while (true)
    {
        convexHull.push_back(currPivot);
        currPivot = JarvisStep<int>(currPivot, points).getNext();
        if (currPivot == pivot)
            break;
    }
    cout << "Counter Clockwise order of Convex Hull: " << endl;
    for (Point<int> &point : convexHull)
        cout << point.x << " " << point.y << endl;
}