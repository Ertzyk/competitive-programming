#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;

struct Customer{
    ll t, l, h;
};

pair<ll, ll> intersects(pair<ll, ll> a, pair<ll, ll> b){
    return {max(a.first, b.first), min(a.second, b.second)};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        vector<Customer> customers(n);
        for(auto &c: customers) cin >> c.t >> c.l >> c.h;
        auto p = intersects({customers[0].l, customers[0].h}, {m - customers[0].t, m + customers[0].t});
        if(p.first > p.second){
            cout << "NO\n";
            continue;
        }
        customers[0].l = p.first;
        customers[0].h = p.second;
        bool flag = false;
        for(ll i = 1; i < n; i++){
            auto p = intersects({customers[i].l, customers[i].h}, {customers[i - 1].l - customers[i].t + customers[i - 1].t, customers[i - 1].h + customers[i].t - customers[i - 1].t});
            if(p.first > p.second){
                cout << "NO\n";
                flag = true;
                break;
            }
            customers[i].l = p.first;
            customers[i].h = p.second;
        }
        if(!flag) cout << "YES\n";
    }
    return 0;
}