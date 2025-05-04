#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

ll fast_exponentiation(ll a, ll b, ll m){
    if(b == 0) return 1;
    if(b%2) return a*fast_exponentiation(a, b - 1, m)%m;
    return fast_exponentiation(a*a%m, b/2, m);
}

ll newton_symbol(ll n, ll k){
    ll result = 1;
    if(k > n - k) k = n - k;
    for(int i = 1; i <= k; i++){
        result *= n - i + 1;
        result %= MOD;
        result *= fast_exponentiation(i, MOD - 2, MOD);
        result %= MOD;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> bucket(n + 1);
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            bucket[a]++;
        }
        for(int i = n; i > 0; i--){
            if(bucket[i] < k) k -= bucket[i];
            else if(bucket[i] == k){
                cout << "1\n";
                break;
            }
            else{
                cout << newton_symbol(bucket[i], k) << '\n';
                break;
            }
        }
    }
    return 0;
}