using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define no "NO"
#define yes "YES"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

vpi check(int n, vector<int> nums, int x) {
    multiset<int> s;
    vpi ans;
    for (int num : nums)
        s.insert(num);

    for (int i = 0; i < n; i++) {
        auto it1 = s.end();
        it1--;
        // cout << i << " : " << x << " :" << *it1 << nl;
        int y = x - *it1;
        s.erase(it1);
        auto it2 = s.find(y);
        if (it2 == s.end()) 
            return {};
        
        ans.push_back({x - y, y});
        s.erase(it2);
        x = max(x - y, y);
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> nums(n * 2);
    for (int i = 0; i < n * 2; i++)   
        cin >> nums[i];

    sort(nums.begin(), nums.end());    

    for (int i = 0; i < (n  * 2) - 1; i++) {
        int x = nums.back() + nums[i];
        auto ans = check(n, nums, x);
        if (ans.size()) {
            cout << yes << nl;
            cout << x << nl;
            for (auto p : ans) {
                cout << p.first << " " << p.second << nl;
            }
            return;
        }
    }
    cout << no << nl;
    return;
}

int32_t main() {
    int t; cin >> t;
    while (t--)
        solve();
} 