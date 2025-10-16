#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l, k;
    string s;
    cin >> n >> l >> k >> s;
    vector<string> result(n);
    sort(s.begin(), s.end());
    int respointer = 0, spointer = 0;
    while(result[k - 1].size() < l){
        while(respointer < k){
            result[respointer] += s[spointer];
            respointer++;
            spointer++;
        }
        respointer--;
        while(respointer > 0 && result[respointer] == result[respointer - 1]) respointer--;
    }
    for(int i = 0; i < n; i++){
        while(result[i].size() < l){
            result[i] += s[spointer];
            spointer++;
        }
    }
    for(string x: result) cout << x << '\n';
    return 0;
}