#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    ll needB = 0, needS = 0, needC = 0, curB, curS, curC, priceB, priceS, priceC, rub;
    for(char ch: s){
        if(ch == 'B') needB++;
        else if(ch == 'S') needS++;
        else needC++;
    }
    cin >> curB >> curS >> curC >> priceB >> priceS >> priceC >> rub;
    ll l = min(min(needB ? curB/needB : 101, needS ? curS/needS : 101), needC ? curC/needC: 101), hamburger_price = needB*priceB + needS*priceS + needC*priceC;
    ll r = rub/hamburger_price + 100, result = l;
    while(l <= r){
        ll m = (l + r)/2;
        if(m*hamburger_price - min(curB, m*needB)*priceB - min(curS, m*needS)*priceS - min(curC, m*needC)*priceC <= rub){
            result = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << result << '\n';
    return 0;
}