#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 5e5;
int a[mxn], b[mxn];

signed main() {
    int n, k; cin >> n >> k;
    set<int> ia, ib;
    int ans = 0;

    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        a[i] = x;
        ia.insert(a[i]); 
    }
    
    map<pi, int> next;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        b[i] = x;  
        if (i) next[{b[i], b[i - 1]}] = 1; 
        ib.insert(b[i]);  
    }
    next[{b[0], b[k - 1]}] = 1;
    
    int cur = 0;

    int j = 0;
    while (j < k) {
        int i = j;
        int c = 0;
        set<int> in;

        while (c < k && next[{a[i], a[(i + 1) % k]}]) in.insert(a[i]), in.insert(a[(i + 1) % k]), i++, c++;
        ans += in.size(); 
        j = i + 1;    
    }
    
    for (int i = 1; i <= n; i++)
        if (ia.count(i) + ib.count(i) == 0)
            ans++;
    
    int ans2 = ans;

    for (int i = 0; i < k; i++)
        next[{b[i], b[(i + 1) % k]}] = 1;


    {
        int ans = 0;

        int j = 0;
        while (j < k) {
            int i = j;
            int c = 0;
            set<int> in;

            while (c < k && next[{a[i], a[(i + 1) % k]}]) in.insert(a[i]), in.insert(a[(i + 1) % k]), i++, c++; 
            ans += in.size();
            j = i + 1;    
        }

        for (int i = 1; i <= n; i++)
            if (ia.count(i) + ib.count(i) == 0)
                ans++;
        
        ans2 = max(ans, ans2);
    }
    
    cout << ans2 << endl;
}
