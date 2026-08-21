#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l = 1, r = 1000000000;
    while(l < r){
        ll m = (l + r)/2;
        cout << "? " << m << '\n';
        cout.flush();
        string response;
        cin >> response;
        if(response == "YES") l = m + 1;
        else r = m;
    }
    cout << "! " << l << '\n';
    cout.flush();
    return 0;
}