#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if(k > n){
        cout << "NO\n";
        return 0;
    }
    vector<int> bin(32, 0);
    int p = 0, count = 0;
    while(n > 0){
        if(n%2 == 1){
            bin[p]++;
            count++;
        }
        n /= 2;
        p++;
    }
    if(k < count){
        cout << "NO\n";
        return 0;
    }
    p = 31;
    while(count < k){
        if(bin[p] > 0){
            bin[p]--;
            bin[p - 1] += 2;
            count++;
        } else p--;
    }
    cout << "YES\n";
    ll d = 1;
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < bin[i]; j++) cout << d << ' ';
        d *= 2;
    }
    cout << '\n';
    return 0;
}