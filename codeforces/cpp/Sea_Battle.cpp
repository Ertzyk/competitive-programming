#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, k, conseq_0 = 0;
    string s;
    cin >> n >> a >> b >> k >> s;
    vector<int> shoot;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') conseq_0++;
        else conseq_0 = 0;
        if(conseq_0 == b){
            shoot.push_back(i + 1);
            conseq_0 = 0;
        }
    }
    cout << shoot.size() - a + 1 << '\n';
    for(int i = 0; i < shoot.size() - a + 1; i++) cout << shoot[i] << " \n"[i == shoot.size() - a];
    return 0;
}