#include <bits/stdc++.h>

using namespace std;

const int mxn = 2e5;
int a[mxn];

signed main() {
    int n; cin >> n; n--;
    a[n] = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    for (int i = 0; i < n+1; i++)
        if ((i + 1) != a[i]) {
            cout << i + 1 << endl;
            return 0;
        }
}




