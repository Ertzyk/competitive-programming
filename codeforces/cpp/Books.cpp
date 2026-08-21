#include <iostream>
#include <deque>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, t, sum = 0, result = 0;
    cin >> n >> t;
    deque<ll> dq;
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        dq.push_back(a);
        sum += a;
        while(!dq.empty() && sum > t){
            sum -= dq.front();
            dq.pop_front();
        }
        result = max(result, (ll)dq.size());
    }
    cout << result << '\n';
    return 0;
}