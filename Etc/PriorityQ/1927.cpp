#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> pq;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, x;
	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << -pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(-x);
	}
	return 0;
}