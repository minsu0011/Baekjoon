#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
///////////////////////////////////////////
int N, M;
const int MAX_N = 1000010;
const int MAX_M = 5010;
vector <int> parent(MAX_N, 0);
vector <int> robot(MAX_N, 1);
//////////////////////////////////////////
int FIND(int node) {
	if (node == parent[node]) return node;
	return parent[node] = FIND(parent[node]);
}
///////////////////////////////////////////
void UNION(int node_a, int node_b) {
	int root_a = FIND(node_a);
	int root_b = FIND(node_b);

	if (root_a != root_b) {
		parent[root_b] = root_a;
		robot[root_a] += robot[root_b];
	}
}
////////////////////////////////////////////
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char a;
	int b, c;
	///////////////////////////////////////////
	cin >> N;
	for (int n = 1; n <= MAX_N - 1; n++)
		parent[n] = n;
	for (int n = 1; n <= N; n++) {
		cin >> a;
		if (a == 'I') {
			cin >> b >> c;
			UNION(b, c);
		}
		else if (a == 'Q') {
			cin >> b;
			cout << robot[FIND(b)] << '\n';
		}
	}
	return 0;
}