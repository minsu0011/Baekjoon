/* https://www.acmicpc.net/problem/24092 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;
int N;
int A[10005];
int B[10005];
int a,b;
int res = 0;
int cnt;

void compare(void){
    for(int n = 1 ; n <= N ; n++)
        if(A[n] == B[n]) cnt++;
    if(cnt == N) res = 1;
}

int Partition(int p, int r){
    int x = A[r];
    int i = p - 1;
    for (int j = p ; j <= r - 1 ; j++){
        if(A[j] <= x){
            i++;
            int t = A[j];
            A[j] = A[i];
            A[i] = t;
            if(A[i] == B[i]) cnt++;
            if(A[j] == B[j]) cnt++;
            if(A[i] == B[j]) cnt --;
            if(A[j] == B[i]) cnt --;
            if(cnt == N) res = 1;
            if(res == 1)return 1;
        }
    }
    if (i+1 != r) {
        int t = A[i+1];
        A[i+1] = A[r];
        A[r] = t;
        if(A[i+1] == B[i+1]) cnt++;
        if(A[r] == B[r]) cnt++;
        if(A[r] == B[i+1]) cnt --;
        if(A[i+1] == B[r]) cnt --;
        if(cnt == N) res = 1;
        if(res == 1) return 1;
    }
    return i+1;
}

void QuickSort(int p, int r){
    if (p < r){
        int q = Partition(p, r);
        if(res == 1) return;
        QuickSort(p, q-1);
        if(res == 1) return;
        QuickSort(q+1, r);
        if(res == 1) return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N;
    A[0] = 0;
    B[0] = 0;
    for(int n = 1; n <= N ; n++){
        int x;
        cin >> x;
        A[n] = x;
    }
    for(int n = 1; n <= N ; n++){
        int x;
        cin >> x;
        B[n] = x;
    }
    compare();
    if(res == 1){
        cout << "1";
        return 0;
    }
    //N, K, A are inserted
    QuickSort(1, N);
    cout << res;
    return 0;
}