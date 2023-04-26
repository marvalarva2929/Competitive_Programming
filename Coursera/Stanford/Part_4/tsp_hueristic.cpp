using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define MAX (int)1e6 + 10
#define double double
bool visited[MAX];

struct Point {
    double x, y;
    int index;
    bool visited = false;
    Point(double m_x, double m_y, int i) {
        x = m_x, y = m_y;
        index = i;
    }

};

vector<Point> adj[MAX];

double sq(double a) {
    return (double)a * a;
}   

double distanceBetween(Point that, Point thot) { // returns squared distance
    return sqrt(sq(thot.x - that.x) + sq(thot.y - that.y));
}

int32_t main() {
    ifstream cin("tsph.txt");
    // ofstream cout("tsph.out");


    int n;
    cin >> n;
    vector<Point> points;
    for (int i = 0; i < n; i++) {
        double l, x, y; cin >> l >> x >> y;
        Point newPoint(x, y, i);
        points.push_back(newPoint);
    }

    // vector<pair<double, double>> xy;
    // for (int i = 0; i < n; i++) {
    //     double l, x, y; cin >> l >> x >> y;
    //     xy.push_back({x, y});
    // }
    // sort(xy.begin(), xy.end());
    // for (int i = 0; i < n; i++) {
    //     Point newpoint(xy[i].first, xy[i].second, i);
    //     points.push_back(newpoint);
    // }
    // cout << points.size() << nl;
    auto start = chrono::high_resolution_clock::now();

    Point curr = points[0];
    double tourDist = 0;
    int vis = 0;
    while(vis != n) {
        visited[curr.index] = true;
        vector<Point> neighbors;
        Point closest(0, 0, -1);
        double minDist = -1;

        // for (Point point : points) {
        //     if (!visited[point.index] && point.index != curr.index) {
        //         double dub = distanceBetween(curr, point);
        //         if (dub < minDist || minDist == -1 ) {
        //             minDist = dub;
        //             closest = point;
        //         } else if (dub == minDist && point.index < closest.index) {
        //             minDist = dub;
        //             closest = point;
        //         }
        //     }
        // }

        for (int i = curr.index; i >= 0; i--) {
            double dub = distanceBetween(curr, points[i]);
            if (visited[i]) continue;
            else if (abs(points[i].x - curr.x) > minDist && minDist != -1) 
                break;
            else if (dub <= minDist || minDist == -1) {
                minDist = dub;
                closest = points[i];            
            }
        }
        for (int i = curr.index; i < n; i++) {
            double dub = distanceBetween(curr, points[i]);
            if (visited[i]) continue;
            else if (abs(points[i].x - curr.x) > minDist && minDist != -1) 
                break;
            else if (dub < minDist || minDist == -1) {
                minDist = dub;
                closest = points[i];            
            }
        }
        // cout << curr.index << " : " << closest.index << " :  " << minDist << nl;
        if (minDist == -1) {
            tourDist +=(distanceBetween(curr, points[0]));
        } else {
            tourDist += (minDist);
            curr = closest;
        }    
        vis++;
        // if (vis == n) cout << minDist << nl;
        // cout << curr.index << " : " << closest.index << nl;
    }   

    cout << fixed<< tourDist << " :" << curr.index << " : " << vis << nl;
    auto end = chrono::high_resolution_clock::now();

    // cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << nl;
    
} 