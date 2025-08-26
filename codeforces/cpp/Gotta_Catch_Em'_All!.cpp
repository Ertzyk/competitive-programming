#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    unordered_map<char, int> c;
    for(char ch : s) c[ch]++;
    cout << min(c['B'], min(c['u']/2, min(c['l'], min(c['b'], min(c['a']/2, min(c['s'], c['r'])))))) << '\n';
    return 0;
}