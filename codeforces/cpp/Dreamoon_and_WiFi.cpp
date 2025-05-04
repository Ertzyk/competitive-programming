#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int goal = 0, cur = 0, unknown = 0;
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] == '+') goal++;
        else goal--;
        if(s2[i] == '+') cur++;
        else if(s2[i] == '-') cur--;
        else unknown++;
    }
    if(abs(goal - cur) > unknown){
        cout << 0;
        return 0;
    }
    double res = 1;
    for(int i = 0; i < (unknown - abs(goal - cur))/2; i++){
        res *= (double)(unknown - i);
        res /= (double)(i + 1);
    }
    res /= (double)pow(2, unknown);
    cout << fixed << setprecision(10) << res;
    return 0;
}