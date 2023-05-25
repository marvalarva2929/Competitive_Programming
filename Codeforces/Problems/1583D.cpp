#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

int query(vector<int> q) {
    cout << "?";
    for (int x : q)
        cout << " " << x;
    cout << endl;

    int k; cin >> k;
    return k;
}

void answer(vector<int> a) {
    cout << "!";
    for (int x : a)
        cout << " " << x;
    cout << endl;
}

signed main() {
    int n; cin >> n;

    vector<int> z(n, 1), o(n, 2);
    vector<int> ans(n);
    vector<int> next(n, -1);

    for (int i = 0; i < n; i++) {
        z[i] = 2, o[i] = 1; 
        int greater = query(z) - 1;
        int prev = query(o) - 1;
        o[i] = 2, z[i] = 1;
        
        if (greater == -1) {
            ans[i] = n;
        } else if (greater != i) next[i] = greater;

        if (prev == -1) {
            ans[i] = 1;
        } else if (prev != i) next[prev] = i;

    }
    
    int cur = -1;
    int nex = 1; 
    for (int i = 0; i < n; i++)
        if (ans[i] == 1) {
            cur = i;
            break;
        }

    while (next[cur] != -1)
        cur = next[cur],
        ans[cur] = ++nex;

    answer(ans);
}
