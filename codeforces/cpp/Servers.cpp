#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    priority_queue<int, vector<int>, greater<int>> unoccupied;
    for(int i = 1; i <= n; i++) unoccupied.push(i);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < q; i++){
        int t, k, d;
        cin >> t >> k >> d;
        while(!pq.empty() && pq.top().first <= t){
            unoccupied.push(pq.top().second);
            pq.pop();
        }
        if(unoccupied.size() >= k){
            int s = 0;
            while(k--){
                s += unoccupied.top();
                pq.push({d + t, unoccupied.top()});
                unoccupied.pop();
            }
            cout << s << '\n';
        } else cout << "-1\n";
    }
    return 0;
}