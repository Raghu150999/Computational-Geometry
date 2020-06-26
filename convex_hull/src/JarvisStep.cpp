#include "JarvisStep.hpp"
#include "Utils.hpp"

// Allowed type bindings
template class JarvisStep<int>;
template class JarvisStep<long>;
template class JarvisStep<long long>;
template class JarvisStep<float>;
template class JarvisStep<double>;

template <class T>
JarvisStep<T>::JarvisStep(Point<T> pivot, vector<Point<T>> &points)
{
    Point<T> best(points[0]);
    for (Point<T> &point : points)
    {
        if (point == pivot)
            continue;
        // Selecting the right-most-oriented point w.r.t pivot
        int orientation = pivot.orient(pivot, best, point);
        if (orientation < 0)
            best = point;
        else if (orientation == 0)
        {
            // If points are collinear take the farthest one
            if (pivot.squaredDistance(point) > pivot.squaredDistance(best))
                best = point;
        }
    }
    nextPoint = best;
}

template <class T>
Point<T> JarvisStep<T>::getNext()
{
    return nextPoint;
}
