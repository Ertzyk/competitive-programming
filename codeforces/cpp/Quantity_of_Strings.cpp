#include <iostream>
using namespace std;
using ll = long long;
int const MOD = 1000000007;

ll fast_exponentiation(ll a, ll b, ll m){
    int result = 1;
    while(b > 0){
        if(b%2) result = (result*a)%m;
        a = a*a%m;
        b /= 2;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, c;
    cin >> n >> m >> k;
    if(n == k) c = (n + 1)/2;
    else if(k == 1 || k > n) c = n;
    else if(k%2) c = 2;
    else c = 1;
    cout << fast_exponentiation(m, c, MOD);
    return 0;
}