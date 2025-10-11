#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    sort(a.begin(), a.end());
    bool seen_pair = false;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]){
            if(a[i] == 0 || seen_pair || (i >= 2 && a[i - 1] == a[i - 2] + 1)){
                cout << "cslnb\n";
                return 0;
            }
            seen_pair = true;
        }
    }
    cout << (((accumulate(a.begin(), a.end(), (ll)0) - n*(n - 1)/2)%2) ? "sjfnb\n" : "cslnb\n");
    return 0;
}