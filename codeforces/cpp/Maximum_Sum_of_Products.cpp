#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll &x: a) cin >> x;
    for(ll &x: b) cin >> x;
    ll no_reverse = 0;
    for(int i = 0; i < n; i++) no_reverse += a[i]*b[i];
    ll result = no_reverse;
    for(int i = 1; i < n - 1; i++){
        int l = i - 1, r = i + 1;
        ll cur = no_reverse;
        while(l >= 0 && r < n){
            cur += a[l]*b[r] + a[r]*b[l] - a[l]*b[l] - a[r]*b[r];
            result = max(result, cur);
            l--;
            r++;
        }
    }
    for(int i = 0; i < n - 1; i++){
        int l = i, r = i + 1;
        ll cur = no_reverse;
        while(l >= 0 && r < n){
            cur += a[l]*b[r] + a[r]*b[l] - a[l]*b[l] - a[r]*b[r];
            result = max(result, cur);
            l--;
            r++;
        }
    }
    cout << result << '\n';
    return 0;
}