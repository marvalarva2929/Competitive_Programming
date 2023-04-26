using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define f first
#define s second

int n, k;

bool grids[10][10][10] = {};
vector<vector<bool>> grid(8, vector<bool>(8));

bool get(int i, int x, int y) {
    return x < n && x >= 0 && y >= 0 && y < n && grids[i][x][y];
}

signed main() {
    ifstream cin("bcs.in");
    ofstream cout("bcs.out");

    cin >> n >> k;


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            { char c; cin >> c; grid[i][j] = (c == '#'); }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++)
            for (int l = 0; l < n; l++) {
                char c; cin >> c;
                grids[i][j][l] = (c == '#');
            }
    }

    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++)
            for (int x1 = -n + 1; x1 < n; x1++) {
                for (int y1 = -n + 1; y1 < n; y1++) {
                    for (int x2 = -n + 1; x2 < n; x2++) {
                        for (int y2 = -n + 1; y2 < n; y2++) {
                            bool works = true;
                            for (int x = 0; x < n && works; x++)
                                for (int y = 0; y < n && works; y++) {
                                    int xx1 = x1 + x, xx2 = x2 + x, yy1 = y1 + y, yy2 = y2 + y;
                                    bool gridI = get(i, xx1, yy1);
                                    bool gridJ = get(j, xx2, yy2);

                                    if (gridI && gridJ) works = false;
                                    if (grid[x][y] != (gridI || gridJ)) works = false;
                                }

                            if (works) { cout << i + 1 << " " << j + 1 << nl; return 0; }
                        }
                    }
                }
            }
            
}   