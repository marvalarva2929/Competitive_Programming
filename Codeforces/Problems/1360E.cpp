#include <iostream>
#include <vector>
#define nl '\n'
using namespace std;
vector<bool> temp(50, 0);
int grid[50][50];

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> toCheck;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            char a;
            cin >> a;
            grid[i][j] = a - '0';
            if (grid[i][j] == 1) {
                toCheck.push_back({i, j});
            }
        }
    }

    bool yes = true;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            if (grid[i + 1][j] == 0 && grid[i][j + 1] == 0 && grid[i][j] == 1) {
                cout << "NO" << nl;
                return;
            }
        }
    }
    if (yes) cout << "YES" << nl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}