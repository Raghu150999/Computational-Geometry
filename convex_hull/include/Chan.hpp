#pragma once
#include "GrahamScan.hpp"
#include "JarvisStep.hpp"

template <class T>
class Chan
{
    /**
     * @brief Input points for computing convex hull
     */
    vector<Point<T>> points;

    /**
     * @brief Set of points in the convex hull in counter clockwise order
     */
    vector<Point<T>> convexHull;

    /**
     * @brief Number of points in the input
     */
    int numPoints;

    /**
     * @brief Convex Hull size
     */
    int convexHullSize;

    /**
     * @brief Pivot point in input points
     */
    Point<T> pivot;

    /**
     * @brief Tries to compute convex hull using given partition size (guessed size of hull)
     * 
     * @param guessedHullSize Guessed size of hull
     * @return true If algorithm completes, i.e. guessed size if greater or equal to actual hull size
     * @return false If algorithm fails to complete
     */
    bool restrictedConvexHull(int guessedHullSize);

    /**
     * @brief Divide input points equally into partitions of size 'partitionSize'
     * 
     * @param partitionSize 
     * @return vector<vector<Point<T>>> Partitions
     */
    vector<vector<Point<T>>> computePartitions(int partitionSize);

public:
    /**
     * @brief Construct a new Chan object
     * 
     * @param points Set of input points
     */
    Chan(vector<Point<T>> &points);

    /**
     * @brief Get convex hull computed using Chan's algorithm
     * 
     * @return vector<Point<T>> Set of points int convex hull in counter clockwise order
     */
    vector<Point<T>> getConvexHull();
};