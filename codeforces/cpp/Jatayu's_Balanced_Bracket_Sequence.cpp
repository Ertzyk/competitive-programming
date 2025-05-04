#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, cur = 0, max_cur = 0, result = 0;
        string a;
        cin >> n >> a;
        for(char x: a){
            if(x == '('){
                cur++;
                if(cur > max_cur){
                    max_cur = cur;
                    result++;
                }
            } else {
                cur--;
                max_cur = cur + 1;
            }
        }
        cout << result << '\n';
    }
    return 0;
}