#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define YES "YES"
#define NO "NO"

using namespace std;

const int mxk = 20;
int c[mxk];
int x[mxk];

void solve() {
    int n, k; cin >> n >> k;
    string ans;

    for (int i = 0; i < k; i++)
        cin >> x[i];
    for (int i = 0; i < k; i++)
        cin >> c[i];

    if (c[0] > x[0]) {
        cout << NO << nl;
        return;
    }
    
    for (int i = 0; i < k - 1; i++)
        if (x[i + 1] - x[i] < c[i + 1] - c[i]) {
            cout << NO << nl;
            return;
        }


    char curAdd = 'a';
    char list[3] = {'a', 'b', 'c'};
    int j = 0;
    int prev = c[0];
    
    for (int i = 0; i < c[0] - 3; i++)
        ans += curAdd;
    ans += "abc";
    while (ans.size() < x[0])
        ans += list[j++ % 3];
    curAdd = 'd';
    
 //   cout << ans << nl;

    for (int i = 1; i < k; i++) {
        int add = c[i] - prev; 
       
//        cout << i << " : " << c[i] << " " << prev << nl;
        prev = c[i];
        

        for (int k = 0; k < add; k++)
            ans += curAdd;
        ++curAdd;
         
        while (ans.size() != x[i])
            ans += (list[(j++ % 3)]);
    }
    cout << "YES" << nl; 
    cout << ans << nl;
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
