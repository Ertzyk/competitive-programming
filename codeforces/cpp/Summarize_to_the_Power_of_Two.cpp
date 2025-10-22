#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k = 1, res = 0;
    cin >> n;
    vector<ll> a(n), powerof2;
    for(ll &x: a) cin >> x;
    unordered_set<ll> st, st2;
    for(ll x: a) {
        if(st.count(x)) st2.insert(x);
        else st.insert(x);
    }
    while(k < 2000000000){
        powerof2.push_back(k);
        k *= 2;
    }
    for(ll x: a){
        bool found = false;
        if(!st2.count(x)) st.erase(x);
        for(ll y: powerof2){
            if(st.count(y - x)){
                found = true;
                break;
            }
        }
        if(!found) res++;
        if(!st2.count(x)) st.insert(x);
    }
    cout << res << '\n';
    return 0;
}