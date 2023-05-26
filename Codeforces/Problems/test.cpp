#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define ll long long

using namespace std;

ll expo(ll a , ll b , ll m){//(a^b)%m
    ll ans = 1 , curr = a%m;    
    while(b){
        if(b&1){
            ans*=curr;
            ans%=m;
        }
        curr = (curr%m) * (curr%m)%m;
        b>>=1;
    }
    return ans%m;
}


signed main() {
    cout << (2 * expo(2, ((int)1e9 + 5), (int)1e9 + 7)) % ((int)1e9 + 7) << nl;
}
