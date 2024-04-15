#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
///////////////////////////////////////////
const int MAX_LENGTH = 105;
string sik;
int i = 0;
///////////////////////////////////////////
int solve() {
	int cnt = 0;
	while (true) {
		if (sik[i] == 0) break;

		if (sik[i] == '(') {
			i++;
			cnt += solve();
		}

		if (sik[i] == ')') {
			i++;
			if ('0' < sik[i] && sik[i] <= '9') {
				cnt *= (sik[i] - '0');
				i++;
			}
			return cnt;
		}

		if (sik[i] == 'C') {
			i++;
			if ('0' < sik[i] && sik[i] <= '9') {
				cnt += 12 * (sik[i] - '0');
				i++;
			}
			else cnt += 12;
		}
		else if (sik[i] == 'H') {
			i++;
			if ('0' < sik[i] && sik[i] <= '9') {
				cnt += 1 * (sik[i] - '0');
				i++;
			}
			else cnt += 1;
		}
		else if (sik[i] == 'O') {
			i++;
			if ('0' < sik[i] && sik[i] <= '9') {
				cnt += 16 * (sik[i] - '0');
				i++;
			}
			else cnt += 16;
		}
	}
	return cnt;
}
////////////////////////////////////////////
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	///////////////////////////////////////////
	cin >> sik;
	cout << solve();
	return 0;
}