#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll &x: a) cin >> x;
    for(ll &x: b) cin >> x;
    unordered_map<ll, pair<int, ll>> count;
    for(int i = 0; i < n; i++){
        count[a[i]].first++;
        count[a[i]].second += b[i];
    }
    vector<ll> algo_for_group;
    ll result = 0;
    for(auto p: count){
        if(p.second.first > 1){
            algo_for_group.push_back(p.first);
            result += p.second.second;
        }
    }
    for(auto p: count){
        if(p.second.first == 1){
            for(auto l: algo_for_group){
                if((p.first & ~l) == 0){
                    result += p.second.second;
                    break;
                }
            }
        }
    }
    cout << result << '\n';
    return 0;
}