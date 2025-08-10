#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> p(39);
    p[0] = 1;
    for(int i = 1; i < 39; i++) p[i] = p[i - 1]*3;
    int q;
    cin >> q;
    while(q--){
        ll n, ans = 0, k = 38;
        cin >> n;
        while(n > 0){
            if(n > p[k]/2){
                ans += p[k];
                n -= p[k];
            }
            k--;
        }
        cout << ans << '\n';
    }
    cout << '\n';
    return 0;
}