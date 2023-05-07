#include <iostream>
#include <map>
#include <climits>
#include <cmath>
#define nl "\n"
#define ll long long
using namespace std;


int main() {
  ll n;
  int maxx = 0, minn = INT_MAX;
  ll ans = 0;
  ll range = 0;
  cin >> n;
  map<int,ll> nums;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums[num]++;
    minn = min(minn, num);
    maxx = max(maxx, num);
  }
  ans = maxx - minn;
  (minn == maxx) ? range = n*(n-1)/2 : range = nums[minn] * nums[maxx];
  cout << ans << " " << range << nl;
}