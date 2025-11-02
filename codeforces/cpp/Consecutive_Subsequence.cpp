#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    map<int, int> mp;
    int max_conseq = 0, max_num = -1;
    for(int i = 0; i < n; i++){
        auto it = mp.find(a[i] - 1);
        mp[a[i]] = ((it != mp.end()) ? it->second : 0) + 1;
        if(max_conseq < mp[a[i]]){
            max_conseq = mp[a[i]];
            max_num = a[i];
        }
    }
    cout << max_conseq << '\n';
    int l = max_num - max_conseq + 1;
    for(int i = 1; i <= n; i++){
        if(a[i - 1] == l){
            cout << i << ' ';
            l++;
        }
    }
    cout << '\n';
    return 0;
}