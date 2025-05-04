#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> count_a(x + 1);
    while(n--){
        ll p;
        cin >> p;
        count_a[p]++;
    }
    for(int i = 1; i < x; i++){
        if(count_a[i]%(i + 1) == 0){
            count_a[i + 1] += count_a[i]/(i + 1);
        } else {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}