#include <iostream>
#define nl '\n'
using namespace std;

int32_t main() {
    int t;
    cin >> t;
    long long n, a, b, x;    
    for (int p = 0; p < t; p++) {
        cin >> n >> a >> b;
        if (a == 1 && (n - 1) % b < 1) {
            cout << "Yes" << nl;
        } else {
            bool yes = false;
            for (x = 1; x <= n; x = (x * a)) {
                if ((n - x) % b < 1) {
                    yes = true;
                    cout << "Yes" << nl;
                    break;
                }
            }
            if (!yes) cout << "No" << nl;
        }
    }
}

// #include<iostream>
// long long n,a,b,m;
// main(){
//  for(scanf("%*d"); std::cin>>n>>a>>b; puts(n?"No":"Yes"))
//     if(a < 2 ) n = (n - 1) % b;
//     else 
//         for( m = 1; m <= n; m*=a)
//             if((n - m) % b < 1) n=0;
// }
