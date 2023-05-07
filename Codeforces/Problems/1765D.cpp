#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define f first
#define s second
#define int long long
#define MAX (int)2e5 + 10
#define print(x) for (auto a : x) {cout << a << " "; } cout << nl;
#define MAX (int)2e5 + 10
int a[MAX];
int n, m;

bool f(int x) {
    int j = n - 1;
    for (int i = x - 1; i < n && i < j; i++) {
        if (a[i] + a[j] > m)
            return false;
        j--;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    
    sort(a, a + n, greater<int>());

    int l = 1, r = n;
    while(l < r) {
        int m = (l + r)/2;
        if (f(m))
            r = m;
        else 
            l = m + 1;
    }
    
    cout << sum + r << nl;
}