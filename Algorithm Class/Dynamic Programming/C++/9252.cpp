/* https://www.acmicpc.net/problem/9252 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
char A[1005];
char B[1005];
int arr[1005][1005];
int brr[1005][1005];
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
                brr[m][n] = 2;
            }
            else{
                if(arr[m-1][n] >= arr[m][n-1]){
                    arr[m][n] = arr[m-1][n];
                    brr[m][n] = 0;
                }
                else{ 
                    arr[m][n] = arr[m][n-1];
                    brr[m][n] = 1;
                }
            }
        }
    }
    int cnt = arr[M][N];
    char res[1005];
    int m1 = M;
    int n1 = N;
    while(true){
        if(brr[m1][n1] == 2){
            res[cnt] = A[m1-1];
            m1--;
            n1--;
            cnt--;
        }
        if(brr[m1][n1] == 1){
            n1--;
        }
        if(brr[m1][n1] == 0){
            m1--;
        }
        if(cnt == 0) break;
    }
    cout << arr[M][N] << "\n";
    for(int x = 1 ; x <= arr[M][N] ; x++) cout << res[x];
    return 0;
}