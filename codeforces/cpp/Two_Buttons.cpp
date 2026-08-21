#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, res = 0;
    cin >> n >> m;
    while(n != m){
        if(m < n){
            res += n - m;
            m = n;
        } else {
            if(m%2 == 0) m /= 2;
            else m++;
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}