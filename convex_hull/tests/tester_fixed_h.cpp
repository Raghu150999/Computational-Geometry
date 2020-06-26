#include <bits/stdc++.h>
#include "GrahamScan.hpp"
#include "Chan.hpp"

using namespace std;

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));
    if (argc < 4)
    {
        cout << "Usage: ./tester.o n h numTests" << endl;
        return 0;
    }
    int numTests = atoi(argv[3]);
    // Number of points to be used
    int h = atoi(argv[2]);
    int n = atoi(argv[1]) - h;
    long long maxa = 1e6;
    long long maxr = 1e7;
    for (int t = 1; t <= numTests; t++)
    {
        cout << "\rTest " << t << ": ";
        set<pair<long long, long long>> data;
        for (int i = 1; i <= n; i++)
        {
            long long x = (rand() % maxa) * ((rand() % 2 > 0) ? 1 : -1);
            long long y = (rand() % maxa) * ((rand() % 2 > 0) ? 1 : -1);
            data.insert({x, y});
        }
        // Generate h points on a circle with radius maxr
        for(int i = 1; i <= h; i++)
        {
            long long x = (rand() % maxr) * ((rand() % 2 > 0) ? 1 : -1);
            long long y = sqrt(maxr * maxr - x * x) * ((rand() % 2 > 0) ? 1 : -1);
            data.insert({x, y});
        }
        vector<Point<long long>> points;
        ofstream datafile;
        datafile.open("./tests/data.txt");
        datafile << data.size() << "\n";
        for (auto point : data)
        {
            points.push_back(Point<long long>(point.first, point.second));
            datafile << point.first << " " << point.second << "\n";
        }
        datafile << endl;
        datafile.close();
        vector<Point<long long>> convexHullGrahamScan = GrahamScan<long long>(points).getConvexHull();
        vector<Point<long long>> convexHullChan = Chan<long long>(points).getConvexHull();
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