#pragma once
#include <bits/stdc++.h>
#include "Point.hpp"

using namespace std;

template <class T>
class JarvisStep
{
    /**
     * @brief Number of points
     */
    int numPoints;

    /**
     * @brief Next point in jarvis march
     */
    Point<T> nextPoint;

public:
    /**
     * @brief Construct a new Jarvis March object
     * 
     * @param pivot Reference pivot from which points are compared
     * @param points Set of candidate points for Convex Hull
     */
    JarvisStep(Point<T> pivot, vector<Point<T>> &points);

    /**
     * @brief Get the next point in jarvis march
     * 
     * @return Point<T> 
     */
    Point<T> getNext();
};