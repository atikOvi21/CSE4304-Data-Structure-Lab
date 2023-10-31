#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find_Set(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = find_Set(parent[u]);
    }

    void Union_Set(int u, int v) {
        u = find_Set(u);
        v = find_Set(v);
        if (u != v) {
            parent[u] = v;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.Union_Set(u - 1, v - 1);
    }

    unordered_map<int, vector<int>> connectedComponents;

    for (int i = 0; i < n; i++) {
        connectedComponents[dsu.find_Set(i)].push_back(i + 1);
    }

    int numComponents = connectedComponents.size();
    cout << "no of connected components: " << numComponents << endl;

    cout << "Connected node sets:" << endl;
    for (auto component : connectedComponents)
    {

        vector<int>& nodes = component.second;
        for (int node : nodes) {
            cout << node << " ";
        }

        cout << endl;
    }

    return 0;
}
