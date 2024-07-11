/* https://www.acmicpc.net/problem/11382 */
#include<iostream>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int a,b,c;
    //long long int : 8byte Data Type
    //10의12승 범위이내 입력
    cin >> a >> b >> c;
    cout << a+b+c;
	return 0;
}