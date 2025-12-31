#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin >> k;
    vector<ll> cnt(10, 1);
    ll m = 1, d = 0;
    while(m < k){
        m /= cnt[d%10];
        cnt[d%10]++;
        m *= cnt[d%10];
        d++;
    }
    string res;
    while(cnt[0]--) res += 'c';
    while(cnt[1]--) res += 'o';
    while(cnt[2]--) res += 'd';
    while(cnt[3]--) res += 'e';
    while(cnt[4]--) res += 'f';
    while(cnt[5]--) res += 'o';
    while(cnt[6]--) res += 'r';
    while(cnt[7]--) res += 'c';
    while(cnt[8]--) res += 'e';
    while(cnt[9]--) res += 's';
    cout << res << '\n';
    return 0;
}