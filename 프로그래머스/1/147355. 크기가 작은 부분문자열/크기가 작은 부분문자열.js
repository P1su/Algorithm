function solution(t, p) {
    var answer = 0;
    const plen = p.length;
    
    for(i = 0 ; i < t.length - plen + 1 ; i++){
        const target = t.slice(i, i + plen);
        
        if(target <= p){
            answer ++;
        }
    }
    
    return answer;
}