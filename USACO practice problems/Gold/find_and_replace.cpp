#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

const int mxn = 2e5, oo = 1e18;
using namespace std;

struct Node {
    char val;

    int size;

    Node* left;
    Node* right;

    void print(int l, int r) { 

        l = max(l, (int)1); 
        r = min(r, size);

        if (r < l) return;

        if (val != '-') cout << val;
        else {
            left->print(l, r);
            right-> print(l - left->size, r - left->size);
        }
    }
};

pair<char, string> ops[mxn];
Node* tree[26];

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    for (int i = 0; i < 26; i++)
        tree[i] = new Node{(char)(i + 'a'), 1}; 

    int l, r, n; cin >> l >> r >> n;
        
    for (int i = n - 1; i >= 0; i--)
        cin >> ops[i].ff >> ops[i].ss;

    for (int i = 0; i < n; i++) {
        Node* res = nullptr; 
        
        for (char& c : ops[i].ss) {
            Node* to_merge = tree[c - 'a'];
            if (res == nullptr) res = to_merge;
            else {
                res = new Node{'-', min(oo, to_merge->size + res->size), res, to_merge};
            } 
        }
        
        tree[ops[i].ff - 'a'] = res;
    }
    
    tree[0]->print(l, r);
    cout << endl;
}
