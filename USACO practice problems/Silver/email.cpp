using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define YES "YES"
#define NO "NO"

void solve() {
    int n, m, k;
    cin >> m >> n >> k;
    if (n == 1 || m == 1) {
        cout << YES << nl;
        return;
    }
    vector<int> temp;
    vector<int> folderOf(n);
    vector<vector<int>> emailsIn(n, temp);
    vector<vector<int>> inScroll(n, temp);
    vector<bool> filed(n);
    vector<bool> skipped(n);
    vector<bool> inWindow(n);
    int numInWindow = 0;
    int left = 0, right = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> folderOf[i];
        inScroll[max((int)0, (int)--folderOf[i] - k + 1)].push_back(i);
        emailsIn[folderOf[i]].push_back(i);
    }

    auto fileemail = [&](int i) -> void {
        if (inWindow[i]) {
            inWindow[i] = false;
            numInWindow--;
        }
        filed[i] = true;
    };
    
    int currEmail = 0;
    int bottom = 0;

    for (int slvl = 0; slvl < m; slvl++) {
        if (slvl > bottom && slvl + k <= m) bottom++;
    for (int s : inScroll[slvl]) 
        if(inWindow[s]) 
            fileemail(s);
        
    while (emailsIn[slvl].size() && currEmail <= emailsIn[slvl].back()) {
        if (numInWindow == k) {
            while (!inWindow[left]) left++;
            inWindow[left] = false;
            skipped[left] = true;
            numInWindow--;
        }
        if (folderOf[currEmail] >= slvl && folderOf[currEmail] <= slvl + k - 1) {
            filed[currEmail++] = true;
            continue;
        }
        inWindow[currEmail++] = true;
        numInWindow++;
    }

    while (currEmail < n && numInWindow < k) {
        if (folderOf[currEmail] >= slvl && folderOf[currEmail] <= slvl + k - 1) {
            filed[currEmail++] = true;
            continue;
        }

        inWindow[currEmail++] = true;
        numInWindow++;
    }  
        // cout << left << nl;
        // cout << bottom << nl;
        // cout << currEmail << nl;
        // cout << right << nl;
        // cout << "Left off at " << bottom << nl;
        // cout << "inWindow: ";
        // print(inWindow, 0, inWindow.size() - 1);
        // cout << "Skipped:  ";
        // print(skipped, 0, skipped.size() - 1);
        // cout << "filed:    ";
        // print(filed, 0, filed.size() - 1);
        if (currEmail == n) {
            // cout << right << ": " << numInWindow << nl;
            while (numInWindow < k && right >= 0) {
                if (!skipped[right]) {
                    right--;
                    continue;
                }
                if (folderOf[right] < bottom) {
                    cout << NO << nl;
                    return;
                }
                if (folderOf[right] <= bottom + k - 1) {
                    filed[right--] = true;
                    continue;
                } 
                // else cout << right << ": " << folderOf[right] << nl;
                inWindow[right--] = true;
                numInWindow++;
            }
        }
    }

    for (auto ans : filed)  
        if (!ans) {
            cout << NO << nl;
            return;
        }
    
    cout << YES << nl;
    return;

    // cout << "Left off at " << bottom << nl;
    // cout << "inWindow: ";
    // print(inWindow, 0, inWindow.size() - 1);
    // cout << "Skipped: ";
    // print(skipped, 0, skipped.size() - 1);
    // cout << "filed: ";
    // print(filed, 0, filed.size() - 1);

    // for (int slvl = bottom; slvl >= 0; slvl--) {
    //     // if (skipped[currEmail] && folderOf[currEmail])?
    // }
    // cout << "after: " << nl << nl;
    // cout << "Left off at " << bottom << nl;
    // cout << "inWindow: ";
    // print(inWindow, 0, inWindow.size() - 1);
    // cout << "Skipped: ";
    // print(skipped, 0, skipped.size() - 1);
    // cout << "filed: ";
    // print(filed, 0, filed.size() - 1);
    
}


int32_t main() {
    int t;
    cin >> t;
    while (t--)
        solve();
} 
