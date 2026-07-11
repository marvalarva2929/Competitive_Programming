#include <vector>;
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> root;        
	vector<int> size;
	unordered_map<int, int> loc;

	int getroot(int i) {
		while (root[i] != i) {
			root[i] = root[root[i]];
			i = root[i];
		}
	}

	void join(int i, int j) {
		int p = getroot(i), q = getroot(j);
		if (size[p] < size[q]) swap(p, q);

		root[q] = p;
		size[p] += size[q];
	}

    int longestConsecutive(vector<int>& nums) {
		int n = nums.size();
		root = vector<int>(n);
		size = vector<int>(n, 1);

		for (int i = 0; i < n; i++)
			root[i] = i,
			size[i] = 1;

		for (int i = 0; i < n; i++)
			loc[nums[i]]= i+1;

		int ans = 0;

		for (int i = 0; i < n; i++) {
			int idx = nums[i];
			if (loc[idx-1] != 0) {
				join(i, loc[idx-1] - 1);	
			}
			if (loc[idx+1] != 0) {
				join(i, loc[idx+1] - 1);
			}

			ans = max(ans, size[getroot(i)]);
		}	
		return ans;
	}
};
