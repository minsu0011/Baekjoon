#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;
///////////////////////////////////////////
int N;
const int MAX_N = 55;
vector <int> A(MAX_N, 0);
vector <int> B(MAX_N, 0);
bool compare(int a, int b) {
	return a > b;
}
///////////////////////////////////////////
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	///////////////////////////////////////////
	int answer = 0;
	cin >> N;
	A.resize(N, 0);
	B.resize(N, 0);
	for (int n = 0; n < N; n++) cin >> A[n];
	for (int n = 0; n < N; n++) cin >> B[n];

	sort(A.begin(), A.end(), compare);
	sort(B.begin(), B.end());

	for (int n = 0; n < N; n++)
		answer += (A[n] * B[n]);
	cout << answer;

	return 0;
}
