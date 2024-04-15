#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;
///////////////////////////////////////////
const int MAX_N = 505;
const int MAX_M = 505;
int map[MAX_N][MAX_M];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	///////////////////////////////////////////
	int N, M, B;
	int height_now;
	int height_ans = -1;
	int time_now = 0;
	int time_min = INT_MAX;
	int x = 0;
	int o = 0;
	int t = 0;
	cin >> N >> M >> B;
	for (int n = 0; n < N; n++)
		for (int m = 0; m < M; m++)
			cin >> map[n][m];
	for (int i = 256; i >= 0; i--) {
		x = 0;
		o = 0;
		height_now = i;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (map[n][m] > height_now) x += map[n][m] - height_now;
				else if (map[n][m] < height_now || map[n][m] == height_now) o += height_now - map[n][m];
			}
		}
		if (B < o - x)continue;
		time_now = x * 2 + o;
		if (time_now < time_min) {
			time_min = time_now;
			height_ans = height_now;
		}
	}
	cout << time_min << " " << height_ans;
	return 0;
}