/* https://www.acmicpc.net/problem/1008 */
#include<iostream>
#include<string>
using namespace std;
int main(){
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    double a,b;
    cin >> a >> b;
    cout.precision(12);
    //실수 전체 자리수 12자리 출력 설정
    cout << fixed;
    //고정소수점 표기 설저
    cout << a/b;
    //cout.unsetf(ios::fixed);
    //고정소수점 해제
    return 0;
}
//c++ 기본 소수점 6자리 출력