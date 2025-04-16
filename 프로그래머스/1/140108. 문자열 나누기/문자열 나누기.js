function solution(s) {
    var answer = 0;
    
    while(s.length > 0) {
        var cnt1 = 1;
        var cnt2 = 0;
        
        for(i = 1 ; i < s.length ; i++){
            if(s[0] === s[i]){
                cnt1 ++;
            }else cnt2 ++;
            
            if(cnt1 === cnt2){
                s = s.slice(cnt1+cnt2); 
                answer ++;
                break;
            }
        }
        if(cnt1 > cnt2)break;
    }
    if(s.length > 0){
        answer ++;
    }
    return answer;
}