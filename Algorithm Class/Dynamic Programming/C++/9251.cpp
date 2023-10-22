/* https://www.acmicpc.net/problem/9251 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
char A[1005];
char B[1005];
int arr[1005][1005];
int M, N;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> A;
    cin >> B;
    M = strlen(A);
    N = strlen(B);
    arr[0][0] = 0;
    for(int m = 1 ; m <= M ; m++) arr[m][0] = 0;
    for(int n = 1 ; n <= N ; n++) arr[0][n] = 0;
    for(int n = 1 ; n <= N ; n++){
        for(int m = 1; m <= M ; m++){
            if(A[m-1] == B[n-1]){
                arr[m][n] = arr[m-1][n-1] + 1;
            }
            else{
                if(arr[m-1][n] >= arr[m][n-1]) arr[m][n] = arr[m-1][n];
                else arr[m][n] = arr[m][n-1];
            }
        }
    }
    cout << arr[M][N];
    return 0;
}