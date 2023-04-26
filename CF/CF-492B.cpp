#include <iostream>
#include <vector>
#include <algorithm>
#define nl "\n"
typedef long long ll;
typedef long double ld;
using namespace std;


ll l, n;
vector<ll> a;
bool check(ld r) {
    if (a[0] > r ||( l - a[n-1]) > r) {
      return false;
    } else {
        for (int i = 1; i <= n-1; i++) {
            if (a[i] - a[i-1] > 2*r) return false;
        }
        return true;
    }
}

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        ll ai;
        cin >> ai;
        a.push_back(ai);
    }    
    sort(a.begin(), a.end());
    ld high = l;
    ld low = 0;
    ld mid;
    ld esp = 1e-10;
    
    while(high - low >= esp) {
      mid = (high+low)/2;
        if (check(mid)) {
            high = mid;

        } else {
            low = mid;
        }
      // cout << high << nl;
    }
    cout << std::fixed << mid  << nl;
}