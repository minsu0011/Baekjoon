/* https://www.acmicpc.net/problem/23882 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> selection_sort_return(int N, int K, vector<int> A){
    int cnt = 0;
    int tmp = 0;
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(-1);
    int start = 0, end = 0;
    for(int last = N ; last >= 2 ; last--){
        int maxj = -1;
        int i = 0;
        for(int j = 1; j <= last ; j++){
            if(maxj <= A[j]){
                maxj = A[j];
                i = j;
            }
        }
        if(last!=i){
            start = A[last];
            end = A[i];
            tmp = A[last];
            A[last] = A[i];
            A[i] = tmp;
            cnt ++;
        }
        if(cnt == K){
            return A;
        }
    }
    return arr;
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

    A.push_back(0);
    for(int n = 1; n <= N ; n++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    vector<int> result;
    result = selection_sort_return(N,K,A);
    if(result[1] == -1 ) cout << "-1";
    else{
        for(int n = 1 ; n <= N ; n++){
            cout << result[n] << ' ';
        }
    }
    return 0;
}