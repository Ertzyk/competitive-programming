#include <iostream>
#include <climits>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, l, r, c;
        cin >> n >> l >> r >> c;
        bool same_ends = true;
        ll min_l_cost = c, min_r_cost = c, min_l_num = l, max_r_num = r, min_same_cost = c;
        cout << c << '\n';
        for(ll i = 0; i < n - 1; i++){
            cin >> l >> r >> c;
            if(l == min_l_num && r == max_r_num){
                if(same_ends) min_same_cost = min(min_same_cost, c);
                else {
                    same_ends = true;
                    min_same_cost = c;
                }
            } else if(l <= min_l_num && r >= max_r_num){
                same_ends = true;
                min_same_cost = c;
            } else if(min_l_num > l || max_r_num < r) same_ends = false;
            if(l < min_l_num){
                min_l_num = l;
                min_l_cost = c;
            } else if(l == min_l_num) min_l_cost = min(min_l_cost, c);
            if(r > max_r_num){
                max_r_num = r;
                min_r_cost = c;
            } else if(r == max_r_num) min_r_cost = min(min_r_cost, c);
            cout << min(min_l_cost + min_r_cost, (same_ends ? min_same_cost : LLONG_MAX)) << '\n';
        }
    }
    return 0;
}