#include <iostream>
#include <map>
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
        vector<ll> a(n);
        for(ll &x: a) cin >> x;
        map<ll, ll> cnt_even, cnt_odd;
        for(int i = 0; i < n; i++){
            if(i%2) cnt_odd[a[i]]++;
            else cnt_even[a[i]]++;
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++){
            if(i%2) cnt_odd[a[i]]--;
            else cnt_even[a[i]]--;
        }
        bool flag = false;
        for(auto pr: cnt_odd){
            if(pr.second != 0){
                cout << "NO\n";
                flag = true;
                break;
            }
        }
        if(flag) continue;
        for(auto pr: cnt_even){
            if(pr.second != 0){
                cout << "NO\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout << "YES\n";
    }
    return 0;
}