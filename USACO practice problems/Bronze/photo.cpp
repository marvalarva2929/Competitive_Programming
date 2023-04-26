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
#define MAX (int)3e5
int oddAt[MAX];


int32_t main() {
    int n;
    cin >> n;
    vector<char> word(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> word[i];
    int ans = 0;
    char lst = '.';
    for (int i = 1; i <= n; i += 2) {
        if (word[i] != word[i + 1] && word[i] != lst) {
            ans++;
            lst = word[i];
        }
    }
    if (lst == 'H') ans--;
    cout << ans << nl;
}   