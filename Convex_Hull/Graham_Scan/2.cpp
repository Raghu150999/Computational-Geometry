#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

/*
*   This code computes Convex Hull using Graham's Scan by sorting vertices
*   by angle, with respect to pivot. Pivot is choosen to be the 
*   left-most bottom-most point.
*   Time Complexity: O(nlogn)
*/

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
        if (x != p.x)
            return x < p.x;
        return y < p.y;
    }

    int cross(Point &p)
    {
        return (x * p.y - p.x * y);
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

bool compare(Point &p1, Point &p2)
{
    int o = p1.orient(pivot, p1, p2);
    if(o == 1)
        return 1;
    else if(o == -1)
        return 0;
    else
        return p1 < p2;
}

// Function to insert new point into the hull
void insert(Point &p, stack<Point> &order)
{
    Point top = order.top();
    order.pop();
    while (order.size() >= 1 && top.orient(order.top(), top, p) <= 0)
    {
        top = order.top();
        order.pop();
    }
    order.push(top);
    order.push(p);
}


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

    // Sort vertices by angle from pivot
    sort(vp.begin(), vp.end(), compare);

    stack<Point> order;
    
    order.push(vp[0]);
    order.push(vp[1]);
    
    // Iterate over all points and insert into Convex Hull
    for(int i = 2; i < n; i++)
        insert(vp[i], order);

    stack<Point> invert_order;
    while (!order.empty())
    {
        Point top = order.top();
        invert_order.push(top);
        order.pop();
    }

    // Convex Hull in counter clockwise order
    cout << "Convex Hull (counter clockwise order): " << endl;
    while(!invert_order.empty())
    {
        Point top = invert_order.top();
        cout << top.x << " " << top.y << endl;
        invert_order.pop();
    }
    return 0;
}

// TODO: Fix bug with collinear points