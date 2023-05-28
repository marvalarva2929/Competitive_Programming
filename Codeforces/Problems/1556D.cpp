#include <bits/stdc++.h>
#define int long long
#define nl endl

using namespace std;

int query(bool type, int i, int j) {
    if (type)
        cout << "and " << i + 1 << " " << j + 1 << nl;
    else cout << "or " << i + 1 << " " << j + 1 << nl;
    int ret; cin >> ret;
    return ret;
}

void answer(int v) {
    cout << "finish " << v << nl;
}

signed main() {
    int n, k; cin >> n >> k;
    vector<int> ans(n);

    for (int i = 0; i < n - (n % 3); i += 3) {
        int both[3][3]; // and
        int either[3][3]; // or
        for (int j = 0; j < 3; j++)
            for (int k = j + 1; k < 3; k++)
                both[j][k] = both[k][j] = query(1, i + j, i + k),
                either[j][k] = either[k][j] = query(0, i + j, i + k);
        
        for (int j = 0; j < 3; j++) {
            int a =  (i + j) % 3;
            int b = (i + j + 1) % 3;
            int c = (i + j + 2) % 3;
            
            ans[b + i] = (both[a][b] | both[b][c]) | ((either[a][b] | either[b][c]) - either[a][c]);
        }
    }
    
    for (int i = n - (n % 3); i < n; i++) {
        ans[i] = (ans[0] ^ (query(0, 0, i) - query(1, 0, i)));     
    }
    
    sort(ans.begin(), ans.end());

    answer(ans[k - 1]); 
}

