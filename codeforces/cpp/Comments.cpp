#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t, d;
    cin >> s;
    vector<string> strs;
    vector<int> counts;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ','){
            if(s[i - 1] >= '0' && s[i - 1] <= '9'){
                counts.push_back(stoi(d));
                d.clear();
            } else {
                strs.push_back(t);
                t.clear();
            }
        } else if(s[i] >= '0' && s[i] <= '9') d += s[i];
        else t += s[i];
    }
    counts.push_back(stoi(d));
    vector<vector<int>> graph(strs.size());
    stack<int> st;
    queue<pair<int, int>> q, q2;
    for(int i = 0; i < counts.size(); i++){
        if(st.empty()){
            q.push({i, 1});
            q2.push({i, 0});
        } else {
            graph[st.top()].push_back(i);
            st.pop();
        }
        for(int j = 0; j < counts[i]; j++) st.push(i);
    }
    int max_depth = 1, prev_depth = -1;
    while(!q.empty()){
        auto [node, depth] = q.front();
        q.pop();
        max_depth = depth;
        for(int neighbor: graph[node]) q.push({neighbor, depth + 1});
    }
    cout << max_depth;
    while(!q2.empty()){
        auto [node, depth] = q2.front();
        q2.pop();
        cout << ((depth == prev_depth) ? ' ' : '\n') << strs[node];
        prev_depth = depth;
        for(int neighbor: graph[node]) q2.push({neighbor, depth + 1});
    }
    cout << '\n';
    return 0;
}