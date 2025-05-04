#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    while(n != 1){
        cout << n << ' ';
        if(n%2) n = 3*n + 1;
        else n /= 2;
    }
    cout << 1;
    return 0;
}