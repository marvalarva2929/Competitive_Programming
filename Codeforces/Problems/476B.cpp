#include <iostream>
#include <iomanip>
#include <cmath>
#define nl "\n"
using namespace std;

int choose(int n, int k) {
	if (k == 0 || k == n) {
		return 1;
	}
	return (choose(n - 1, k - 1) + choose(n - 1, k));
}
int main() {

  int loc1 = 0, loc2 = 0;
  int unk = 0;
  double ans = 0;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  for (char s : s1) s == '+' ? loc1++ : loc1--;
  for (char s : s2) ((s == '+') ? loc2++ : (( s == '?') ? unk++ : loc2--));

  int diff = abs(loc1-loc2);
  diff > unk ? ans = 0 : ans = choose(unk, (unk - diff)/2) / pow(2, unk);


  cout << fixed << setprecision(10) << ans << nl;
}