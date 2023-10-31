#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

int parent[MAXN];
int arr[MAXN];


int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

int main() {

    int tt;
    cin>>tt;

    while(tt--)
    {
        int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        parent[i] = i;
    }

    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int x, y;
            cin >> x >> y;

            for (int j = 1; j <= n; j++) {
                if (arr[j] == x) {
                    arr[j] = y;
                }
            }
            cout<<"Printing the array :\n";
            for (int j = 1; j <= n; j++) {
                cout<<arr[j]<<" ";
            }
            cout<<endl;

        } else if (op == 2) {
            int idx;
            cin >> idx;

            cout << "Output of the 2nd command :"<<arr[find(idx)] << endl;
        }
    }

    }
    return 0;
}
