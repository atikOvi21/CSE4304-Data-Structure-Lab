#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int> cookies; // min heap

    for (int i = 0; i < n; ++i) {
        int sweetness;
        cin >> sweetness;
        cookies.push((-1*sweetness));
    }

    int operations = 0;

    while (cookies.size() >= 2 && cookies.top() < k) {
        int least_sweet_1 = -1*cookies.top();
        cookies.pop();
        int least_sweet_2 = -1*cookies.top();
        cookies.pop();

        int combined_sweetness = least_sweet_1 + 2 * least_sweet_2;
        cookies.push(-1*combined_sweetness);

        operations++;
    }

    if (cookies.top() < k) {
        cout << -1 << endl;
    } else {
        cout << operations << endl;
    }

    return 0;
}
