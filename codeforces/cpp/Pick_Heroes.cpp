#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t, count_out = 0;
    cin >> n >> m;
    vector<int> p(2*n), strong_pairs(2*n + 1, -1);
    for(int &x: p) cin >> x;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        strong_pairs[a] = b;
        strong_pairs[b] = a;
    }
    vector<bool> chosen(2*n + 1);
    cin >> t;
    while(t == 2 && count_out < 2*n){
        int x;
        cin >> x;
        chosen[x] = true;
        count_out++;
        if(strong_pairs[x] == -1) t = 1;
        else {
            cout << strong_pairs[x] << '\n';
            cout.flush();
            chosen[strong_pairs[x]] = true;
            count_out++;
            strong_pairs[strong_pairs[x]] = -1;
            strong_pairs[x] = -1;
        }
    }
    for(int i = 1; i <= 2*n; i++) if(strong_pairs[i] != -1){
        cout << ((p[i - 1] >= p[strong_pairs[i] - 1]) ? i : strong_pairs[i]) << '\n';
        cout.flush();
        int x;
        cin >> x;
        chosen[strong_pairs[i]] = chosen[i] = true;
        strong_pairs[strong_pairs[i]] = -1;
        count_out += 2;
    }
    priority_queue<pair<int, int>> pq;
    for(int i = 1; i <= 2*n; i++) if(!chosen[i]) pq.push({p[i - 1], i});
    while(!pq.empty()){
        cout << pq.top().second << '\n';
        cout.flush();
        count_out++;
        if(count_out == 2*n) break;
        pq.pop();
        int x;
        cin >> x;
        count_out++;
        chosen[x] = true;
        while(!pq.empty() && chosen[pq.top().second]) pq.pop();
    }
    return 0;
}