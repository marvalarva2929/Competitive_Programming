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
int cows[21];
int stalls[21];
int cowsIn[21];
//step one: determine how many cows can go in each stall
//step two: sort the stalls in ascending order of height
//step three: multiply the number of cows that can fit in each stall minus the rank of the stall

int32_t main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cows[i];
    for (int i = 0; i < n; i++)
        cin >> stalls[i];

    sort(stalls, stalls + n);
    sort(cows, cows + n);

    for (int i = 0; i < n; i++) {
        int height = cows[i];
        for (int j = 0; j < n; j++) {
            if (height <= stalls[j]) {
                cowsIn[j]++;
            } 
        }        
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= (cowsIn[i] - i); 
    }
    
    cout << ans << nl;
} 