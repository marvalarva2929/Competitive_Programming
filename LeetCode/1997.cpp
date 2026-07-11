#include <vector>
using namespace std;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
		int MOD = (1e9)+7;
		int n = nextVisit.size();
 		vector<int> a(n, 0);       
		vector<int> pa(n, 0);
		a[0] = 2;
		pa[0] = 2;

		for (int i = 1; i < n; i++) {
			// compute a[i] given a[i - 1];		
			if (nextVisit[i] == i) {
				a[i] = (a[i - 1] + 2) % MOD;
			} else {
				int af = pa[i -1] % MOD;
				int bf = (nextVisit[i] > 0 ? pa[nextVisit[i] - 1] : 0);
				a[i] = (af - bf) % MOD;	
			}

			pa[i] = (pa[i - 1] + a[i]) % MOD;
		}

		return pa[n-1] % MOD;
    }
};
