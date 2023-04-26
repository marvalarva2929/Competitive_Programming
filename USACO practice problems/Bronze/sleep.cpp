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

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m = INT_MIN;
        cin >> n;
        vector<int> nums(n + 1);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> nums[i];
            sum += nums[i];
        }
        for (int i = n; i >= 1; i--) {
            if (sum % i == 0) {
                int des = sum/i;
                int curr = 0;
                bool yes = true;
                for (int r = 1; r <= n; r++){
                    curr += nums[r];
                    // cout << i << ": " << curr << ": " << yes << nl;
                    if (curr > des) { yes = false; break;}
                    else if (curr == des) curr = 0;
                }
                if (yes) {
                    cout << n - i << nl;
                    break;
                }
            }
        }
    }
} 
