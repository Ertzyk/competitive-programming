#include <iostream>
using namespace std;
using ll = long long;
 
ll fact(ll n){
    if(n == 0) return 1;
    return n*fact(n - 1);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll A, B;
    cin >> A >> B;
    cout << fact(min(A, B)) << '\n';
    return 0;
}