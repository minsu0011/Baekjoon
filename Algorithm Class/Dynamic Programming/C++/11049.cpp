/* https://www.acmicpc.net/problem/11049 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int arr[505][505];
#define MAX_INT 2147483647
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N;
    vector<int> p;
    cin >> N;
    for(int n = 1 ; n <= N ; n++){
        int x,y;
        cin >> x >> y;
        if(n == 1) p.push_back(x);
        p.push_back(y);
    }
    for(int i = 1 ; i <= N ; i++) arr[i][i] = 0;
    for(int l = 2 ; l <= N ; l++){
        for(int i = 1 ; i <= N - l + 1 ; i++){
            int j = i + l - 1;
            arr[i][j] = MAX_INT;
            for(int k = i ; k <= j - 1 ; k++){
                int mi = arr[i][k] + arr[k+1][j] + p[i-1] * p[k] * p[j];
                if(mi < arr[i][j]) arr[i][j] = mi;
            }
        }
    }
    cout << arr[1][N];
    return 0;
}