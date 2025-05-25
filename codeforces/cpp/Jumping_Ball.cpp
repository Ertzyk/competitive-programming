#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, result = 0, pointer = 0;
    cin >> n;
    string s;
    cin >> s;
    while(pointer < n && s[pointer] == '<'){
        pointer++;
        result++;
    }
    pointer = n - 1;
    while(pointer > -1 && s[pointer] == '>'){
        pointer--;
        result++;
    }
    cout << result << '\n';
    return 0;
}