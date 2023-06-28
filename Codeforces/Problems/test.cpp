#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
    
vector<int> res(vector<int> a) {
    vector<int> ret(a.size());

    for (int i = 0; i < a.size(); i++) {
        sort(a.begin(), a.begin() + i + 1);
        for (int j = 0; j < a.size(); j++)
            ret[j] += a[j];
    }
    
    return ret;
}

vector<int> tovec(bitset<5> x) {
    vector<int> ret;
    for (int i = 0; i < 5; i++)
        ret.push_back(x[i]);
    return ret;
}

string tobinstring(int x) {
    string ret = ""; 
    for (int i = 0; i < 5; i++) {
        ret += to_string((x >> i) & 1) + ' ';
    }
    return ret;
}

void solve() {
    
    ofstream fout("results.txt");

    bitset<5> cur;
    
    map<int, vector<int>> answer;
    
    fout << (1 << 5) << nl;

    for (int i = 0; i < (1 << 5); i++) {
        cur = i; 
        cout << 5 << nl << tobinstring(i) << nl;
        
        vector<int> x = res(tovec(cur));
        for (int xx : x)
            cout << xx << " ";
        cout << nl;

        }
   }

signed main() {
    int t = 1; 
    while (t--)
        solve();
}

