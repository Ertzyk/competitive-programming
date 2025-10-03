#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, rk, ck, rd, cd, result = 0;
        cin >> n >> rk >> ck >> rd >> cd;
        if(ck > cd) result = max(result, n - cd);
        else if(ck < cd) result = max(result, cd);
        if(rk > rd) result = max(result, n - rd);
        else if(rk < rd) result = max(result, rd);
        cout << result << '\n';
    }
    return 0;
}