#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define ff first
#define ss second

using namespace std;
const int mxn = 10, mxc = 2e5, mxm = 1e5;

template <class T> using v = vector<T>;
template <class T, class S> using p = pair<T, S>;
int n, m;

v<v<int>> a;

void set_max(vector<int>& x, vector<int> y) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i][x[i]];
   
    int s2 = 0;
    for (int i = 0; i < n; i++)
        s2 += a[i][x[i]];
    
    if (s2 > s) x = y;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
 
    a = v<v<int>>(n);
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x; 
        a[i].resize(x);
        for (int j = 0; j < x; j++) 
            cin >> a[i][j];
    }
    
    cin >> m;
    v<v<int>> ban(m, v<int>(n));
    v<v<int>> av(n, v<int>(1 << n));
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> ban[i][j], ban[i][j]--;
    
    sort(ban.begin(), ban.end());
    
    {
        v<int> ch;
        for (int i = 0; i < n; i++)
            ch.push_back((int)a[i].size() - 1);

        if (!binary_search(ban.begin(), ban.end(), ch)) {
            for (int i = 0; i < n; i++)
                cout << ch[i] + 1 << " ";
            cout << nl;
            return 0;
        } 
    }
    
    p<int, v<int>> mx = {0, v<int>(n, -1)};

    for (int i = 0; i < m; i++) {
        int s = 0;
        v<int> t = ban[i];
        
        for (int j = 0; j < n; j++)
            s += a[j][t[j]];
    

        for (int j = 0; j < n; j++) {
            if (t[j] == 0) continue;
            t[j]--;
            
            int ns = s + a[j][t[j]] - a[j][t[j] + 1];
            
            if (!binary_search(ban.begin(), ban.end(), t)) 
                mx = max(mx, {ns, t}); 
            
            t[j]++; 
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << mx.ss[i] + 1 << " ";
    } 
    cout << nl;
}
