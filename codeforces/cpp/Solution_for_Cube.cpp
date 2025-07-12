#include <iostream>
#include <vector>
using namespace std;

bool same_color(int a, int b, int c, int d){
    return a == b && b == c && c == d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(25);
    for(int i = 1; i < 25; i++) cin >> a[i];
    if((same_color(a[13], a[14], a[15], a[16]) && same_color(a[17], a[18], a[19], a[20]) &&
        same_color(a[1], a[3], a[6], a[8]) && same_color(a[5], a[7], a[10], a[12]) &&
        same_color(a[9], a[11], a[21], a[23]) && same_color(a[2], a[4], a[22], a[24])) || 
        (same_color(a[13], a[14], a[15], a[16]) && same_color(a[17], a[18], a[19], a[20]) &&
        same_color(a[1], a[3], a[21], a[23]) && same_color(a[22], a[24], a[10], a[12]) &&
        same_color(a[9], a[11], a[6], a[8]) && same_color(a[2], a[4], a[5], a[7])) ||
        (same_color(a[5], a[6], a[7], a[8]) && same_color(a[21], a[22], a[23], a[24]) &&
        same_color(a[3], a[4], a[18], a[20]) && same_color(a[11], a[12], a[17], a[19]) &&
        same_color(a[9], a[10], a[13], a[15]) && same_color(a[1], a[2], a[14], a[16])) || 
        (same_color(a[5], a[6], a[7], a[8]) && same_color(a[21], a[22], a[23], a[24]) &&
        same_color(a[3], a[4], a[13], a[15]) && same_color(a[11], a[12], a[14], a[16]) &&
        same_color(a[9], a[10], a[18], a[20]) && same_color(a[1], a[2], a[17], a[19])) ||
        (same_color(a[1], a[2], a[3], a[4]) && same_color(a[9], a[10], a[11], a[12]) &&
        same_color(a[5], a[6], a[19], a[20]) && same_color(a[7], a[8], a[13], a[14]) &&
        same_color(a[15], a[16], a[21], a[22]) && same_color(a[17], a[18], a[23], a[24])) ||
        (same_color(a[1], a[2], a[3], a[4]) && same_color(a[9], a[10], a[11], a[12]) &&
        same_color(a[5], a[6], a[15], a[16]) && same_color(a[7], a[8], a[17], a[18]) &&
        same_color(a[19], a[20], a[21], a[22]) && same_color(a[13], a[14], a[23], a[24]))) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}