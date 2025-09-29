#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, result = 0, prev = 0, conseq = 0;
    cin >> n >> k;
    vector<int> conseq0;
    bool first = true;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        t = ((t >= 0) ? 0 : -1);
        if(t == 0){
            if(first) continue;
            conseq++;
        } else {
            first = false;
            k--;
            if(conseq > 0){
                conseq0.push_back(conseq);
                conseq = 0;
            }
        }
        if(prev != t) result++;
        prev = t;
    }
    if(k < 0){
        cout << "-1\n";
        return 0;
    }
    if(conseq == 0) conseq = n + 1;
    sort(conseq0.begin(), conseq0.end());
    for(int i = 0; i < conseq0.size(); i++){
        if(k >= conseq0[i]){
            result -= 2;
            k -= conseq0[i];
        } else break;
    }
    if(k >= conseq) result--;
    cout << result << '\n';
    return 0;
}