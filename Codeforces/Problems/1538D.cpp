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
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define no "NO"
#define yes "YES"
#define MAX (int)1e5 + 1

std::vector<int> primes;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    if (k == 1) {
        if ((a % b == 0 || b % a == 0) && a != b) {
            cout << yes << nl;
            return;
        } else {
            cout << no << nl;
            return;
        }
    }
    int maxK = 0;

    for (int t : primes) {
        while (a % t == 0) {
            maxK++;
            a /= t;
        }

        while (b % t == 0) {
            maxK++;
            b /= t;
        }
        if (a == 1 && b == 1) break;
    }
    if (a != 1) maxK++;
    if (b != 1) maxK++;

    if (k <= maxK) {
        cout << yes << nl;
        return;
    } else {
        cout << no << nl;
        return;
    }
}

int32_t main() {
    vector<bool> isPrime(MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < MAX; i++) 
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < MAX; j += i)
                isPrime[j] = false;
    }
    int t; cin >> t;
    while (t--)
        solve();


} 