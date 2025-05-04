#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> b(n);
    for(int &x: b) cin >> x;
    int max_val = *max_element(b.begin(), b.end()), min_val = *min_element(b.begin(), b.end());
    if(max_val != min_val) cout << max_val - min_val << ' ' << (ll)count(b.begin(), b.end(), max_val)*(ll)count(b.begin(), b.end(), min_val);
    else{
        ll x = count(b.begin(), b.end(), max_val);
        cout << "0 " << x*(x - 1)/2;
    }
    return 0;
}