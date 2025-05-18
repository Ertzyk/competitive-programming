#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

pair<pair<int, int>, pair<int, int>> find_two_largest(vector<pair<int, int>>& a){
    int m1 = 0, m2 = 0, m1idx = 0, m2idx = 0;
    for(auto x: a){
        if(x.second > m1){
            m2 = m1;
            m1 = x.second;
            m2idx = m1idx;
            m1idx = x.first;
        } else if(x.second > m2){
            m2 = x.second;
            m2idx = x.first;
        }
    }
    return {{m1idx, m1}, {m2idx, m2}};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c;
    cin >> n;
    map<pair<int, int>, vector<pair<int, int>>> hashmap;
    int cur_max = 0, k = 1, stone1 = 0, stone2 = 0;
    for(int i = 1; i <= n; i++){
        cin >> a >> b >> c;
        if(min(min(a, b), c) > cur_max){
            cur_max = min(min(a, b), c);
            stone1 = i;
        }
        if(min(a, b) > cur_max) hashmap[{min(a, b), max(a, b)}].push_back({i, c});
        if(min(b, c) > cur_max) hashmap[{min(b, c), max(b, c)}].push_back({i, a});
        if(min(c, a) > cur_max) hashmap[{min(c, a), max(c, a)}].push_back({i, b});
    }
    for(auto p: hashmap){
        if(p.second.size() < 2) continue;
        a = p.first.first;
        b = p.first.second;
        auto x = find_two_largest(p.second);
        c = x.first.second + x.second.second;
        if(min(min(a, b), c) > cur_max){
            k = 2;
            cur_max = min(min(a, b), c);
            stone1 = x.first.first;
            stone2 = x.second.first;
        }
    }
    if(k == 1) cout << "1\n" << stone1 << '\n';
    else cout << "2\n" << stone1 << ' ' << stone2 << '\n';
    return 0;
}