#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> b(2*n), a(2*n + 2);
        for(ll &x: b) cin >> x;
        sort(b.begin(), b.end());
        ll l = 0, r = 2*n - 3, i = 4;
        a[1] = b[2*n - 1];
        a[3] = b[2*n - 2];
        a[2] = a[1] + a[3];
        while(l <= r){
            a[i] = b[l];
            a[2] -= a[i];
            l++;
            i++;
            a[i] = b[r];
            a[2] += a[i];
            r--;
            i++;
        }
        for(int i = 1; i < 2*n + 2; i++) cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}