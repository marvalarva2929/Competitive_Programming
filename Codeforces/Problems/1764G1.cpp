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
#define fl flush

int request(int x, int y, int k) {
    int n;
    cout << "? " << x << " " << y << " " << k << nl << fl;
    cin >> n;
    return n;
}

int solve(int lo, int hi) {
    if (lo >= hi) return lo;
    int mid = (lo + hi)/2;
    int left = request(lo, mid, 2);
    int right = request(mid, hi, 2);
    if (left < right) return solve(mid, hi);
    else return solve(lo, mid);
}

int32_t main() {
    int n;
    cin >> n;
    cout << "! " << solve(1, n) << nl;

} 