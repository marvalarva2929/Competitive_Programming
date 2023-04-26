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
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define MAX (int)5e6 + 10
bool isPrime[MAX];
int numOfFactors[MAX];
int primeDiv[MAX];
int pref[MAX];

vector<int> primes;


void solve() {
    int a, b; cin >> a >> b;
    int ans = 0;
    cout << (pref[a] - pref[b]) << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i <= MAX; i++) 
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i; j <= MAX; j += i) { 
                isPrime[j] = false;
                if(!primeDiv[j])
                    primeDiv[j] = i;
            }
        }

    for (int i = 2; i <= MAX; i++)
        numOfFactors[i] = numOfFactors[i / primeDiv[i]] + 1;

    for (int i = 1; i <= MAX; i++)
        pref[i] = pref[i - 1] + numOfFactors[i];
    int t; cin >> t;
    while (t--)
        solve();
} 