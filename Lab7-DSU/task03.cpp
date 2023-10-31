#include <bits/stdc++.h>
using ll = long long;
#define endl '\n'

using namespace std;

void init_code() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class DSU
{
public:
    vector<int> parent;

    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findSet(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = findSet(parent[u]);
    }

    void SetUnion(int u, int v)
    {
        u = findSet(u);
        v = findSet(v);
        if (u != v) {
            parent[u] = v;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu.SetUnion(u - 1, v - 1);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (  dsu.findSet(x - 1) == dsu.findSet(y - 1) )
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
