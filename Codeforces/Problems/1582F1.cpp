#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

const int mxa = (1 << 13);

vector<int> aval[mxa + 1];
int lim[mxa + 1];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    fill(lim, lim + mxa, mxa);
    
    for (int i = 0; i <= mxa; i++)
        aval[i].push_back(0);

    set<int> ans;
    ans.insert(0);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int next : aval[x]) {
            int to = next ^ x;
            ans.insert(to);
            while (lim[to] > x)
                aval[lim[to]].push_back(to),
                lim[to]--;
        }
        aval[x] = {};
    }
   
    cout << ans.size() << nl;
    for (int a : ans)
        cout << a << " ";
    cout << nl;
    
}
