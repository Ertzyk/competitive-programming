#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll v;
    cin >> v;
    vector<ll> a(10, 0);
    for(ll i = 1; i < 10; i++) cin >> a[i];
    ll min_d = 0, cnt_min_d = 100001;
    for(ll i = 1; i < 10; i++){
        if(a[i] <= cnt_min_d){
            cnt_min_d = a[i];
            min_d = i;
        }
    }
    ll res_len = v/cnt_min_d;
    if(res_len == 0){
        cout << "-1\n";
        return 0;
    }
    v -= res_len*cnt_min_d;
    for(ll i = 9; i > min_d; i--){
        while(a[i] - cnt_min_d <= v){
            v -= a[i] - cnt_min_d;
            cout << i;
            res_len--;
        }
    }
    for(ll i = 0; i < res_len; i++) cout << min_d;
    cout << '\n';
    return 0;
}