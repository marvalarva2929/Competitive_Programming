#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;
    
int query(int a, int b, int c) {
    cout << "? " << a + 1 << " " << b + 1  << " " << c + 1 << endl;
    cout.flush();
    
    int x; cin >> x;
    return !x;
}

void answer(vector<int> toAns) {
    cout << "! " << toAns.size();
    for (int ans : toAns)
        cout << " " << ans + 1;
    cout << endl;
}
    
void solve() {
    int n; cin >> n;
    int wait = -1;
    int ky, kn;
    vector<int> ans;
    
    for (int i = 0; i < n - 2; i++) {
         int res = query(i, i + 1, i + 2);
         if (res == -1)
             return;
         if (res == wait) {
              ky = i + 2,
              kn = i - 1;
              if (!res)
                 swap(ky, kn);

               ans.push_back(ky);
              break;
         }
         wait = !res;
    }
    
    for (int i = 0; i < n; i++)
        if (i != ky && i != kn)
            if (query(ky, kn, i))
                ans.push_back(i);

    answer(ans);
    return;

}

signed main() {
    int t; cin >> t;
    while (t--)
        solve();
}
