#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;
using ll = long long;

ll llrand(){
    return (((ll)rand()*(ll)RAND_MAX + (ll)rand())*(ll)RAND_MAX + (ll)rand())*(ll)RAND_MAX + (ll)rand();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    ll l = 3, r = 1000000000000000000, result = 3;
    while(l <= r){
        ll m = (3*l + 2*r)/5, response;
        cout << "? " << m << ' ' << llrand()%(m - 1) + 1 << '\n';
        cout.flush();
        cin >> response;
        if(response == -1) r = m - 1;
        else {
            result = max(m, response + 1);
            l = result + 1;
        }
    }
    cout << "! " << result;
    return 0;
}