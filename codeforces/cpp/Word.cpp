#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string w;
    cin >> w;
    int lower = 0, upper = 0;
    for(char ch: w)(ch >= 'a' && ch <= 'z') ? lower++ : upper++;
    if(lower >= upper) for(auto &ch: w) ch = (char)tolower(ch);
    else for(auto &ch: w) ch = (char)toupper(ch);
    cout << w;
    return 0;
}