#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for(ll &x: a) cin >> x;
        if(n == 2 || m < n){
            cout << -1 << '\n';
            continue;
        } else {
            ll sum = accumulate(a.begin(), a.end(), (ll)0);
            cout << sum*2 << '\n';
        }
        for(int i = 1; i < n; i++){
            cout << i << ' ' << i + 1 << '\n';
        }
        cout << n << ' ' << 1 << '\n';
    }
    return 0;
}