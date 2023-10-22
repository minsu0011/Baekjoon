/* https://www.acmicpc.net/problem/1931 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N;
    cin >> N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int n = 1;n <= N;n++){
        int x,y;
        cin >> x >> y;
        pq.push({y,x});
    }
    int end_time = pq.top().first;
    pq.pop();
    int cnt = 0;
    while(!pq.empty()){
        if(pq.top().second >= end_time){
            end_time = pq.top().first;
            cnt ++;
        }
        pq.pop();
    }
    cout << cnt + 1;
    return 0;
}