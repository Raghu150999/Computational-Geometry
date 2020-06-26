#pragma once
#include <bits/stdc++.h>
#include "Point.hpp"
#include "JarvisStep.hpp"

using namespace std;

template <class T>
class GrahamScan
{
    /**
     * @brief Order stack for maintaining points in the partially
     * constructed convex hull
     */
    stack<Point<T>> order;

    /**
     * @brief Insert new point into the stack of partially constructed convex hull
     * 
     * @param p New point to be inserted
     */
    void insert(Point<T> &p);

    /**
     * @brief Number of points in input
     */
    int numPoints;

    /**
     * @brief Counter clockwiser order of points in the convex hull
     */
    vector<Point<T>> convexHull;

    /**
     * @brief Determine if 'a' lies strictly to left of 'b' (in orientation) w.r.t pivot
     * 
     * @param pivot 
     * @param a 
     * @param b 
     * @return true If 'a' lies strictly to left of 'b' 
     * @return false otherwise
     */
    bool isBelow(Point<T> pivot, Point<T> a, Point<T> b);

    /**
     * @brief Determine if a lies strictly to right of b (in orientation) w.r.t pivot
     * 
     * @param pivot 
     * @param a 
     * @param b 
     * @return true If 'a' lies strictly to right of b
     * @return false otherwise
     */
    bool isAbove(Point<T> pivot, Point<T> a, Point<T> b);

    /**
     * @brief Number of points in convex hull
     */
    int convexHullSize;

    /**
     * @brief Get the Point from convex hull at position 'idx'
     * 
     * @param idx 
     * @return Point 
     */
    Point<T> getPoint(int idx);

    /**
     * @brief Compare ordering of points for graham's scan
     */
    class Comparator
    {
        Point<T> pivot;

    public:
        Comparator(Point<T> pivot)
        {
            this->pivot = pivot;
        }

        bool operator()(Point<T> &p1, Point<T> &p2)
        {
            int o = Point<T>::orient(pivot, p1, p2);
            if (o == 1)
                return 1;
            else if (o == -1)
                return 0;
            else
                return p1 < p2;
        }
    };

public:
    /**
     * @brief Construct a new Graham Scan object
     * 
     * @param points set of points for constructing convex hull
     */
    GrahamScan(vector<Point<T>> &points);

    /**
     * @return vector<Point<T>> set of points in convex hull in counter clockwise order
     */
    vector<Point<T>> getConvexHull();

    /**
     * @brief Get the Right Tangent Point, using binary search on the convex hull
     * from the pivot as reference
     * 
     * @param pivot 
     * @return Point on the convex hull lying on the right tangent
     */
    Point<T> getRightTangentPoint(Point<T> pivot);
};