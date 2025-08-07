#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int k;
    cin >> s >> k;
    if(k > s.size()) cout << "impossible\n";
    else {
        unordered_set<char> sett;
        for(char ch: s) sett.insert(ch);
        cout << max(0, k - (int)sett.size()) << '\n';
    }
    return 0;
}