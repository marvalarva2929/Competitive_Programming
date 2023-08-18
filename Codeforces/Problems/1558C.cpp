#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2021;
int a[mxn];

void rev(int i, int j, vector<int>& ans) {

    if (i == j) return;
    reverse(a + i, a + j + 1);
    

    ans.push_back(j);
    if (i != 0)
        ans.push_back(j - i), 
        ans.push_back(j);
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        if (a[i] % 2 == i % 2) {
            cout << -1 << nl;
            return;
        }
    
    vector<int> moves;
    
    for (int i = n; i > 1; i -= 2) {
        int t1, t2;

        for (int j = 0; j < n; j++)
            if (a[j] == i) t1 = j;
            else if (a[j] == i - 1) t2 = j;
    
        if (t1 == i - 1 && t2 == i - 2) continue; 

        if (t1 > t2) {
            rev(t2 + 1, t1, moves);
            rev(0, t2 + 1, moves);
            rev(0, i - 1, moves);
        } else {
            rev(0, t1, moves);
            rev(0, t2 - 1, moves);
            rev(t2 - 1, i - 1, moves);
        }
    }
    
    cout << moves.size() << nl;
    for (int move : moves)
        cout << move + 1 << " ";
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
