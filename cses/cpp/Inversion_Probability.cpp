#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> r(n);
    for(ll &x: r) cin >> x;
    double result = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            if(r[i] >= r[j]){
                result += (double)1 - (double)(r[j] + 1)/(double)(2*r[i]);
            } else {
                result += (double)(r[i] - 1)/(double)(2*r[j]);
            }
        }
    }
    cout << fixed << setprecision(6) << result << '\n';
    return 0;
}