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
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");
    int n;
    string a, b;
    fin >> n >> a >> b;
    char lsta = '.';
    char lstb = '.';
    string na, nb;
    int lst = 0;
    int ans = 0;
    vector<pair<int, int>> fix;
    bool prev = false;
    for (int i = 0; i <= n; i++) { 
        if (a[i] != b[i] && !prev) {
            ans++;
            prev = true;
        } else if (a[i] == b[i]) prev = false;
    }

    fout << ans << nl;
} 