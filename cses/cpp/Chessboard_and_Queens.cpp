#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;

bool check_if_free(vector<string> &c, ll pos){
    ll pointer = pos - 1;
    while(pointer/8 == pos/8){
        if(c[pointer/8][pointer%8] == 'q') return false;
        pointer--;
    }
    pointer = pos - 8;
    while(pointer >= 0){
        if(c[pointer/8][pointer%8] == 'q') return false;
        pointer -= 8;
    }
    pointer = pos;
    while(pointer%8 != 0 && pointer >= 9){
        pointer -= 9;
        if(c[pointer/8][pointer%8] == 'q') return false;
    }
    pointer = pos;
    while(pointer%8 != 7 && pointer >= 8){
        pointer -= 7;
        if(c[pointer/8][pointer%8] == 'q') return false;
    }
    return true;
}

ll solve(vector<string> &c, ll idx, ll cnt_q){
    if(cnt_q == 8) return 1;
    if(idx == 64) return 0;
    if(c[idx/8][idx%8] == '*') return solve(c, idx + 1, cnt_q);
    ll res = solve(c, idx + 1, cnt_q);
    if(check_if_free(c, idx)){
        c[idx/8][idx%8] = 'q';
        res += solve(c, idx + 8 - idx%8, cnt_q + 1);
        c[idx/8][idx%8] = '.';
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<string> c(8);
    for(string &x: c) cin >> x;
    cout << solve(c, 0, 0) << '\n';
    return 0;
}