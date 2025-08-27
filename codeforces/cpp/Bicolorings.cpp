#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    if(k == 1 || n == 1){
        cout << "2\n";
        return 0;
    }
    vector<ll> prevww(k + 1), prevwb(k + 1), prevbw(k + 1), prevbb(k + 1), curww(k + 1), curwb(k + 1), curbw(k + 1), curbb(k + 1);
    prevww[1] = prevbb[1] = prevwb[2] = prevbw[2] = 1;
    for(int i = 2; i <= n; i++){
        curww[1] = curbb[1] = 1;
        for(int pk = 2; pk <= k; pk++){
            curww[pk] = (prevww[pk] + prevwb[pk] + prevbw[pk] + prevbb[pk - 1])%998244353;
            curwb[pk] = (prevww[pk - 1] + prevwb[pk] + prevbw[pk - 2] + prevbb[pk - 1])%998244353;
            curbw[pk] = (prevww[pk - 1] + prevwb[pk - 2] + prevbw[pk] + prevbb[pk - 1])%998244353;
            curbb[pk] = (prevww[pk - 1] + prevwb[pk] + prevbw[pk] + prevbb[pk])%998244353;
        }
        swap(prevww, curww);
        swap(prevwb, curwb);
        swap(prevbw, curbw);
        swap(prevbb, curbb);
    }
    cout << (prevww[k] + prevwb[k] + prevbw[k] + prevbb[k])%998244353 << '\n';
    return 0;
}