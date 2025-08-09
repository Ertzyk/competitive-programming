#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_set<string> hashset;
    while(n--){
        string s;
        cin >> s;
        if(hashset.count(s)) cout << "YES\n";
        else cout << "NO\n";
        hashset.insert(s);
    }
    return 0;
}