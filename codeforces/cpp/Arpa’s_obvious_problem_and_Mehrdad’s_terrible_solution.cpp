#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x, result = 0;
    cin >> n >> x;
    unordered_map<ll, ll> hashmap;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        hashmap[a]++;
    }
    if(x == 0){
        for(auto p: hashmap) result += p.second*(p.second - 1);
    } else {
        for(auto p: hashmap) if(hashmap.find(x^p.first) != hashmap.end()) result += p.second*hashmap[x^p.first];
    }
    cout << result/2 << '\n';
    return 0;
}