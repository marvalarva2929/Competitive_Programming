using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)5e6 + 10
bool isComp[MAX];
vector<int> p;
bool isWin[MAX];

void solve() {
    int n; cin >> n;
    int rooms[n] = {};
    for (int i = 0; i < n; i++)
        cin >> rooms[i];

    

}

signed main() {
    // cin.tie(0)->sync_with_stdio(false);

    for (int i = 2; i < MAX; i++)
        if (!isComp[i]) {
            p.push_back(i);
            for (int j = i + i; j < MAX; j += i)
                isComp[j] = true;
        }

    for (int i = 0; i < MAX; i++)
        isWin[i] = i % 4;
    

    int t; cin >> t;
    while (t--)
        solve();
}