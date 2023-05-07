#include <iostream>
#include <map>
#define nl '\n'
#define ll long long
using namespace std;

void tt() {
    ll n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        int freq[10]{}, distinct = 0, maxFreq = 0;
        for (int j = i; j < s.size() && ++freq[s[j] -'0'] <= 10; j++) {
            // cout << s[j] - '0' << " with a freq of " << freq[s[j] - '0'] << nl;
             maxFreq = max(maxFreq, freq[s[j] - '0']);
             distinct += freq[s[j] - '0'] == 1 ? 1 : 0;
             ans += distinct >= maxFreq ? 1 : 0;
        }
    }
    cout << ans << nl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t ;i++) {
        tt();     
    }
}