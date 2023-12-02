#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1000;

int findmax(vector<vector<int>> a) {
    int ret = 0;
    vector<vector<int>> ros(a.size(), vector<int>(2));
    
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size(); j++)
            ros[i][j % 2] += a[i][j];

    for (int i = 0; i < a.size(); i++)
        ret += max(ros[i][0], ros[i][1]);

    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n,0));
    vector<vector<int>> b(n, vector<int>(n,0));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j], b[j][i] = a[i][j];
    
    cout << max(findmax(a), findmax(b)) << endl; 
}
