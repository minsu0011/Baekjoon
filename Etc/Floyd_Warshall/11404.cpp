#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int N, M;
int a, b, c;
const int MAX_N = 102;
const int MAX_M = 100002;
const int INF = MAX_N * 100'000;
int DP[MAX_N][MAX_M];

void Floyd_Warshall() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
	}
}
int main() {
	//파일입출력
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//입출력가속
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++) {
			if (i == j) DP[i][j] = 0;
			else DP[i][j] = INF;
		}

	cin >> N >> M;
	for (int m = 1; m <= M; m++) {
		cin >> a >> b >> c;
		DP[a][b] = min(DP[a][b], c);
	}

	Floyd_Warshall();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (DP[i][j] == INF) DP[i][j] = 0;
			cout << DP[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}