/* https://www.acmicpc.net/problem/24173 */
//time out
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, K;
int cnt;
int swapa, swapb;
int min_vector_index(int a, int b, int c, int i){
    if(a <= c && a <= b) return i;
    else if (b <= a && b <= c) return 2*i;
    else return (2*i + 1);
}

vector<int> MinHeapify(vector<int> A, int i, int l){
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
                    return A;
                }
            }
            return A;
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
                return A;
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
                return A;
            }
            j = 2*j + 1;
        }
    }
    return A;
}

vector<int> BuildMinHeap(vector<int> A){
    int t = (A.size() - 1);
    for (int i = t / 2 ; i >= 1 ; i--){
        A = MinHeapify(A ,i, t);
    }
    return A;
}

vector<int> HeapSort(vector<int> A){
    A = BuildMinHeap(A);
    int l = A.size() - 1;
    for(int i = l ; i >= 2 ; i--){
        int t = A[1];
        A[1] = A[i];
        A[i] = t;
        cnt ++;
        if(cnt == K){
            swapa = A[1];
            swapb = A[i];
        }
        A = MinHeapify(A, 1, i - 1);
    }
    return A;

}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N;
    cin >> K;
    vector<int> A;
    int result = 0;
    A.push_back(0);
    for(int n = 1; n <= N ; n++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    //N, K, A are inserted
    A = HeapSort(A);
    if(cnt < K) cout << "-1";
    else{
        if(swapa < swapb) cout << swapa << " " << swapb << '\n';
        else cout << swapb << " " << swapa << '\n';     
    } 
    return 0;
}