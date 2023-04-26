#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#define nl "\n"
using namespace std;

struct Point{
    int x;
    int y;
};

double distanceBetwean(Point one, Point two) { return sqrt(pow(one.x - two.x, 2) + pow(one.y - two.y, 2)); }

void exch(int i, int j, vector<Point> &a) {
    Point temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


struct Pair {
    Point one;
    Point two;
    double delta;
};

vector<Point> sortByY(int low, int high, int n, vector<Point> a) {
    if (high - low == 1) return {a[low]};

    vector<Point> a1 = sortByY(low, (high+low)/2, n/2, a);
    vector<Point> a2 = sortByY((high+low)/2, high, n - n/2, a);
    vector<Point> c(n);
    int i = 0, j = 0, k = 0;
    for (int q = 0; q < n; q++) {
      if ((a1[i].y < a2[j].y || j >= a2.size()) && i < a1.size()) {
        c[k] = a1[i];
        k++;
        i++;
      } else if ((a2[j].y <= a1[i].y || i >= a1.size()) && j < a2.size()) {
        c[k] = a2[j];
        k++;
        j++;
      }
    }
    return c;
}


vector<Point> sortByX(int low, int high, int n, vector<Point> a) {
    if (high - low == 1) return {a[low]};

    vector<Point> a1 = sortByX(low, (high+low)/2, n/2, a);
    vector<Point> a2 = sortByX((high+low)/2, high, n - n/2, a);
    vector<Point> c(n);
    int i = 0, j = 0, k = 0;
    for (int q = 0; q < n; q++) {
      if ((a1[i].x < a2[j].x || j >= a2.size()) && i < a1.size()) {
        c[k] = a1[i];
        k++;
        i++;
      } else if ((a2[j].x <= a1[i].x || i >= a1.size()) && j < a2.size()) {
        c[k] = a2[j];
        k++;
        j++;
      }
    }
    return c;
}



vector<Point> copy(vector<Point> copyFrom, int start, int end) {
    vector<Point> copied(end - start);
    for (int i = start; i < end; i++) {
        copied[i] = copyFrom[i];
    }
    return copied;
}

Pair findClosestSplitPair(vector<Point> byX, vector<Point> byY, int barX, double delta) {
    int left = barX;
    int right = barX;
    cout << "bar x is : " << barX << " and delta is: " << delta << nl;
    while(abs(byX[barX].x - byX[left].x) < byX[barX].x - delta && left > 0) left--;
    while(abs(byX[barX].x - byX[right].x) < byX[barX].x + delta && right < byX.size() - 1) right++;
    cout << left << " " << right << nl;
    vector<Point> strip(byX.begin() + left, byX.begin() + right);
    for (Point n : strip) cout << n.x << ", " << n.y << " ";
    cout << nl;
    strip = sortByY(0, strip.size(), strip.size(), strip);
    Pair m;
    m.delta = INT_MAX;
    for (int i = 1; i < min(7, (int) strip.size()); i++) {
        cout << "comparing " << strip[i].x << ", " << strip[i].y << " with " << strip[i+1].x << ", " << strip[i+1].y << nl;
        if(distanceBetwean(strip[i], strip[i + 1]) < m.delta) {
            m.one = strip[i];
            m.two = strip[i +1];
            m.delta = distanceBetwean(strip[i], strip[i + 1]); 
        }
    }
    cout << m.delta << nl;
    return m;
}

Pair findClosestPair(vector<Point> byX, vector<Point> byY, int n) {
    cout << n << ": ";
    if (n <= 3) {
        Pair min;
        min.delta = INT_MAX;
        for (int i = 0; i < byX.size(); i++) {
            for (int j = 0; j < byX.size(); j++) {
                if(distanceBetwean(byX[i], byX[j]) < min.delta && j != i) {
                    min.one = byX[i];
                    min.two = byX[j];
                    min.delta = distanceBetwean(byX[i], byX[j]); 
            }
        }
    }
    return min;
    } else {
        Pair closestX = findClosestPair(vector<Point>(byX.begin(), byX.begin() + n/2), byY, n/2);
        Pair closestY = findClosestPair(vector<Point>(byX.begin() + n/2, byX.end()), byY, n - n/2);
        Pair closestNonSplit = closestX.delta < closestY.delta ? closestX : closestY;
        Pair closestSplit = findClosestSplitPair(byX, byY, n/2, closestNonSplit.delta);
        return closestSplit.delta > closestNonSplit.delta ? closestNonSplit : closestSplit;
    }
}

int main() {
    int n;
    cin >> n;
    vector<Point> points;
    vector<Point> byY;
    vector<Point> byX;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >>y;
        Point p = {x, y};
        points.push_back(p);
        byY.push_back(p);
        byX.push_back(p);
    }

    byX = sortByX(0, n, n, byX);
    byY = sortByY(0, n, n, byY);
    // for (Point p : byX) cout << p.x << ", " << p.y << nl;
    Pair closest = findClosestPair(byX, byY, n);
    // Pair min;
    //     min.delta = INT_MAX;
    //     for (int i = 0; i < byX.size() - 1; i++) {
    //         if(distanceBetwean(byX[i], byX[i + 1]) < min.delta) {
    //             min.one = byX[i];
    //             min.two = byX[i +1];
    //             min.delta = distanceBetwean(byX[i], byX[i + 1]); 
    //         }
    //     }
    cout << "( " << closest.one.x << ", " << closest.one.y << " )" <<  " to "  << "( " << closest.two.x << ", " << closest.two.y << " )" << nl;
}