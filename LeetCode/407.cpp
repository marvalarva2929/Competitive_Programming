using namespace std;
#include <vector> 
#include <queue>
#include <unordered_set>

class Solution {
public:
    int trapRainWater(vector<vector<int>>& a) {
        int n = a.size();
		int m = a[0].size();
		
		priority_queue<pair<int, pair<int, int>>> boundary = priority_queue<pair<int, pair<int, int>>>();	
		vector<vector<bool>> visited(n, vector<bool>(m, 0));
		int dx[2] = {-1, 1};
		int dy[2] = {-1, 1};

		for (int i = 0; i < n; i++) {
			boundary.push({-a[i][0], {i, 0}});
			boundary.push({-a[i][m-1], {i, m-1}});
			visited[i][0] = visited[i][m-1] = 1;
		}	
		for (int i = 1; i < m - 1; i++) {
			boundary.push({-a[0][i], {0, i}});
			boundary.push({-a[n-1][i], {n-1, i}});
			visited[0][i] = visited[n-1][i] = 1;
		}	
		
		int ans = 0;
		while (boundary.size()) {
			auto next = boundary.top();		
			boundary.pop();
			int x = next.second.first,
				y = next.second.second;

			ans = - a[x][y] - next.first;
				
			for (int i = 0; i < 2; i++) {
				int nx = x + dx[i],
					ny = y + dy[i];

				if (nx >= 0 && nx < n) if (!visited[nx][y]) {
					visited[nx][y] = 1;
					boundary.push({min(-a[nx][y], next.first), {nx, y}});
				}

				if (ny >= 0 && ny < m) if (!visited[x][ny]) {
					visited[x][ny] = 1;
					boundary.push({min(-a[x][ny], next.first), {x, ny}});
				}
			}
		}
		return ans;
    }
};
