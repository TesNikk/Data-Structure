#include<iostream>
using namespace std;
class rect {
public:
    int l, w;
    rect(){
        l=10;
        w=5;
    }
    rect(int l1, int w1) {
        l = l1;
        w = w1;
    }
};
int main() {
    rect r1;
    cout << r1.l << " " << r1.w << endl;*
    
    
    
    }