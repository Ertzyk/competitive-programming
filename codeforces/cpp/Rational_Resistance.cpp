#include <iostream>
using namespace std;
using ll = long long;

ll solve(ll a, ll b){
    if(b == 0){
        return 0;
    }
    if(a%b == 0){
        return a/b;
    }
    return a/b + b/(a%b) + solve(a%b, b%(a%b));
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}