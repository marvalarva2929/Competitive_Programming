#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#define nl '\n'
#define MAX (int)1e3
using namespace std;
ifstream fin("vcovt.in");
ofstream fout("vcovt.out");
int dp[MAX][2];
int w[MAX];

struct Node {
    Node* left;
    Node* right;
    int val, n; 
    Node(Node *r, Node *l, int v, int i) {
        this->left = l;
        this->right = r;
        val = v;
        n = i;
    }
};

Node* construct(vector<int>& w, int i) {
    // cout << i << nl;
    if (i * 2 > w.size() - 1) {
        Node* n = new Node(NULL, NULL, w[i], i);
        return n;
    }
    Node* right;
    if (i * 2 + 1 < w.size()) right = construct(w, i * 2 + 1);
    Node* n = new Node(construct(w, i * 2), right, w[i], i);
    return n;
}

void print(Node *start) {
    if (start->left == NULL && start->right == NULL) {
        fout << "Node " << start->n << " is a leaf, with a value of " << start->val << nl;
        return;
    }

    if (start->left == NULL) {
        fout << "Node " << start->n << " has a right child, " << start->right->val << nl;
        print(start->right);
        return;
    }
    if (start->right == NULL) {
        fout << "Node " << start->n << " has a left child, " << start->left->val << nl;
        print(start->left);
        return;
    }
    print(start->left);
    print(start->right);
    fout << "Node " << start->n << " has children with value " << start->left->val << " and " << start->right->val << nl;
    return;
}
void build(set<int> & within, int i, int n, bool include) {
    int l = i * 2;
    int r = l + 1;
    if (l > n && r > n) { // if node i is a leaf node...
        if (include) within.insert(i);
    } else if (l < n && r > n) {
        if (dp[i][1] < dp[i][0]) {
            if (include) within.insert(i);
            if (dp[i][1] == dp[l][0] + w[1]) include = false;
            build(within, l, n, include);
        } else {
            build(within, l, n, true);
        }     
    } else {
        if (include) {
            bool ir = true, il = true;
            within.insert(i);
            if (dp[i][1] == dp[l][0] + dp[r][0] + w[i]) {
                ir = false, il = false;
            } else if (dp[i][1] == dp[l][1] + dp[r][0] + w[i]) {
                ir = false, il = true;
            } else if (dp[i][1] == dp[l][0] + dp[r][1]) {
                il = false, ir = true;
            }
            build(within, l, n, il);
            build(within, r, n, ir);
        } else {
            build(within, l, n, true);
            build(within, r, n, true);
        }   
    }
}

int main() {
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++) 
        fin >> w[i];

    // Node *root = construct(w, 1);

    for (int i = n; i > n/2; i--) { // setting up the leaves of the tree FIRST
        dp[i][0] = 0;
        dp[i][1] = w[i];
    } 

    for (int i = n/2; i >= 1; i--) { // setting up the rest of the tree
        int l = i * 2;
        int r = l + 1;
        if (r > n) {
            dp[i][0] = dp[l][1];
            dp[i][1] = min(dp[l][0], dp[l][1]) + w[i];  
        } else {
            dp[i][0] = dp[l][1] + dp[r][1];
            dp[i][1] = min(dp[l][0] + dp[r][0], min(dp[l][1] + dp[r][0], dp[l][0] + dp[r][1])) + w[i];
        }
        
    } // On to the rest of the tree!
    set<int> incl;
    int ans = min(dp[1][1], dp[1][0]);
    int i = 1;
    bool io = (dp[1][1] > dp[1][0] ? false : true);
    build(incl, 1, n, io);
    for (int i : incl) cout << " Node " << i << " is in the set\n";
    cout << min(dp[1][1], dp[1][0]) << nl;

}