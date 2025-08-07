#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, lowest_odd = INT_MAX, cur_sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a > 0) cur_sum += a;
        if(abs(a)%2 == 1) lowest_odd = min(lowest_odd, abs(a));
    }
    if(cur_sum%2 == 1) cout << cur_sum << '\n';
    else cout << cur_sum - lowest_odd << '\n';
    return 0;
}