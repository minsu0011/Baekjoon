#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> vec[1010];
int visit_dfs[1010] = { 0, };
int visit_bfs[1010] = { 0, };
int tmp[10010] = { 0, };
queue <int> q;
int n, m, v;
void dfs(int x) {
	visit_dfs[x] = true;
	cout << x << " ";
	for (int i = 0; i < vec[x].size(); i++) {
		if (!visit_dfs[vec[x][i]])
			dfs(vec[x][i]);
	}
}
void bfs() {
	q.push(v);
	visit_bfs[v] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i = 0; i < vec[now].size(); i++) {
			if (!visit_bfs[vec[now][i]]) {
				q.push(vec[now][i]);
				visit_bfs[vec[now][i]] = true;
			}
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t1, t2, t;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		vec[t1].push_back(t2);
		vec[t2].push_back(t1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < vec[i].size(); j++)
			tmp[j] = vec[i][j];
		sort(tmp, tmp + vec[i].size());
		t = vec[i].size();
		vec[i].clear();
		for (int j = 0; j < t; j++) {
			vec[i].push_back(tmp[j]);
			tmp[j] = 0;
		}
	}

	dfs(v);
	cout << "\n";
	bfs();
	return 0;
}