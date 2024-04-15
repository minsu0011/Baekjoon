#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int N, M;
const int INF = INT_MAX;
const int MAX_N = 102;
int DP[MAX_N][MAX_N];

void Floyd_Warshall() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
	}
}

int main() {
	//파일입출력
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//입출력가속
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t1, t2;

	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++) {
			if (i == j) DP[i][j] = 0;
			else DP[i][j] = INF;
		}

	cin >> N >> M;
	for (int m = 1; m <= M; m++) {
		cin >> t1 >> t2;
		DP[t1][t2] = min(DP[t1][t2], 1);
		DP[t2][t1] = min(DP[t2][t1], 1);

	}
	Floyd_Warshall();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			DP[i][j]
		}
	}
	return 0;
}