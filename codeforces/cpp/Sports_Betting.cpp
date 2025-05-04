#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    map<int, int> count;
    for(int x: a) count[x]++;
    bool carry = false;
    int prev = -1;
    for(auto pair: count){
        if(pair.first - 1 != prev) carry = false;
        if(pair.second >= 4){
            cout << "Yes\n";
            return;
        } else if(pair.second == 3 || pair.second == 2){
            if(carry){
                cout << "Yes\n";
                return;
            } else carry = true;
        }
        prev = pair.first;
    }
    cout << "No\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}