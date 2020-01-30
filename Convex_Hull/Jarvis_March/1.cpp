#include <bits/stdc++.h>

using namespace std;

#define INF 1e7

/*
*   This code computes Convex Hull using Jarvis March algorithm.
*   Complexity: O(nh)
*   where,
*   n: number of points given in input
*   h: number of vertices of Convex Hull
*/

struct Point
{
    int x, y;

    Point()
    {
        x = y = 0;
    }

    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    bool operator<(const Point &p)
    {
        if (x != p.x)
            return x < p.x;
        return y < p.y;
    }

    bool operator==(const Point &p)
    {
        return (x == p.x && y == p.y);
    }

    int cross(Point &p)
    {
        return (x * p.y - p.x * y);
    }

    int square(int x)
    {
    	return x * x;
    }

    int dist_squared(Point &p)
    {
        return (square(x - p.x) + square(y - p.y));
    }

    // Finds the orientation of the given 3 points
    int orient(const Point &p1, const Point &p2, const Point &p3)
    {
        Point v1(p2.x - p1.x, p2.y - p1.y);
        Point v2(p3.x - p2.x, p3.y - p2.y);
        int o = v1.cross(v2);
        if (o > 0)
            return 1;
        else if (o == 0)
            return 0;
        else
            return -1;
    }
};

Point pivot(INF, INF);

int main()
{
    // Number of points in the plane
    int n;
    cin >> n;
    vector<Point> vp;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        Point p(x, y);
        vp.push_back(p);
        if(p < pivot)
            pivot = p;
    }
    // Handle case when n < 3
    if (n < 3)
    {
        cout << "Number of points must be greater than or equal to 3";
        return 0;
    }
    
    vector<Point> order;
    order.push_back(pivot);
    // This outer loop runs h times.
    while(1)
    {
        Point p = order.back();
        Point best(INF, INF);
        // Iterate over all points to get next point in convex hull
        for(int j = 0; j < n; j++)
        {
            if(vp[j] == p)
                continue;
            if(best == Point(INF, INF))
                best = vp[j];
            else
            {
            	// Selecting the right-most point w.r.t p
                int o = p.orient(p, best, vp[j]);
                if(o < 0)
                    best = vp[j];
                else if(o == 0)
                {
                	// If points are collinear take the farthest one
                    if(p.dist_squared(vp[j]) > p.dist_squared(best))
                        best = vp[j];
                }
            }
        }
        if(best == pivot)
        	break;
        order.push_back(best);
    }
    cout << "Convex Hull counter clockwise order: " << endl;
    for(Point &p: order)
        cout << p.x << " " << p.y << endl;
    return 0;
}