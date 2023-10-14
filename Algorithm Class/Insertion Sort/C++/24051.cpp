/* https://www.acmicpc.net/problem/24051 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int insertion_sort_return(int N, int K, vector<int> A){
    int cnt = 0;
    for(int n = 2 ; n <= N ; n++){
        int i = n-1;
        int key = A[n];
        while(i >= 1 && key < A[i]){
            A[i + 1] = A[i];
            i --;
            cnt ++;
            if(cnt == K) return A[i+2];
        }
        if(i + 1 != n){
            A[i+1] = key;
            cnt ++;
            if(cnt == K) return A[i+1];
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<int> A;
    int result = 0;
    A.push_back(0);
    for(int n = 1; n <= N ; n++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    result = insertion_sort_return(N,K,A);
    cout << result;
    return 0;
}