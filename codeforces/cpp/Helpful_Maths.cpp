#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> a;
    for(int i = 0; i < s.size(); i += 2) a.push_back(s[i] - '0');
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++){
        cout << a[i];
        if(i != a.size() - 1) cout << '+';
    }
    return 0;
}