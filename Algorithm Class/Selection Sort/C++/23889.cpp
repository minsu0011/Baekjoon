/* https://www.acmicpc.net/problem/23889 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int selection_sort_return(int N, vector<int> A, vector<int> B){
    int tmp = 0;
    int res = 0;
    for(int last = N ; last >= 2 ; last--){
        int maxa = -1;
        int maxb = -1;
        int ia = 0;
        int ib = 0;
        int cnt = 0;
        for(int j = 1; j <= last ; j++){
            if(maxa <= A[j]){
                maxa = A[j];
                ia = j;
            }
        }
        for(int j = 1; j <= last ; j++){
            if(maxb <= B[j]){
                maxb = B[j];
                ib = j;
            }
        }
        if(last!=ia){
            tmp = A[last];
            A[last] = A[ia];
            A[ia] = tmp;
        }
        if(last!=ib){
            tmp = B[last];
            B[last] = A[ib];
            B[ia] = tmp;
        }
        for(int n = 1 ; n <= N ; n++){
            if(A[n] == B[n]) cnt++;
        }
        if(cnt == N) res = 1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> A;
    vector<int> B;

    A.push_back(0);
    B.push_back(0);
    for(int n = 1; n <= N ; n++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    for(int n = 1; n <= N ; n++){
        int x;
        cin >> x;
        B.push_back(x);
    }
    int c = 0;
    for(int n = 1 ; n <= N ; n++){
        if(A[n] == B[n]) c++;
    }
    if(c == N){
        cout << "1";
        return 0;
    }
    int result;
    result = selection_sort_return(N,A,B);
    cout << result;
    return 0;
}