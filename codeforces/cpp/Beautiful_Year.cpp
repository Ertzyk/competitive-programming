#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool diff_digits(int n){
    string s = to_string(n);
    vector<bool> nums(10, false);
    for(char ch: s){
        if(nums[ch - '0']) return false;
        else nums[ch - '0'] = true;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int y;
    cin >> y;
    while(true){
        y++;
        if(diff_digits(y)){
            cout << y << '\n';
            break;
        }
    }
    return 0;
}