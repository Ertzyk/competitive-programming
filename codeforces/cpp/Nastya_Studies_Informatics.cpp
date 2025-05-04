#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

int count_combinations(ll cur, ll pointer, const vector<ll>& relatively_prime, const ll& l, const ll& r, const ll& gcd, const ll& lcm){
    if(pointer == relatively_prime.size()){
        if(l <= cur && r >= cur && gcd*lcm/cur >= l && gcd*lcm/cur <= r){
            return 1;
        }
        return 0;
    }
    return count_combinations(cur*relatively_prime[pointer], pointer + 1, relatively_prime, l, r, gcd, lcm) + 
    count_combinations(cur, pointer + 1, relatively_prime, l, r, gcd, lcm);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l, r, x, y;
    cin >> l >> r >> x >> y;
    if(y%x != 0){
        cout << 0;
        return 0;
    }
    ll d = y/x, k = 2;
    vector<ll> relatively_prime;
    while(d > 1 && k*k <= y/x){
        if(d%k == 0){
            ll c = 0;
            while(d%k == 0){
                d /= k;
                c++;
            }
            relatively_prime.push_back(pow(k, c));
        }
        k++;
    }
    if(d > 1) relatively_prime.push_back(d);
    cout << count_combinations(x, 0, relatively_prime, l, r, x, y);
    return 0;
}