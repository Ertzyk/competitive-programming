#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<pair<int, int>, int> mp;
    int n, c = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            if(b[i] == 0) c++;
            continue;
        }
        bool is_negative = ((ll)a[i]*(ll)b[i] < 0);
        a[i] = abs(a[i]);
        b[i] = abs(b[i]);
        int g = gcd(a[i], b[i]);
        a[i] /= g;
        b[i] /= g;
        if(is_negative) a[i] *= -1;
        mp[{a[i], b[i]}]++;
    }
    int res = 0;
    for(auto p: mp) res = max(res, p.second);
    cout << res + c << '\n';
    return 0;
}