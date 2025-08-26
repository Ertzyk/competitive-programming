#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int n;
    cin >> s >> n;
    bool first_letter = false, second_letter = false;
    while(n--){
        string a;
        cin >> a;
        if(a[0] == s[1]) second_letter = true;
        if(a[1] == s[0]) first_letter = true;
        if(a == s) first_letter = second_letter = true;
    }
    cout << ((first_letter && second_letter) ? "Yes\n" : "No\n");
    return 0;
}