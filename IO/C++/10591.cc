/* https://www.acmicpc.net/problem/10591 */
#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int a, b;
	while(scanf("%d %d", &a, &b) != EOF){
        printf("%d\n", a + b);
    }
	return 0;
}