function solution(s) {
    var flag = Array(26);
    var answer = [];
    
    for(i = 0 ; i < s.length ; i++){
        var idx = s[i].charCodeAt() - 97;
        
        if(flag[idx] === undefined){
            flag[idx] = i;
            answer.push(-1);
        }else{
            answer.push(i - flag[idx]);
            flag[idx] = i;
        }
    }
    
    return answer;
}