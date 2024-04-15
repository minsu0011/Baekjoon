#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
queue <pair<int, int>> q;
int N, M;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
const int MAX_N = 1'003;
const int MAX_M = 1'003;
int tomato[MAX_M + 1][MAX_N + 1];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int m = 1; m <= M; m++)
		for (int n = 1; n <= N; n++) {
			cin >> tomato[m][n];
			if (tomato[m][n] == 1)
				q.push(make_pair(m, n));
		}


	int x, y;
	int newx, newy;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			newx = x + dx[i];
			newy = y + dy[i];
			if (newx > 0 && newx <= M && newy > 0 && newy <= N) {
				if (tomato[newx][newy] == 0) {
					tomato[newx][newy] = tomato[x][y] + 1;
					q.push(make_pair(newx, newy));
				}
			}
		}
	}
	int day = 0;
	for (int m = 1; m <= M; m++) {
		for (int n = 1; n <= N; n++) {
			if (tomato[m][n] == 0) {
				printf("-1");
				return 0;
			}
			if (tomato[m][n] > day) {
				day = tomato[m][n];
			}
		}
	}
	cout << day - 1;
	return 0;
}