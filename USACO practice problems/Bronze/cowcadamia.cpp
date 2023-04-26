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
#define MAX (int)2e5
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
int nums[MAX];

int hIndex(int n) {
    int h = n;
    while (h > 0 && nums[h - 1] < h) {
        h--;
    }
    return h;
}

int32_t main() {
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    sort(nums, nums + n);
    reverse(nums, nums + n);
    int h = hIndex(n);
    if (h != n)
        for (int i = h; i >= 0 && i > h - l; i--) {
            nums[i]++;
        }
    sort(nums, nums + n);
    reverse(nums, nums + n);
    cout << hIndex(n) << nl;
}  