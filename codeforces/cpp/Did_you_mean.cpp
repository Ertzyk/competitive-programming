#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int conseq_constants = 0;
    bool diff = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
            conseq_constants++;
            if(conseq_constants > 1 && s[i] != s[i - 1]) diff = true;
            if(conseq_constants >= 3 && diff){
                cout << ' ';
                conseq_constants = 1;
                diff = false;
            }
        } else {
            conseq_constants = 0;
            diff = false;
        }
        cout << s[i];
    }
    return 0;
}