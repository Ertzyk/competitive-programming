#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    if(n == 1){
        cout << "1 1\n" << -a[0] << "\n1 1\n0\n1 1\n0";
        return 0;
    }
    cout << "1 1\n" << -a[0] << "\n2 " << n << '\n';
    a[0] = 0;
    for(int i = 1; i < n; i++){
        cout << a[i]*(n - 1) << " \n"[i == n - 1];
        a[i] = a[i]*n;
    }
    cout << "1 " << n << '\n';
    for(int i = 0; i < n; i++) cout << -a[i] << " \n"[i == n - 1];
    return 0;
}