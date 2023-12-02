#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 25;
pi a[mxn][mxn];
int is[mxn][mxn];
int dx[2] = {-1, 1};
int pw[10];
bool vis[mxn][mxn][19684];
int n;
set<int> ans;

int types[16][3][3] = {
    {
        { 1,  0,  0},
        {-1, -1, -1},
        {-1, -1, -1}
    },
    {
        { 0,  0,  1},
        {-1, -1, -1},
        {-1, -1, -1}
    },
    {
        { 1, -1, -1},
        {-1,  0, -1},
        {-1, -1,  0}
    },
    {
        { 0, -1, -1},
        {-1,  0, -1},
        {-1, -1,  1}
    },
    {
        { 1, -1, -1},
        { 0, -1, -1},
        { 0, -1, -1}
    },
    {
        { 0, -1, -1},
        { 0, -1, -1},
        { 1, -1, -1}
    },
    {
        {-1, -1,  1},
        {-1, -1,  0},
        {-1, -1,  0}
    },
    {
        {-1,  0, -1},
        {-1,  0, -1},
        {-1,  1, -1}
    },
    {
        {-1,  1, -1},
        {-1,  0, -1},
        {-1,  0, -1}
    },
    {
        {-1, -1,  0},
        {-1, -1,  0},
        {-1, -1,  1}
    },
    {
        {-1, -1, -1},
        {-1, -1, -1},
        { 0,  0,  1}
    },
    {
        {-1, -1, -1},
        {-1, -1, -1},
        { 1,  0,  0}
    },
    {
        {-1, -1, -1},
        { 0,  0,  1},
        {-1, -1, -1},
    },
    {
        {-1, -1, -1},
        { 1,  0,  0},
        {-1, -1, -1},
    },
    {
        {-1, -1,  0},
        {-1,  0, -1},
        { 1, -1, -1}
    },
    {
        {-1, -1,  1},
        {-1,  0, -1},
        { 0, -1, -1}
    },
};

bool win(int b) {
    int cel[3][3];

    //cout << b << nl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cel[i][j] = b % 3, b /= 3;
    
    //for (int i = 0; i < 3; i++)
    //    for (int j = 0; j < 3; j++)
    //        cout << cel[i][j] << nl[j == 2];

    for (int i = 0; i < 16; i++) {
        bool ret = 1;
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                if (types[i][j][k] != -1 && types[i][j][k] != cel[j][k] - 1)
                    ret = 0;
        if (ret) return true;
    }

    return false;
}

void dfs(int x, int y, int b) {
    if (vis[x][y][b]) return;
    vis[x][y][b] = 1;
    int nb = b;
   
    //cout << x << " " << y << nl;

    if (is[x][y] != -1) {
        //cout << 'e' << nl;
        int id = (3 * a[x][y].ff) + a[x][y].ss;
        if ((b / pw[id]) % 3) goto skip;
        
        //cout << 'f' << nl;

        nb += (is[x][y]+1) * pw[id]; 
        if (win(nb)) {
            ans.insert(nb);
            return;
        }
    }
    
    skip:

    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dx[i];
         
        if (nx >= 0 && nx < n && is[nx][y] != -2) dfs(nx, y, nb);
        if (ny >= 0 && ny < n && is[x][ny] != -2) dfs(x, ny, nb);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    pi st;
    pw[0] = 1;
    for (int i = 1; i < 10; i++)
        pw[i] = pw[i - 1] * 3;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j * 3 < s.size(); j++) {
            if (s[j*3] == '#') is[i][j] = -2;
            else if (s[j*3] == '.') is[i][j] = -1;
            else if (s[j*3] == 'O') a[i][j] = {s[j*3 + 1] - '0' - 1, s[j*3 + 2] - '0' - 1}, is[i][j] = 0; 
            else if (s[j*3] == 'M') a[i][j] = {s[j*3 + 1] - '0' - 1, s[j*3 + 2] - '0' - 1}, is[i][j] = 1; 
            else st.ff = i, st.ss = j, is[i][j] = -1;
        }
    }
    
    dfs(st.ff, st.ss, 0);
    cout << ans.size() << endl;
}
