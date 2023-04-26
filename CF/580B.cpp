#include <iostream>
#include <vector>
#include <algorithm>
#define nl '\n'
#define MAX (int)1e6
#define int long long
#define ll long long
using namespace std;

struct f {
    int v, w;
    f(int value, int weight) {
        v = value;
        w = weight;
    }
    friend bool operator<(const f &that, const f &them) {
        return that.w < them.w;
    }   
};

int32_t main() {
    int n, d;
    cin >> n >> d;
    vector<f> friends;
    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> w >> v;
        f fre(v, w);
        friends.push_back(fre);
    }
    sort(friends.begin(), friends.end());
    int i = 0, ans = 0;
    int j = 0;
    int total = 0;
    for (int i = 0; i < n; total -= friends[i].v, i++) {
        while(abs(friends[j].w - friends[i].w) < d && j < n) {
            total += friends[j++].v;
            ans = max(ans, total);
        }
    
    }
    cout << ans << nl;
}