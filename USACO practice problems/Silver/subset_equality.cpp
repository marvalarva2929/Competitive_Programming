using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = 1e5 + 10;
const int mxletter = 20;

int a[mxn], b[mxn];
vector<int> loc[2][mxletter];
int prefa[mxletter][mxn];
int prefb[mxletter][mxn];
set<int> bl;
set<int> no[mxletter];
int n, q;

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    ifstream cin("test.in");
    ofstream cout("test.out");
    string _a, _b; cin >> _a >> _b >> q;
    n = _a.size();
    for (int i = 0; i < n; i++) {
        a[i] = (_a[i] - 'a'),
        loc[0][a[i]].push_back(i),
        prefa[a[i]][i]++;
    }

    for (int i = 0; i < _b.size(); i++) {
        b[i] = (_b[i] - 'a');
        loc[1][b[i]].push_back(i);
        prefb[b[i]][i]++;
    }

    for (int i = 0; i < mxletter; i++)
        for (int j = 1; j < n; j++)
            prefa[i][j] += prefa[i][j - 1],
            prefb[i][j] += prefb[i][j - 1];

    for (int i = 0; i < mxletter; i++) {
        if (loc[0][i].size() != loc[1][i].size()) {
            bl.insert(i); // this letter can NEVER be used in a query !
            continue;
        }
        for (int j = 0; j < loc[0][i].size(); j++) {
            int ata = loc[0][i][j];
            int atb = loc[1][i][j];
            for (int k = 0; k < mxletter; k++) {
                if (k != i) {

                    int lefta = prefa[k][ata], 
                        righta = prefa[k][n - 1] - prefa[k][ata];

                    int leftb = prefb[k][atb], 
                        rightb = prefb[k][n - 1] - prefb[k][atb];

                    if ((lefta != leftb) || (righta != rightb)) {
                        no[i].insert(k); // letter i can never be with letter k in a query
                    }
                }
            }
        }
    }

    while (q--) {
        string qu; cin >> qu;
        set<int> alls;
        for (char c : qu)
            alls.insert(c - 'a');

        string ss, tt;
        for (int i = 0; i < n; i++)
            if (alls.count(a[i]))
                ss += _a[i];
        
        for (int i = 0; i < n; i++)
            if (alls.count(b[i]))
                tt += _b[i];
        
        cout << (ss == tt ? "Y" : "N");
        continue;
        bool flag = true;
        
        for (int c : alls) {
            if (bl.count(c)) {
                cout << "N";
                flag = false;
                break;
            }
            
            for (int skip : no[c])
                if (alls.count(skip)) {
                    cout << "N";
                    flag = false;
                    break;

                }
        
            if (!flag) {
                break;
            }
        }

        if (flag) cout << "Y";
    }
    cout << nl;
}