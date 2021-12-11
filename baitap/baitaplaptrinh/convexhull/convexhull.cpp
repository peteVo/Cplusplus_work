#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>

using namespace std;

struct pt // The point struct
{
    double x, y;
};

bool cmp(pt a, pt b) // Checks a.x < b.x or if they're equal -> check a.y < b.y
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

bool cw(pt a, pt b, pt c) // Check if points a, b and c are clockwise or not
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(pt a, pt b, pt c) // Check if points a, b and c are counter-clockwise or not
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void Solve(vector<pt> &a)
{
    // Sort the array of points according to the function cmp
    sort(a.begin(), a.end(), &cmp);

    // Get the first and the last points of the array
    pt p1 = a[0], p2 = a.back();

    // Initialize up and down -> stores the array of points that
    // makes the hull (the upper part and the lower part)
    vector<pt> up, down;
    up.push_back(p1), down.push_back(p1);

    for(unsigned i = 0, len = a.size(); i < len; ++i){
        // Add to upper part
        if(i == len - 1 || cw(p1, a[i], p2)){ // Checks if "at the last point" or "in the UPPER part"
            while(up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }

        // Add to lower part
        if(i == len - 1 || ccw(p1, a[i], p2)){ // Checks if "at the last point" or "in the LOWER part"
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    // Combine up and down to one single vector
    a.clear();
    for(int i = 1, len = up.size(); i < len; ++i){
        a.push_back(up[i]);
    }
    for(int i = down.size() - 2; i >= 0; --i){
        a.push_back(down[i]);
    }

    double sum = 0;
    // Calculate the area
    for(int i = 0, len = a.size(); i < len; ++i){
        sum = sum + (a[(i+1)%len].x - a[i].x) * (a[(i+1)%len].y + a[i].y);
    }
    sum /= 2.0;

    // Print out the results
    cout << a.size() << endl;
    cout << fixed << setprecision(1) << sum << endl;
    cout << setprecision(0);
    for(int i = a.size() - 1; i >= 0; --i){
        cout << a[i].x << " " << a[i].y << endl;
    }
}

int main()
{
    freopen("convexhull.inp", "r", stdin);
    freopen("convexhull.out", "w", stdout);

    //set<pt> set_points;
    vector<pt> points;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        pt p;
        cin >> p.x >> p.y;
        points.push_back(p);
        //set_points.insert(p);
    }

    Solve(points);

    return 0;
}
