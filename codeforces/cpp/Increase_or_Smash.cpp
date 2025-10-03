#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        unordered_set<int> sett;
        for(int x: a) sett.insert(x);
        cout << sett.size()*2 - 1 << '\n';
    }
    return 0;
}