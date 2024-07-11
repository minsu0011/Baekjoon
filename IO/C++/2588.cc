/* https://www.acmicpc.net/problem/2588 */
#include<iostream>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a,b;
    int t;
    cin >> a >> b;
    t = b % 10;
    cout << a*t << '\n';
    t = (b % 100 - b % 10)/10;
    cout << a*t << '\n';
    t = (b % 1000 - b % 100)/100;
    cout << a*t << '\n';
    cout << a*b;
	return 0;
}