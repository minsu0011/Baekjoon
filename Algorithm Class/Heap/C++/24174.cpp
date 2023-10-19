/* https://www.acmicpc.net/problem/24174 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;
int N, K;
int cnt;
int swapa, swapb;
int A[500005];
int min_vector_index(int a, int b, int c, int i){
    if(a <= c && a <= b) return i;
    else if (b <= a && b <= c) return 2*i;
    else return (2*i + 1);
}

void MinHeapify(int i, int l){
    for (int j = i ; j <= (l / 2) ; ){
        if(j*2 == l){
            if(A[j] > A[l]){
                int t = A[j];
                A[j] = A[l];
                A[l] = t;
                cnt ++;
                if(cnt == K){
                    swapa = A[j];
                    swapb = A[l];
                    return;
                }
            }
            return;
        }
        int index;
        index = min_vector_index(A[j], A[2*j], A[2*j+1], j);
        if(index == j) break;
        else if(index == 2*j){
            int t = A[j];
            A[j] = A[2*j];
            A[2*j] = t;
            cnt ++;
            if(cnt == K){
                swapa = A[j];
                swapb = A[2*j];
                return;
            }
            j = 2*j;
        }
        else{
            int t = A[j];
            A[j] = A[2*j+1];
            A[2*j+1] = t;
            cnt ++;
            if(cnt == K){
                swapa = A[j];
                swapb = A[2*j+1];
                return;
            }
            j = 2*j + 1;
        }
    }
    return;
}

void BuildMinHeap(){
    int t = N;
    for (int i = t / 2 ; i >= 1 ; i--){
        MinHeapify(i, t);
        if(cnt == K) return;
    }
    return;
}

void HeapSort(void){
    BuildMinHeap();
    if(cnt == K) return;
    int l = N;
    for(int i = l ; i >= 2 ; i--){
        int t = A[1];
        A[1] = A[i];
        A[i] = t;
        cnt ++;
        if(cnt == K){
            swapa = A[1];
            swapb = A[i];
            return;
        }
        MinHeapify(1, i - 1);
        if(cnt == K) return;
    }
    return;

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
    HeapSort();
    if(cnt < K) cout << "-1";
    else{
        for(int i = 1 ;i <= N ;i ++) cout << A[i] << " ";   
    } 
    return 0;
}