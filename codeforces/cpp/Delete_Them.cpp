#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> files(n);
    vector<int> to_del(m);
    vector<bool> visited(m, false);
    for(string &x: files) cin >> x;
    for(int &x: to_del) cin >> x;
    string pattern = files[to_del[0] - 1];
    visited[to_del[0] - 1] = true;
    for(int i = 1; i < m; i++){
        if(pattern.size() != files[to_del[i] - 1].size()){
            cout << "No\n";
            return 0;
        }
        for(int j = 0; j < pattern.size(); j++) if(pattern[j] != '?' && pattern[j] != files[to_del[i] - 1][j]) pattern[j] = '?';
        visited[to_del[i] - 1] = true;
    }
    for(int i = 0; i < n; i++){
        if(visited[i] || pattern.size() != files[i].size()) continue;
        bool the_same = true;
        for(int j = 0; j < pattern.size(); j++) if(pattern[j] != '?' && pattern[j] != files[i][j]) the_same = false;
        if(the_same){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n" << pattern << '\n';
    return 0;
}