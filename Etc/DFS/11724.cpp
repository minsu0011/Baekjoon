#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> vec[1010];
int visit_dfs[1010];
int visit[1010];
queue <int> q;
int n, m;
void dfs(int x) {
	visit_dfs[x] = true;
	for (int i = 0; i < vec[x].size(); i++)
		if (!visit_dfs[vec[x][i]])dfs(vec[x][i]);
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t1, t2;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		vec[t1].push_back(t2);
		vec[t2].push_back(t1);
	}
	for (int i = 1; i <= n; i++) {
		if (!visit_dfs[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}