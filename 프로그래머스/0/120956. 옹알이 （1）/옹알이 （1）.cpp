#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> words = {"aya", "ye", "woo", "ma"};
    
    for(auto &s: babbling){
        bool flag = 0;
        
        while(s != ""){
            for(auto word: words){
                if(s.find(word) == 0){
                    s = s.substr(word.length());
                    flag = 0;
                    break;
                }else{
                    flag = 1;
                }
            } 
            if(flag)break;
        }
        
        if(flag){
            continue;
        }else{
            answer++;
        }
        
    }
    return answer;
}