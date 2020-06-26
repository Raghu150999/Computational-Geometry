#pragma once
#include "Utils.hpp"

using namespace std;

template <class T>
class Point
{

public:
    T x, y;

    Point()
    {
        x = 0;
        y = 0;
    }

    /**
     * @brief Construct a new Point object
     * 
     * @param a 
     * @param b 
     */
    Point(T a, T b)
    {
        x = a;
        y = b;
    }

    /**
     * @brief Compare two points, by order of x-coordinate then y-coordinate
     * 
     * @param p 
     * @return true If 'this' point is lesser in ordering
     * @return false otherwise
     */
    bool operator<(const Point<T> &p)
    {
        if (x != p.x)
            return x < p.x;
        return y < p.y;
    }

    /**
     * @brief Check equality of points
     * 
     * @param p 
     * @return true 
     * @return false 
     */
    bool operator==(const Point<T> &p)
    {
        return (x == p.x && y == p.y);
    }

    /**
     * @brief Compute cross product of two vectors (represented as points)
     * 
     * @param p 
     * @return int signed area of the parallelipiped formed by the vectors
     */
    pair<double, double> cross(Point<T> &p)
    {
        double a = (double)x * (double)p.y;
        double b = (double)p.x * (double)y;
        return {a, b};
    }

    /**
     * @brief Compute orientation of the traversal of three points
     * 
     * @param p1 
     * @param p2 
     * @param p3 
     * @return int value signifying orientation
     */
    static int orient(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3)
    {
        Point<T> v1(p2.x - p1.x, p2.y - p1.y);
        Point<T> v2(p3.x - p2.x, p3.y - p2.y);
        auto o = v1.cross(v2);
        if (o.first > o.second)
            return 1;
        else if (o.first < o.second)
            return -1;
        else
            return 0;
    }

    /**
     * @brief Compute squared Euclidean distance between points
     * 
     * @param p 
     * @return int distance
     */
    double squaredDistance(Point<T> &p)
    {
        double dx = (double)x - (double)p.x;
        double dy = (double)y - (double)p.y;
        return Utils<double>::square(dx) + Utils<double>::square(dy);
    }

    /**
     * @brief Utility to print the point
     */
    void print()
    {
        cout << x << " " << y << endl;
    }
};