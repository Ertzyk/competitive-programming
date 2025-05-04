#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> merge(vector<ll> a, vector<ll> b){
    vector<ll> result(10);
    for(int i = 0; i <= 9; i++) result[i] = a[i] + b[i];
    return result;
}

vector<ll> map(vector<ll> a, vector<vector<ll>>& table, int k){
    vector<ll> result(10);
    for(int i = 0; i <= 9; i++){
        result[table[k][i]] += a[i];
    }
    return result;
}

vector<ll> solve(int k, string n, vector<vector<ll>>& table, vector<vector<vector<ll>>>& precal){
    vector<ll> result(10);
    result = map(precal[n.size()][n[0] - '0' - 1], table, k);
    if(n.size() == 1) return result;
    result = merge(result, solve(table[k][n[0] - '0'], n.substr(1), table, precal));
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<vector<vector<ll>>> precal(19, vector<vector<ll>>(10, vector<ll>(10)));
    vector<vector<ll>> table = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 2, 4, 6, 8, 0, 2, 4, 6, 8},
        {0, 3, 6, 9, 2, 5, 8, 2, 8, 4},
        {0, 4, 8, 2, 6, 0, 8, 6, 6, 8},
        {0, 5, 0, 5, 0, 0, 0, 5, 0, 0},
        {0, 6, 2, 8, 8, 0, 8, 8, 6, 0},
        {0, 7, 4, 2, 6, 5, 8, 8, 0, 8},
        {0, 8, 6, 8, 6, 0, 6, 0, 8, 4},
        {0, 9, 8, 4, 8, 0, 0, 8, 4, 8}
    };
    vector<ll> cur(10);
    for(int i = 0; i <= 9; i++){
        cur[i] = 1;
        precal[1][i] = cur;
    }
    for(int i = 2; i <= 18; i++){
        vector<ll> base = precal[i - 1][9];
        precal[i][0] = base;
        for(int j = 1; j <= 9; j++){
            for(int k = 0; k <= 9; k++){
                cur[table[j][k]] += base[k]; 
            }
            precal[i][j] = cur;
        }
    }
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            cout << "i: " << i << " j: " << j  << " Res: ";
            for(int k = 0; k <= 9; k++){
                cout << precal[i][j][k] << ' ';
            }
            cout << '\n';
        }
    }
    while(t--){
        string n;
        cin >> n;
        vector<ll> result(10);
        result = solve(1, n, table, precal);
        for(int x: result) cout << x << ' ';
    }
    return 0;
}