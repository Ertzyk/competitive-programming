#include <iostream>
using namespace std;

void solve(string &a, string &b, int pa, int pb){
    while(pa < (int)a.size() && a[pa] == '0') pa++;
    while(pb < (int)b.size() && b[pb] == '0') pb++;
    if(pa == (int)a.size() && pb == (int)b.size()){
        cout << "=\n";
        return;
    } else if(pb == (int)b.size()){
        cout << ">\n";
        return;
    } else if(pa == (int)a.size()){
        cout << "<\n";
        return;
    } else if((int)a.size() - pa - (int)b.size() + pb >= 2){
        cout << ">\n";
        return;
    } else if((int)b.size() - pb - (int)a.size() + pa >= 2){
        cout << "<\n";
        return;
    } else if((int)a.size() - pa == (int)b.size() - pb) solve(a, b, pa + 1, pb + 1);
    else if((int)a.size() - pa - (int)b.size() + pb == 1){
        if(a[pa + 1] == '1' || (int)a.size() - pa == 2 || (a[pa + 2] == '1' && b[pb + 1] == '0')){
            cout << ">\n";
            return;
        } else if(a[pa + 2] == '0' && b[pb + 1] == '0'){
            a[pa + 2] = '1';
            solve(a, b, pa + 2, pb + 1);
        } else if(a[pa + 2] == '1' && b[pb + 1] == '1'){
            b[pb + 1] = '0';
            solve(a, b, pa + 2, pb + 1);
        } else solve(a, b, pa + 3, pb + 2);
    } else {
        if(b[pb + 1] == '1' || (int)b.size() - pb == 2 || (b[pb + 2] == '1' && a[pa + 1] == '0')){
            cout << "<\n";
            return;
        } else if(b[pb + 2] == '0' && a[pa + 1] == '0'){
            b[pb + 2] = '1';
            solve(a, b, pa + 1, pb + 2);
        } else if(b[pb + 2] == '1' && a[pa + 1] == '1'){
            a[pa + 1] = '0';
            solve(a, b, pa + 1, pb + 2);
        } else solve(a, b, pa + 2, pb + 3);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    solve(a, b, 0, 0);
    return 0;
}