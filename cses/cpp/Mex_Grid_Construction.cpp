#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll mex(const vector<vector<ll>> &res, ll pos_i, ll pos_j){
    vector<bool> a(pos_i + pos_j + 1, false);
    ll i = pos_i, j = pos_j;
    i--;
    while(i >= 0) {
        a[res[i][j]] = true;
        i--;
    }
    i = pos_i;
    j--;
    while(j >= 0) {
        a[res[i][j]] = true;
        j--;
    }
    i = 0;
    while(a[i]) i++;
    return i;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for(ll i = 0; i < n; i++){
        res[0][i] = i;
        res[i][0] = i;
    }
    for(ll i = 1; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            ll m = mex(res, i, j);
            res[i][j] = m;
            res[j][i] = m;
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cout << res[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}