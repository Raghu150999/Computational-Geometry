#include "GrahamScan.hpp"

using namespace std;

// Allowed type bindings
template class GrahamScan<int>;
template class GrahamScan<long>;
template class GrahamScan<long long>;
template class GrahamScan<float>;
template class GrahamScan<double>;

template <class T>
GrahamScan<T>::GrahamScan(vector<Point<T>> &points)
{
    numPoints = points.size();
    assert(numPoints >= 3);

    Point<T> best(points[0]);
    for (Point<T> &point : points)
        if (point < best)
            best = point;

    // Sort vertices by x-coordinate then by y-coordinate
    sort(points.begin(), points.end(), Comparator(best));

    order.push(points[0]);
    order.push(points[1]);

    // Construct Convex hull
    for (int i = 2; i < numPoints; i++)
        insert(points[i]);

    // Get all points in convex hull avoiding repeatition for lowermost-leftmost point
    while (!order.empty())
    {
        Point<T> top = order.top();
        convexHull.push_back(top);
        order.pop();
    }
    reverse(convexHull.begin(), convexHull.end());
    convexHullSize = convexHull.size();
}

template <class T>
void GrahamScan<T>::insert(Point<T> &p)
{
    Point<T> top = order.top();
    order.pop();
    while (order.size() >= 1 && Point<T>::orient(order.top(), top, p) <= 0)
    {
        top = order.top();
        order.pop();
    }
    order.push(top);
    order.push(p);
}

template <class T>
vector<Point<T>> GrahamScan<T>::getConvexHull()
{
    return convexHull;
}

template <class T>
bool GrahamScan<T>::isAbove(Point<T> pivot, Point<T> a, Point<T> b)
{
    if (Point<T>::orient(pivot, a, b) > 0)
        return true;
    else if (Point<T>::orient(pivot, a, b) == 0)
    {
        if (pivot.squaredDistance(a) > pivot.squaredDistance(b))
            return true;
    }
    return false;
}

template <class T>
bool GrahamScan<T>::isBelow(Point<T> pivot, Point<T> a, Point<T> b)
{
    if (Point<T>::orient(pivot, a, b) < 0)
        return true;
    else if (Point<T>::orient(pivot, a, b) == 0)
    {
        if (pivot.squaredDistance(a) < pivot.squaredDistance(b))
            return true;
    }
    return false;
}

template <class T>
Point<T> GrahamScan<T>::getRightTangentPoint(Point<T> pivot)
{
    if (convexHullSize < 3)
        return JarvisStep<T>(pivot, convexHull).getNext();
        
    // Check if convexHull[0] if local maximum
    if (isBelow(pivot, getPoint(1), getPoint(0)) &&
        !isAbove(pivot, getPoint(convexHullSize - 1), getPoint(0)))
        return getPoint(0);

    int low = 0, high = convexHullSize;
    while (true)
    {
        int mid = (low + high) / 2;
        bool isMidDown = isBelow(pivot, getPoint(mid + 1), getPoint(mid));
        if (isMidDown && !isAbove(pivot, getPoint(mid - 1), getPoint(mid)))
            return getPoint(mid);
        bool isLowUp = isAbove(pivot, getPoint(low + 1), getPoint(low));
        if (isLowUp)
        {
            if (isMidDown)
                high = mid;
            else
            {
                if (isAbove(pivot, getPoint(low), getPoint(mid)))
                    high = mid;
                else
                    low = mid;
            }
        }
        else
        {
            if (!isMidDown)
                low = mid;
            else
            {
                if (isBelow(pivot, getPoint(low), getPoint(mid)))
                    high = mid;
                else
                    low = mid;
            }
        }
    }
}

template <class T>
Point<T> GrahamScan<T>::getPoint(int idx)
{
    if (idx >= convexHullSize)
        idx -= convexHullSize;
    else if (idx < 0)
        idx += convexHullSize;
    return convexHull[idx];
}