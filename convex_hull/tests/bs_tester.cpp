#include <bits/stdc++.h>
#include "GrahamScan.hpp"

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<Point<int>> points;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back(Point<int>(x, y));
    }
    GrahamScan<int>(points).getRightTangentPoint(Point<int>(-151367802, -374247154)).print();
    return 0;
}