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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> v( n+1 , vector<int> (n,0));
    vector<vector<int>> vec( n+1);
    set<int>s;

    for (int i = 0; i < k; ++i)
    {
        int x,y;
        cin>>x>>y;
        s.insert(x);
        s.insert(y);
        v[x][y] = 1;
        v[y][x] = 1;


        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    cout<<"Adjacency matrix:\n";

    for (auto x : s )
    {
        cout<<x;
        for (int i = 1; i <= n; ++i)
        {
            cout<<" "<<v[x][i]<<" ";
        }
        cout<<endl;
    }
    cout<<"Adjacency list:\n";
    for (auto x : s )
    {

    cout<<x;
        for (int i = 0; i < vec[x].size(); ++i)
        {
            cout<<" "<<vec[x][i]<<" ";
        }
        cout<<" "<<endl;
    }







}

int main() {
    //init_code();
    solve();
}
