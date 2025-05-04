#include <iostream>
#include <vector>
#include <utility>
#include <bitset>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k = 1;
    cin >> n >> m;
    if(n == 2){
        cout << "2 2\n1 2 2";
        return 0;
    }
    vector<vector<int>> edges(m, vector<int>(3));
    edges[0] = {1, n, 2};
    for(int i = 1; i < n - 2; i++){
        edges[k] = {i, i + 1, 1};
        k++;
    }
    int mstw = n;
    bitset<200000> sieve;
    sieve.set();
    sieve[0] = sieve[1] = 0;
    for(ll i = 2; i < 200000; i++){
        if(sieve[i]){
            for(ll j = i*i; j < 200000; j += i) sieve[j] = 0;
        }
    }
    while(!sieve[mstw]) mstw++;
    edges[k] = {n - 2, n - 1, mstw - n + 1};
    k++;
    if(m == k){
        cout << 2 << ' ' << mstw << '\n';
        for(auto v: edges) cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
        return 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 2; j <= n; j++){
            if(i == 1 && j == n) continue;
            edges[k] = {i, j, 1000000000};
            k++;
            if(k == m){
                cout << 2 << ' ' << mstw << '\n';
                for(auto v: edges) cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
                return 0;
            }
        }
    }
    if(k < m) edges[k] = {n - 1, n, 1000000000};
    cout << 2 << ' ' << mstw << '\n';
    for(auto v: edges) cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
    return 0;
}