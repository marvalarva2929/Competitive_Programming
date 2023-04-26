#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#define nl "\n"
#define adjacency_list vector<vector<int>>
#define vector2d vector<vector<int>>
#define set2d set<set<int>>
using namespace std;

class Strong_connected_components {
    private:
    set2d components;
    adjacency_list main_adjList;
    adjacency_list rev_adjList;
    priority_queue<int> maxSizes;
    vector<bool> visited;
    vector<int> node_from_finish;        
    int numOfComponents = 0;
    
    set<int> dfs(int n, int t, bool reversed) { // returns the  nodes in the component
        set<int> count = {n};
        if (!visited[n]) {
            visited[n] = true;
            // cout << n << nl;
            if (!reversed) {
                for (int i : main_adjList[n]) {
                    if (i != 0 && !visited[i]) {
                        set<int> pot = dfs(i, t + 1, false);
                        count.insert(pot.begin(), pot.end());
                    }
                }
                // cout << n << ": " << t << nl;
            } else {
                for (int i : rev_adjList[n]) {
                    if (i != 0 && !visited[i]) {
                        dfs(i, t + 1, true);
                        // count.insert(pot.begin(), pot.end());
                    }
                }
                cout << n << ": " << t << nl;
                node_from_finish.push_back(n);
            }
        }
        return count;
    }

    public:
    
    Strong_connected_components(adjacency_list adjList, adjacency_list rev) {
        // cout << adjList.size() << nl;
        main_adjList = adjList;
        rev_adjList = rev;
        visited.resize(max(adjList.size(),  rev.size()) + 1);
        for (int i = 1; i <= (int) main_adjList.size(); i++) visited[i] = false;
        find();
    }

    int numberOf() {
        return numOfComponents;
    }

    string count_to_string() {
        stringstream ss;
        ss << "[ ";
        for (int i : node_from_finish) {
            if (i != 0) ss << i << ", ";
        }
        ss << "]";
        return ss.str();
    }

    string toString() {
        stringstream ss;
        ss << "The Strong Components are: " << nl;
        for (set<int> component : components) {
            if (component.size() > 2) {
                ss << "{ ";
                for (int node : component) {
                    ss << node << ", ";
                }
                ss << "} " << "with a size of " << component.size() << nl;
            }
        }
        return ss.str();
    }

    string maxToString(int n) {
        stringstream ss;
        priority_queue<int> copy = maxSizes;
        ss << "The max sizes are: " << nl << "{ ";
        for (int i = 0; i < n; i++) {
            ss << copy.top() << " ";
            copy.pop();
        }
        ss << " }";
        return ss.str();
    }

    set2d find() {
        //STEP 1: Topologically sort the reversed graph
        for (int i = main_adjList.size() - 1; i > 0; i--) {
            if (!visited[i]) {
                cout << i << " --" << nl;
                dfs(i, 0, true);
            }
        }
        cout << "e" << nl;
        // STEP 2: DFS through the finished components list in decreasing order so that sink nodes/components are discovered before 
        for (int i = 1; i < (int) visited.size(); i++) visited[i] = false;
        int count = 0;
        reverse(node_from_finish.begin(), node_from_finish.end());
        for (int i : node_from_finish) {
            if (!visited[i]) {
                set<int> comp = dfs(i, 0, false);
                if (comp.size() > 2) count++;
                components.insert(comp);
                maxSizes.push(comp.size());
                // cout << next << ": " << comp.size() << nl;
            }
            // cout << nl;
        }
        numOfComponents += count;
        return components;
    // }
    }
};

int main() {
    ifstream fin("SCC.txt");
    ofstream fout("strong.out");
    // fstream fin;
    // fin.open("SCC.txt");
    vector<int> temp;
    vector<vector<int>> adj(875715, temp);
    vector<vector<int>> rev(875715, temp);
    int p;
    int q;
    
    while (fin >> p >> q) {
        // cout << p << " " << q << nl;
        adj[p].push_back(q);
        rev[q].push_back(p);
    }
    cout << 'a' << nl;
    // cout << adj[875714][0] << nl;

    Strong_connected_components comp(adj, rev);
    cout << 'e' << nl;
    fout << comp.maxToString(5) << nl << nl << comp.toString() << nl;
}
