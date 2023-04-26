#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)1e5 + 10
using namespace std;
vector<int> w, x, v;

int32_t main() {
    ifstream fin("meetings.in");
    ofstream fout("meetings.out");
    int n, l;
    fin >> n >> l;
    w.resize(n);
    x.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++) {fin >> w[i] >> x[i] >> v[i]; cout << i << ": " << x[i] << nl;}
    vector<int> indc(n);
    iota(indc.begin(), indc.end(), 0);
	sort(indc.begin(), indc.end(), [](int a, int b) { return x[a] < x[b]; });
    vector<int> W, X, V;
    for (int i : indc) {
        W.push_back(w[i]);
        X.push_back(x[i]);
        V.push_back(v[i]);
    }
    swap(W, w); swap(V, v); swap(X, x);

    vector<pair<int, pair<int, int>>> cows; 
    vector<pair<int, int>> ncow;
    vector<int> lx;
    int stop = 0;
    vector<int> left;
    vector<int> right;
    for (int i = 0; i < v.size(); i++) 
        if (v[i] == -1) left.push_back(x[i]);
        else right.push_back(x[i]);
    for (int i = 0; i < left.size(); i++) {
        ncow.push_back({left[i], w[i]});     
    }
    for (int i = 0; i < right.size(); i++) {
        ncow.push_back({l - right[i], w[i + left.size()]});
    }
    sort(ncow.begin(), ncow.end());
    for (auto p : ncow) stop += p.second;
    int T = 0;
    for (pair<int, int> a : ncow) {
        stop -= a.second * 2;
        if (stop <= 0) { 
            T = a.first;
            break;
        } 
    }
    cout << T << nl;
    int ans = 0;
    // for (int le : lx) cout << le << nl;
    sort(left.begin(), left.end());
    for (int r : right) {
            ans += upper_bound(left.begin(), left.end(), r + T*2) - lower_bound(left.begin(), left.end(), r);
            // cout << upper_bound(left.begin(), left.end(), r + T*2) - left.begin() << ": " << lower_bound(left.begin(), left.end(), r) - left.begin() << nl;
            // cout << i << ": " << cows[i].first << nl;
    }
    fout << ans << nl;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	freopen("meetings.in", "r", stdin);
// 	freopen("meetings.out", "w", stdout);
// 	int n, l; cin >> n >> l;
// 	//{weight, pos}, stop_time
// 	vector<pair<pair<int, int>, int>> cows(n);
// 	vector<int> left, right;
// 	//stop_time, direction(1 for right, 0 for left)
// 	vector<pair<int, bool>> distances(n);
// 	int sumweights = 0;
// 	for(int i = 0; i < n; i++) {
// 		int w, x, d; cin >> w >> x >> d;
// 		cows[i].first = {w, x};
// 		sumweights += w;
// 		if(d == 1) {
// 			right.push_back(x);
// 			distances[i] = {l-x, 1};
// 		} else {
// 			left.push_back(x);
// 			distances[i] = {x, 0};
// 		}
// 	}
// 	//sort by position
// 	sort(cows.begin(), cows.end(), 
// 	[](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
// 		return a.first.second < b.first.second;
// 	});
// 	sort(distances.begin(), distances.end(),
// 	[](pair<int, bool> a, pair<int, bool> b) {
// 		return a.first < b.first;
// 	});
// 	//find the time cow reaches barn
// 	int leftp = 0, rightp = n-1;
// 	for(int i = 0; i < n; i++) {
// 		if(distances[i].second) {
// 			cows[rightp].second = distances[i].first;
// 			rightp--;
// 		} else {
// 			cows[leftp].second = distances[i].first;
// 			leftp++;
// 		}
// 	}
    
// 	//sort by time cow reaches barn
// 	sort(cows.begin(), cows.end(), 
// 	[](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
// 		if(a.second == b.second)
// 			return a.first.first > b.first.first;
// 		return a.second < b.second;
// 	});
// 	//find stopping time
// 	int sum = 0, etime = -1;
// 	while((sum << 1) < sumweights) { //bit shifting to save time because its multiplying by 2
// 		sum += cows[etime + 1].first.first;
// 		etime++;
// 	}
// 	etime = cows[etime].second;
// 	int ans = 0;
//     cout << etime << '\n';
// 	//cows only collide at opposite directions
// 	sort(right.begin(), right.end());
// 	for(int i = 0; i < left.size(); i++) {
// 		ans += lower_bound(right.begin(), right.end(), left[i]) - lower_bound(right.begin(), right.end(), max(left[i] - (2*etime), 0));
// 	}
// 	cout << ans << '\n';
// }