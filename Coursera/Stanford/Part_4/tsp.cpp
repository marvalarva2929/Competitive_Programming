#include <bits/stdc++.h>
#define nl '\n'
#define MAX (int)1e3
using namespace std;
int w[MAX][MAX];


auto start = chrono::high_resolution_clock::now();

int main() {
    ifstream fin("tsp.in");
    ofstream fout("tsp.out");
    int n, m;
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, l;
        fin >> x >> y >> l;
        w[x][y] = l;
        w[y][x] = l;
    }
    cout << 'g' << nl;
        map<pair<int, int>, double> dp;
        vector<set<int>> pS(n + 1);
        pS[1].insert(1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int a : pS[i - 1]) {
                    int add = a ^ (int)pow(2, j - 1);
                    // cout << i << ": " << add << nl;
                    if (add > a) pS[i].insert(add);
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
        cout << 'h' << nl;

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
                        cout << b << ": " << c << ": " << a_star << nl;
                        double ans = INT_MAX;
                        int bb = a_star;
                        int iterb = 0;
                        for (;bb > 0; bb = bb >> 1) {
                            iterb++;
                            if (bb % 2 == 1) {
                                cout << " -- " << iterb << ": " << bb << nl;
                                if (dp[make_pair(a_star, iterb)] == INT_MAX) continue;
                                ans = min(ans, dp[make_pair(a_star, iterb)] + w[(int)iterb][c]);
                            }
                        }
                        dp[make_pair(b, c)] = ans;
                        cout << "S of " << e << ": { ";
                        // int iterc = 0;
                        // int bc = b;
                        // while (bc > 0) {
                        //     iterc++;
                        //     if (bc % 2 == 1) cout << iterc << ", ";
                        //     bc = bc >> 1;
                        // }
                        cout << "} has a tour of distance " << ans << " with respect to " << c << nl;
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
    cout << "The minimum tour of the traveling salesman is " << ans << nl;

    auto end = chrono::high_resolution_clock::now();

    cout << "Took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;

}