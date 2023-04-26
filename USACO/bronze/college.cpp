using namespace std;
#include <bits/stdc++.h>
#define nl '\n'
#define int long long
#define MAX (int)1e5 + 50
unordered_map<int, bool> used;

int32_t main() {
    int n; cin >> n;
    vector<int> cowsPlaying;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        int cost; cin >> cost;
        cowsPlaying.push_back(cost);
    }


    sort(cowsPlaying.begin(), cowsPlaying.end());


    int prof = INT_MIN;
    int cha = 0;
    int i = 0;

    for (int i = 0; i < n; i++) {
        int attend = n - i;
        int charge = cowsPlaying[i];    
        // cout << i << ": " << attend << ": " << charge  << nl;
        if ((attend * charge) > prof) {
            prof = (attend * charge);
            cha = charge;
        } 
    }


    // for (int i = 0; i < cost; i++)

    cout << prof << ' ' << cha << nl;


    
}