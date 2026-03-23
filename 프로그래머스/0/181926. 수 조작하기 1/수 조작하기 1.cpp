#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, string control) {
  
    for(auto &c: control){
        if(c == 'w'){
            n += 1;
        }else if(c == 's'){
            n -= 1;
        }else if(c == 'd'){
            n += 10;
        }else if(c == 'a'){
            n -= 10;
        }
        
    }
    return n;
}