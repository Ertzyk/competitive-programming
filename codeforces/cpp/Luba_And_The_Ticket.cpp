#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int left = (s[0] - '0') + (s[1] - '0') + (s[2] - '0'), right = (s[3] - '0') + (s[4] - '0') + (s[5] - '0');
    if(left == right){
        cout << "0\n";
        return 0;
    }
    vector<int> changes;
    if(left < right){
        changes.push_back('9' - s[0]);
        changes.push_back('9' - s[1]);
        changes.push_back('9' - s[2]);
        changes.push_back(s[3] - '0');
        changes.push_back(s[4] - '0');
        changes.push_back(s[5] - '0');
    } else {
        changes.push_back(s[0] - '0');
        changes.push_back(s[1] - '0');
        changes.push_back(s[2] - '0');
        changes.push_back('9' - s[3]);
        changes.push_back('9' - s[4]);
        changes.push_back('9' - s[5]);
    }
    sort(changes.begin(), changes.end());
    int d = abs(left - right), result = 0;
    while(d > 0){
        d -= changes.back();
        changes.pop_back();
        result++;
    }
    cout << result << '\n';
    return 0;
}