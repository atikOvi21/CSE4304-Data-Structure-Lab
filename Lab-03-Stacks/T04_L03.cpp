#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
#define fr first
#define sc second

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	vector<int> v;
	stack<pair<int, int> > stk;
	int x, lg = 0, i, j;
	
	while(1){
		cin >> x;
		if(x == -1) break;
		v.push_back(x);
		lg = max(lg, x);
	}
	vector<int>ans(v.size());
	stk.push({v[0], 0});
	
	for(i = 0; i < v.size(); i++){
		while(!stk.empty() && stk.top().fr < v[i]){
			ans[stk.top().sc] = v[i];
			stk.pop();
		}
		if(v[i] == lg) ans[i] = -1;
		else stk.push({v[i], i});
	}
	for(i = 0; i < v.size(); i++){
		while(!stk.empty() && stk.top().fr < v[i]){
			ans[stk.top().sc] = v[i];
			stk.pop();
		}
	}
	
	for(auto e : ans) cout << e << " ";
	cout << "\n";
	
	return 0;
}