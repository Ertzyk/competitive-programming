#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(string &s: grid) cin >> s;
    vector<vector<char>> res(n, vector<char>(m));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            vector<bool> b(4, false);
            b[grid[i][j] - 'A'] = true;
            if(i > 0) b[res[i - 1][j] - 'A'] = true;
            if(j > 0) b[res[i][j - 1] - 'A'] = true;
            ll p = 0;
            while(b[p]) p++;
            res[i][j] = (char)(p + 'A');
            cout << res[i][j];
        }
        cout << '\n';
    }
    return 0;
}