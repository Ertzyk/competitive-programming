#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll d, k;
        cin >> d >> k;
        ll c = (ll)floor((double)d*sqrt(2)/(double)2/(double)k)*k;
        if(c*c + (c + k)*(c + k) <= d*d) cout << "Ashish\n";
        else cout << "Utkarsh\n";
    }
    return 0;
}