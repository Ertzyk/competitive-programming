#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k = 0;
        cin >> n;
        vector<int> a(n), left_out;
        for(int &x: a) cin >> x;
        vector<pair<int, int>> graph(n + 1);
        unordered_set<int> out, in;
        for(int i = 1; i <= n; i++){
            out.insert(i);
            in.insert(i);
        }
        for(int i = 0; i < n; i++){
            if(in.count(a[i])){
                graph[i + 1].first = a[i];
                graph[a[i]].second = i + 1;
                out.erase(i + 1);
                in.erase(a[i]);
                k++;
            }
        }
        vector<int> out_vector(out.begin(), out.end()), in_vector(in.begin(), in.end());
        for(int i = 0; i < out_vector.size(); i++){
            if(out_vector[i] == in_vector[i]) left_out.push_back(out_vector[i]);
            else{
                graph[out_vector[i]].first = in_vector[i];
                graph[in_vector[i]].second = out_vector[i];
                in.erase(in_vector[i]);
            }
        }
        if(left_out.size() > 1){
            for(int i = 0; i < left_out.size() - 1; i++) graph[left_out[i]].first = left_out[i + 1];
            graph[left_out.back()].first = left_out[0];
        } else if(left_out.size() == 1){
            graph[graph[a[left_out[0] - 1]].second].first = left_out[0];
            graph[left_out[0]].first = a[left_out[0] - 1];
        }
        cout << k << '\n';
        for(int i = 1; i <= n; i++) cout << graph[i].first << " \n"[i == n];
    }
    return 0;
}