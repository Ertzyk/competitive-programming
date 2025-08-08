#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

string bin(ll x){
    string result;
    do{
        result += '0' + (x%2);
        x /= 2;
    } while(x);
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, l, r, m = 1, ones = 0;
    cin >> n >> l >> r;
    l--;
    string b = bin(n);
    for(int i = 0; i < b.size(); i++){
        ones += (r + m)/2/m*(b[i] - '0') - (l + m)/2/m*(b[i] - '0');
        m *= 2;
    }
    cout << ones << '\n';
    return 0;
}