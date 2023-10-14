/* https://www.acmicpc.net/problem/24061 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_INT 2147483647
int cnt;
vector<int> A;
int res;
int N;
int K;
void merge(int p, int q, int r){
    int L[250005];
    int R[250005];
    L[0] = 0;
    R[0] = 0;
    int n1 = q - p + 1;
    int n2 = r - q;
    for(int i = 1 ; i <= n1 ; i++) L[i] = A[p + i - 1];
    for(int j = 1 ; j <= n2 ; j++) R[j] = A[q + j];
    L[n1+1] = MAX_INT;
    R[n2+1] = MAX_INT;
    int i = 1;
    int j = 1;
    for (int k = p ; k <= r ; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
            cnt++;
        }
        else {
            A[k] = R[j];
            j++;
            cnt++;
        }
        if(cnt == K) {
            for(int n = 1; n <= N ; n++){
                cout << A[n] << ' ';
            }
            res = 1;
        } 
    }
}

void merge_sort(int p, int r){
    if (p < r){
        int q1 = (p + r)/2;
        merge_sort(p, q1);
        merge_sort(q1+1, r);
        merge(p, q1, r);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N;
    cin >> K;
    A.push_back(0);
    for(int n = 1; n <= N ; n++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    merge_sort(1, N);
    if(res == 0) cout << -1;
    return 0;
}