#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

// 두 사람 사이 선물을 더 많이 줌 -> 다음 달에 하나 받음
// 선물 지수가 높음 -> 선물을 받기 보다 많이 줌
// 두 사람 사이 선물 기록 없거나 횟수가 같다면 선물 지수 낮은 사람이 높은 사람에게 하나 줌
// 선물 횟수도 같고 선물 지수도 같으면 선물을 주고 받지 않음

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string, map<string, int>> giftCnt; // 주고 받은 선물
    map<string, pair<int,int>> giftScore; // 준 선물과 받은 선물
    
    for(int i = 0 ; i < gifts.size() ; i++){
        stringstream ss(gifts[i]); // 공백 제거
        
        string giver, receiver; 
        ss>>giver>>receiver; // 준 사람과 받은 사람 변수 할당
        
        giftCnt[giver][receiver]++; // 준 사람이 받은 사람에게 준 선물의 개수 증가
        
        giftScore[giver].first++; // 준 사람의 준 선물 증가
        giftScore[receiver].second++; // 받은 사람의 받은 선물 증가
    }
    
    /*
    map의 값 확인용 출력
    for(const auto& outer: giftCnt){
        cout<<outer.first<<endl;
        for(const auto& inner: outer.second){
            cout<<" "<<inner.first<<" : "<<inner.second<<endl;
        }
    }
    
    for (const auto& [name, score] : giftScore) {
        cout << name << " - 준 선물: " << score.first << ", 받은 선물: " << score.second << endl;
    }*/
    
    for(int i = 0 ; i < friends.size() ; i++){ // 본인을 기준으로
        int cnt = 0;
        for(int j = 0 ; j < friends.size() ; j++){ // 친구 순회
            string name = friends[i];
            string other = friends[j];
            
            if(giftCnt[name][other] > giftCnt[other][name]){ // 만약 선물을 더 많이 줬다면
                cnt++; // 선물을 받음
            }else if(giftCnt[name][other] == giftCnt[other][name]){ // 만약 횟수가 같다면
                int myScore = giftScore[name].first - giftScore[name].second;
                int friendScore = giftScore[other].first - giftScore[other].second;
                
                if(myScore > friendScore){
                    cnt++;
                }
            }
        }
        
        answer = max(answer, cnt);
    }
    
    
    return answer;
}