#include <bits/stdc++.h>
#define int long long
#include <map>
#define nl '\n'
#define double float
using namespace std;

class TSP {
    private:

    int n;
    vector<vector<double>> w;
    public:

    TSP(int ne, vector<vector<double>> we) {    
        this->w = we;
        n = ne;
    }

    double getTour() {
        map<pair<int, int>, double> dp;
        vector<set<int>> pS(n + 1);
        pS[1].insert(1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int a : pS[i - 1]) {
                    int add = a ^ (int)pow(2, j - 1);
                    if (add > a) {
                    pS[i].insert(add);}
                }
            }
        }
        for (set<int> a : pS) {
            for (int b : a) {
                if (b == 1) {
                    dp[make_pair(b, 1)] = 0;
                } else {
                    dp[make_pair(b, 1)] = INT_MAX;
                }
            }
        } 
        dp[make_pair(1, 1)] = 0;

        for (int e = 2; e <= n; e++) {
            set<int> a = pS[e];
            for (int aa : a) {
                int iter = 1;
                int b = aa;
                aa = aa >> 1; // skip 1
                while (aa > 0) {
                    iter++;
                    if (aa % 2 == 1) {
                        int c = iter;
                        int a_star = b - pow(2, c - 1);
                        double ans = INT_MAX;
                        int bb = a_star;
                        int iterb = 0;
                        for (;bb > 0; bb = bb >> 1) {
                            iterb++;
                            if (bb % 2 == 1) {
                                if (dp[make_pair(a_star, iterb)] == INT_MAX) continue;
                                ans = min(ans, dp[make_pair(a_star, iterb)] + w[(int)iterb][c]);
                            }
                        }
                        dp[make_pair(b, c)] = ans;
                    }
                    aa = aa >> 1;
                }
            } 
        }
        int f = 0;
        for (int i = 0; i < n; i++) {
            f += pow(2, i);
        }
        double ans = INT_MAX;
        for (int i = 2; i <= n; i++) {
            ans = min(ans, dp[make_pair(f, i)] + w[i][1]);
        }
        return ans;
    }
};

struct Point {
    double x, y, n;
    Point(double m_x, double m_y, double m_n) {
        x = m_x;
        y = m_y;
        n = m_n;
    }
};

double distanceTo(Point that, Point thot) {

    return pow((that.x - thot.x), 2) + pow((that.y - thot.y), 2);
}
auto start = chrono::high_resolution_clock::now();
int32_t main() {
    ifstream fin("tsp2.in");
    ofstream fout("tsp2.out");
    int n;
    fin >> n;
    vector<Point> allpoints;
    for (int i = 0; i < n; i++) {
        double x, y;
        fin >> x >> y;
        Point np(x, y, i);
        allpoints.push_back(np);
    }
    vector<double> temp(n);
    vector<vector<double>> w0_12(14, temp);
    vector<vector<double>> w11_24(15, temp);
    for (int i = 0; i <= 12; i++) {
        for (int j = 0; j <= 12; j++) {
            w0_12[i + 1][j + 1] = sqrt(distanceTo(allpoints[i], allpoints[j]));
        }
    }
    for (int i = 0; i <= 13; i++) {
        for (int j = 0; j <= 13; j++) {
            w11_24[i + 1][j + 1] = sqrt(distanceTo(allpoints[i + 11], allpoints[j + 11]));
        }
    }
    TSP tsp1(13, w0_12);
    TSP tsp2(14, w11_24);
    auto end = chrono::high_resolution_clock::now();
    cout << tsp1.getTour() + tsp2.getTour() - (2 * sqrt(distanceTo(allpoints[11], allpoints[12]))) << nl;
    cout << "took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;
}
