#include <bits/stdc++.h>
#include "GrahamScan.hpp"
#include "Chan.hpp"

using namespace std;

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));
    if (argc < 2)
    {
        cout << "Usage: ./tester.o numTests" << endl;
        return 0;
    }
    int numTests = atoi(argv[1]);
    // Number of points to be used
    int n = 1e5;
    double maxa = 1e18;
    for (int t = 1; t <= numTests; t++)
    {
        cout << "\rTest " << t << ": ";
        set<pair<double, double>> data;
        for (int i = 1; i <= n; i++)
        {
            double x = maxa * ((double)rand()) / ((double)RAND_MAX) * (rand() % 2 ? 1 : -1);
            double y = maxa * ((double)rand()) / ((double)RAND_MAX) * (rand() % 2 ? 1 : -1);
            data.insert({x, y});
        }
        vector<Point<double>> points;
        ofstream datafile;
        datafile.open("./tests/data.txt");
        datafile << data.size() << "\n";
        for (auto point : data)
        {
            points.push_back(Point<double>(point.first, point.second));
            datafile << point.first << " " << point.second << "\n";
        }
        datafile << endl;
        datafile.close();
        vector<Point<double>> convexHullGrahamScan = GrahamScan<double>(points).getConvexHull();
        vector<Point<double>> convexHullChan = Chan<double>(points).getConvexHull();
        sort(convexHullGrahamScan.begin(), convexHullGrahamScan.end());
        sort(convexHullChan.begin(), convexHullChan.end());
        bool pass = true;
        if (convexHullGrahamScan.size() != convexHullChan.size())
            pass = false;
        else
        {
            int convexHullSize = convexHullChan.size();
            for (int i = 0; i < convexHullSize; i++)
            {
                if (convexHullChan[i] == convexHullGrahamScan[i])
                    continue;
                pass = false;
                break;
            }
        }
        if (pass)
            cout << "OK";
        else
        {
            cout << "Failed" << endl;
            exit(1);
        }
        fflush(stdout);
    }
    cout << endl;
    cout << "All tests passed" << endl;
    return 0;
}