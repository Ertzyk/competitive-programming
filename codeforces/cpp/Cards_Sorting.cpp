#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    map<ll, vector<ll>> count;
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        count[a].push_back(i);
    }
    ll last = -1, left = n, delayed_left = n, result = 0;
    for(auto pr: count){
        auto it = upper_bound(pr.second.begin(), pr.second.end(), last);
        if(it != pr.second.begin()){
            left -= pr.second.end() - it;
            result += delayed_left;
            delayed_left = left;
            left -= it - pr.second.begin();
            last = *(it - 1);
        } else {
            left -= pr.second.size();
            last = pr.second.back();
        }
    }
    result += delayed_left;
    cout << result << '\n';
    return 0;
}