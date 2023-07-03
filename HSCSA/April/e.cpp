#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

const int mxn = 1e3;
char ans[mxn][mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k; cin >> n >> k;

    int acc = n + n;
    int cur = n;

    if (k == n/2 || k == n)
        goto skip;

    while (cur && acc != (k * 2)) {
        for (int i = 0; i < 4; i++) {
            acc += cur - 2;
            if (acc == (k * 2))
                goto skip;
        }

        cur -= 2;
        //cout << acc << nl;
    }


    if (acc != (k * 2)) { cout << "NO" << nl; return 0; }

skip:

    cout << "YES" << nl;

    int depth = 0;
    
    while (k > 0) {
        
        for (int j = depth; j < n - depth; j += 2)
            ans[depth][j] = 'L',
            ans[depth][j + 1] = 'R',
            k--;

        if (!k) break;

        for (int j = depth; j < n - depth; j+= 2)
            ans[n - depth - 1][j] = 'L',
            ans[n - depth - 1][j + 1] = 'R',
            k--;

        if (!k) break;

        depth++;

        for (int i = depth; i < n - depth; i += 2)
            ans[i][depth - 1] = 'U',
            ans[i + 1][depth - 1] = 'D',
            k--;

        if (!k) break;

        for (int i = depth; i < n - depth; i += 2)
            ans[i][n - depth] = 'U',
            ans[i + 1][n - depth] = 'D',
            k--;
    }

    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++) 
            cout << (ans[i][j] ? ans[i][j] : '.');
        cout << nl;
    }
}
