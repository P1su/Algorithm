#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> words = {"aya", "ye", "woo", "ma"};
    
    for(auto s : babbling){
        while(!s.empty()){
            bool matched = false;

            for(const auto& word : words){
                if(s.compare(0, word.length(), word) == 0){
                    s = s.substr(word.length());
                    matched = true;
                    break;
                }
            }

            if(!matched) break;
        }

        if(s.empty()) answer++;
    }

    return answer;
}