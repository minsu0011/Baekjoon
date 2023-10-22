/* https://www.acmicpc.net/problem/11052 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N;
    int arr[1005];
    int r[1005];
    cin >> N;
    for(int n = 1 ; n <= N ; n++) cin >> arr[n];
    arr[0] = 0;
    r[0] = 0;
    for(int n = 1 ; n <= N ; n++){
        int t = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(t <= r[i] + arr[n-i]){
                t = r[i] + arr[n-i];   
            }
        }
        r[n] = t;
    }
    cout << r[N];
    return 0;
}