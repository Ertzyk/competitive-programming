#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, res = 1;
    cin >> n;
    vector<ll> a(n), segments;
    for(ll &x: a) cin >> x;
    segments.reserve(n);
    segments.push_back(0);
    for(ll i = 1; i < n; i++) if(a[i - 1] >= a[i]){
        res = max(res, i - segments.back());
        segments.push_back(i);
    }
    res = max(res, n - segments.back());
    segments.push_back(n);
    for(ll i = 0; i < segments.size() - 2; i++){
        if(segments[i + 1] - segments[i] > 1 && segments[i + 2] - segments[i + 1] > 1 &&
        (a[segments[i + 1] - 2] < a[segments[i + 1]] || a[segments[i + 1] - 1] < a[segments[i + 1] + 1])){
            res = max(res, segments[i + 2] - segments[i] - 1);
        }
    }
    cout << res << '\n';
    return 0;
}