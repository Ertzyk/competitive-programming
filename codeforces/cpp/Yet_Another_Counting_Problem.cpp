#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
 
ll gcd(ll a, ll b){
    return (b == 0) ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll a, b, q;
        cin >> a >> b >> q;
        if(a == b){
            for(int i = 0; i < q; i++){
                ll l, r;
                cin >> l >> r;
            }
            for(int i = 0; i < q; i++) cout << '0' << " \n"[i == q - 1];
            continue;
        }
        if(a > b){
            swap(a, b);
        }
        ll g = lcm(a, b);
        for(int i = 0; i < q; i++){
            ll l, r, result;
            cin >> l >> r;
            result = r - l + 1 - (r/g - l/g)*b - min(b, r%g + 1) + min(b, l%g);
            cout << result << " \n"[i == q - 1];
        }
    }
    return 0;
}