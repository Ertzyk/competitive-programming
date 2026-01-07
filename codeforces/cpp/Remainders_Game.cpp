#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> ld(1000001, 1);
    for(ll i = 2; i <= 1000000; i++){
        if(ld[i] == 1){
            ld[i] = i;
            for(ll j = i*i; j <= 1000000; j += i){
                if(ld[j] == 1) ld[j] = i;
            }
        }
    }
    vector<ll> num(1000000, 0);
    while(n--){
        ll c;
        cin >> c;
        while(c > 1){
            ll d = ld[c], cnt = 0;
            while(c%d == 0){
                cnt++;
                c /= d;
            }
            num[d] = max(num[d], cnt);
        }
    }
    bool flag = false;
    while(k > 1){
        ll d = ld[k], cnt = 0;
        while(k%d == 0){
            cnt++;
            k /= d;
        }
        if(num[d] < cnt){
            cout << "No\n";
            flag = true;
            break;
        }
    }
    if(!flag) cout << "Yes\n";
    return 0;
}