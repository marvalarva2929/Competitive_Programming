#include <bits/stdc++.h>
#define int long long

using namespace std;
const int mxn = 1e6;
int a[mxn+1];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0; 
    }
    if (n <= 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    
    int h = (n + 1)/2;
    int c = 1;

    for (int i = 0; i < (n + 1)/2; i++) {
   
        if (!(n % 2)) a[i + h] = c++;
        a[i] = c++;
        if (n % 2) a[i + h] = c++;  
    }
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
}
