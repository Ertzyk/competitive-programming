#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    unordered_set<char> letters;
    for(char ch: s) letters.insert(ch);
    cout << ((letters.size()%2) ? "IGNORE HIM!" : "CHAT WITH HER!");
    return 0;
}