#include <iostream>
using namespace std;
using ll = long long;

string solve(ll a, ll b, ll x){
    if(b == 0){
        return "NO";
    }
    if(a%b == x%b && x <= a){
        return "YES";
    }
    return solve(b, a%b, x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll a, b, x;
        cin >> a >> b >> x;
        if(a < b) swap(a, b);
        cout << solve(a, b, x) << '\n';
    }
    return 0;
}