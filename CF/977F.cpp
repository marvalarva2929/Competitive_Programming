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
#define f first
#define s second
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

unordered_map<int, int> dp;
unordered_map<int, int> nexto;
int32_t main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        dp[nums[i]] = 0;
    }   
    int m = 0;
    int lst = 0;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        dp[num] = max(dp[num - 1] + 1, dp[num]);
        if (dp[num] > m) {
            m = dp[num];
            lst = num;
        }
    }
    vector<int> ans;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] == lst) {
            lst--;
            ans.push_back(i + 1);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << m << nl;
    print(ans, 0, ans.size() - 1);
} 