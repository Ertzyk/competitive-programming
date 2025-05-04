#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x: a) cin >> x;
    ll sum = accumulate(a.begin(), a.end(), (ll)0);
    if(sum%3){
        cout << 0;
        return 0;
    }
    ll f_part = sum/3, s_part = 2*sum/3, cur = 0, result = 0;
    int count_s = 0;
    for(int i = 0; i < n - 1; i++){
        cur += a[i];
        if(cur == s_part){
            count_s++;
        }
    }
    cur = 0;
    for(int i = 0; i < n - 2; i++){
        cur += a[i];
        if(cur == s_part){
            count_s--;
        }
        if(cur == f_part){
            result += count_s;
        }
    }
    cout << result;
    return 0;
}