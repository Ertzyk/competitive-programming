#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void add_to_result(const vector<int>& cur_delete, vector<string>& result, const string& core_string){
    int start = 0;
    string s = core_string;
    if(cur_delete.size()%2){
        s[cur_delete[0]] = s[cur_delete[1]] = s[cur_delete[2]] = '1';
        result.push_back(s);
        start = 3;
    }
    for(int i = start; i < cur_delete.size(); i += 2){
        s = core_string;
        s[cur_delete[i]] = s[cur_delete[i + 1]] = '1';
        result.push_back(s);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<pair<int, int>> max_heap;
    vector<string> result;
    string core_string(n, '0');
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        max_heap.push({a, i});
    }
    while(true){
        auto [largest, largest_idx] = max_heap.top();
        max_heap.pop();
        auto [second_largest, second_largest_idx] = max_heap.top();
        if(largest == second_largest){
            max_heap.push({largest, largest_idx});
            break;
        } else {
            max_heap.pop();
            max_heap.push({max(second_largest - 1, 0), second_largest_idx});
            max_heap.push({max(largest - 1, 0), largest_idx});
            string s = core_string;
            s[largest_idx] = s[second_largest_idx] = '1';
            result.push_back(s);
        }
    }
    vector<pair<int, int>> a;
    a.reserve(n);
    while(!max_heap.empty()){
        auto [x, idx] = max_heap.top();
        max_heap.pop();
        a.push_back({x, idx});
    }
    vector<int> cur_delete;
    cur_delete.reserve(n);
    cur_delete.push_back(a[0].second);
    cur_delete.push_back(a[1].second);
    for(int i = 2; i < n; i++){
        if(a[i].first != a[i - 1].first){
            for(int j = 0; j < a[i - 1].first - a[i].first; j++){
                add_to_result(cur_delete, result, core_string);
            }
        }
        cur_delete.push_back(a[i].second);
    }
    cout << a.back().first << '\n' << result.size() << '\n';
    for(string res: result) cout << res << '\n';
    return 0;
}