#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;
///////////////////////////////////////////
int N;
const int MAX_N = 100005;
pair <int, int> Semina[MAX_N];
int Greedy_max(void) {
	int answer = 1;
	int end_former = Semina[1].first;
	int start_now, end_now;
	for (int n = 2; n <= N; n++) {
		start_now = Semina[n].second;
		end_now = Semina[n].first;
		if (start_now >= end_former) {
			end_former = end_now;
			answer++;
		}
	}
	return answer;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	///////////////////////////////////////////
	int a, b;
	int answer;
	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> a >> b;
		Semina[n].first = b;
		Semina[n].second = a;
	}
	sort(Semina + 1, Semina + N + 1);
	cout << Greedy_max();
	return 0;
}

#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int start, end;
	int cnt = 0;
	int tmp = 0;
	pair<int, int> arr[100010];
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &start, &end);
		arr[i] = { end,start };
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (tmp <= arr[i].second) {
			cnt++;
			tmp = arr[i].first;
		}
	}
	cout << cnt;
	return 0;
}