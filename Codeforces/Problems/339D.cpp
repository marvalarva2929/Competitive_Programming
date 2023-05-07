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
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl
#define MAX (int)pow(2, 17) + 10
int n;

void calc(vector<int>& nums) {
    int l = n/2;
    int iter = 0;
    while (l >= 1) {
        int i = l;
        for (int i = l; i < l * 2; i++) {
            if (iter % 2 == 0) nums[i] = nums[i * 2] | nums[i * 2 + 1];
            else nums[i] = nums[i * 2] ^ nums[i * 2 + 1];
        }
        iter++;
        l /= 2;
    }

}

int recalc(int p, int b, vector<int> &nums ) {
    p = p + n - 1 + (p + n - 1  % 2);
    p /= 4;
    int iter = 0;
    while (p >= 1) {
        if (iter % 2 == 0) nums[p] = nums[p * 2] | nums[p * 2 + 1];
        else nums[p] = nums[p * 2] ^ nums[p * 2 + 1];
        iter++;
        p /= 2;
    }
    // print(nums, 1, n * 2 - 1);
    return nums[1];
}



int32_t main() {
    int m;
    cin >> n >> m;
    n = pow(2, n);
    vector<int> nums(2 * n);
    for (int i = n; i < n * 2; i++) {
        cin >> nums[i];
    }
    calc(nums);
    // print(nums, 1, n * 2 - 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        nums[a + n - 1] = b;
        cout << recalc(a, b, nums) << nl;
    }
} 