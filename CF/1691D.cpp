using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define f first
#define s second
#define inf (int)1e15

const int mxn = 2e5;
int a[mxn];
pi d[mxn];			   // the range in which number i is the maximum value
int n;
int un;

class SegmentTree {

    private:
    int *t;
    vector<int> m;

    void build() {
		for (int i = 0; i < n; i++)
			t[i + un] = m[i];

		for (int i = un - 1; i >= 1; i--)
			t[i] = max(t[i * 2], t[i * 2 + 1]);
		
    }

    int mx(int v, int l, int r, int tl, int tr) {
		if (tl > r || tr < l) return -inf;
		if (tl >= l && tr <= r) return t[v];

		int tm = (tl + tr) >> 1;
		return max(mx(v * 2, l, r, tl, tm), 
					mx(v * 2 + 1, l, r, tm + 1, tr));
    }

    public:

    SegmentTree(vector<int> a) {
        this->m = a;
        this->t = new int[un * 2];
		fill(t, t + (un * 2), LLONG_MIN);
		build();
    }

    int getMaxOf(int i, int j) {
        return mx(1, i, j, 0, un - 1);
    }

};


void solve()
{
	cin >> n;

	un = n;
	while (__builtin_popcount(un) != 1) un++;

	fill(d, d + n, make_pair(-1, n));

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vector<int> b(n), c(n);

	b[0] = a[0];
	c[n - 1] = a[n - 1];

	for (int i = 1; i < n; i++)
		b[i] = b[i - 1] + a[i];

	for (int i = n - 2; i >= 0; i--)
		c[i] = c[i + 1] + a[i];
		
	stack<int> ss;
	for (int i = 0; i < n; i++)
	{
		while (ss.size() && a[ss.top()] < a[i])
		{
			d[ss.top()].s = i;
			ss.pop();
		}
		ss.push(i);
	}

	stack<int> tt;

	for (int i = n - 1; i >= 0; i--)
	{
		while (tt.size() && a[tt.top()] < a[i])
		{
			d[tt.top()].f = i;
			tt.pop();
		}
		tt.push(i);
	}

	SegmentTree p(b);
	SegmentTree sc(c);

	for (int i = 0; i < n; i++)
	{
		int left = sc.getMaxOf(d[i].f + 1, i - 1) - c[i];
		int right = p.getMaxOf(i + 1, d[i].s - 1) - b[i];

		if (max(left, right) > 0)
		{
			cout << "NO" << nl;
			return;
		}
	}
	cout << "YES" << nl;
	return;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
		solve();
}
