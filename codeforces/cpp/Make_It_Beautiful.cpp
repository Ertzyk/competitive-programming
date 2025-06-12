#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

string num_to_bin(ll n){
    string result;
    while(n > 0){
        if(n%2 == 1) result += '1';
        else result += '0';
        n /= 2;
    }
    while(result.size() < 64) result += '0';
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for(ll&x: a) cin >> x;
        vector<ll> c(64);
        ll beauty = 0;
        for(ll j: a){
            string st = num_to_bin(j);
            for(int i = 0; i < 64; i++){
                if(st[i] == '1') beauty++;
                else c[i]++;
            }
        }
        int pointer = 0;
        ll multi = 1;
        while(true){
            if(c[pointer] == 0){
                pointer++;
                multi *= 2;
            } else {
                if(k - multi >= 0){
                    k -= multi;
                    beauty++;
                    c[pointer]--;
                } else break;
            }
        }
        cout << beauty << '\n';
    }
    return 0;
}