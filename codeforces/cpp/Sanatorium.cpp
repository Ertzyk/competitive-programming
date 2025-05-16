#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll b, d, s;
    cin >> b >> d >> s;
    ll m = max(max(b, d), s);
    ll result = max((ll)0, m - 1 - b) + max((ll)0, m - 1 - d) + max((ll)0, m - 1 - s);
    cout << result << '\n';
    return 0;
}