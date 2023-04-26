using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<long long, long long>
#define vi vector<long long>
#define vpi vector<pi>
#define MAX (int)1e3 + 10

pi hw[(int)1e5 + 10];
int sumAt[MAX][MAX];

const int dx[2] = {-1, 0}, dy[2] = {0, -1};

void solve() {
    int n, q; cin >> n >> q;
    memset(sumAt, 0, sizeof sumAt);

    for (int i = 0; i < n; i++) {
        int h, w; cin >> h >> w;
        sumAt[h + 1][w + 1] += h * w;
    }

    for (int i = 1; i < MAX; i++)
        for (int j = 1; j < MAX; j++) {
            for (int k = 0; k < 2; k++) 
                sumAt[i][j] += sumAt[i + dx[k]][j + dy[k]];
            sumAt[i][j] -= sumAt[i - 1][j - 1];
        }

    for (int i = 0; i < q; i++) {
        int h1, w1, h2, w2; cin >> h1 >> w1 >> h2 >> w2;
        cout << sumAt[h2][w2] + sumAt[h1 + 1][w1 + 1] - sumAt[h1 + 1][w2] - sumAt[h2][w1 + 1] << nl;
    }

    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}