#include <iostream>
#include <bitset>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

set<int> divisors(int x, const vector<int>& prime_list){
    set<int> result;
    int i = 0;
    while(x > 1 && prime_list[i]*prime_list[i] <= x && i < prime_list.size()){
        if(x%prime_list[i] == 0){
            result.insert(prime_list[i]);
            while(x%prime_list[i] == 0) x /= prime_list[i];
        }
        i++;
    }
    if(x > 1) result.insert(x);
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k = 0;
    cin >> n;
    vector<pair<int, int>> pairs(n);
    for(auto &x: pairs) cin >> x.first >> x.second;
    vector<int> prime_list;
    bitset<44722> is_prime;
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i < 44722; i++){
        if(is_prime[i]){
            prime_list.push_back(i);
            for(int j = i*i; j < 44722; j += i){
                is_prime[j] = 0;
            }
        }
    }
    set<int> p = divisors(pairs[0].first, prime_list), q = divisors(pairs[0].second, prime_list), potential_cand;
    set_union(p.begin(), p.end(), q.begin(), q.end(), inserter(potential_cand, potential_cand.begin()));
    for(int x: potential_cand){
        bool flag = true;
        for(int i = 1; i < n; i++){
            if(pairs[i].first%x && pairs[i].second%x){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << x;
            return 0;
        }
    }
    cout << -1;
    return 0;
}