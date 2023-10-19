/* https://www.acmicpc.net/problem/24091 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;
int N, K;
int cnt;
int A[500005];
int a,b;

int Partition(int p, int r){
    int x = A[r];
    int i = p - 1;
    for (int j = p ; j <= r - 1 ; j++){
        if(A[j] <= x){
            i++;
            int t = A[j];
            A[j] = A[i];
            A[i] = t;
            cnt ++;
            if(cnt == K){
                a = A[i];
                b = A[j];
                return 1;
            }
        }
    }
    if (i+1 != r) {
        int t = A[i+1];
        A[i+1] = A[r];
        A[r] = t;
        cnt ++;
        if(cnt == K) {
            a = A[i+1];
            b = A[r];
            return 1;
        }
    }
    return i+1;
}

void QuickSort(int p, int r){
    if (p < r){
        int q = Partition(p, r);
        if(cnt == K) return;
        QuickSort(p, q-1);
        if(cnt == K) return;
        QuickSort(q+1, r);
        if(cnt == K) return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N;
    cin >> K;
    int result = 0;
    A[0] = 0;
    for(int n = 1; n <= N ; n++){
        int x;
        cin >> x;
        A[n] = x;
    }
    //N, K, A are inserted
    QuickSort(1, N);
    if(cnt < K) cout << "-1";
    else{
        for(int n = 1 ; n <= N ; n++) cout << A[n] << " ";
    }
    return 0;
}