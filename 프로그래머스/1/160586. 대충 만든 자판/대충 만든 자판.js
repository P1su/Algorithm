function solution(keymap, targets) {
    var answer = [];
    var alphList = Array(26);
    
    for(i = 0 ; i < keymap.length; i++){
        for(j = 0 ; j < keymap[i].length ; j++){
            const curNum = keymap[i][j].charCodeAt() - 65;
            if(alphList[curNum] > j + 1 || alphList[curNum] === undefined){
                alphList[curNum] = j + 1;
            }
        }
    }

    for(x = 0 ; x < targets.length ; x++){
        var cnt = 0;
        for(y = 0 ; y < targets[x].length ; y++){
            const curNum = targets[x][y].charCodeAt() - 65;
            
            if(alphList[curNum] === undefined){
                cnt = -1;
                break;
            }else {
                cnt += alphList[curNum];
            }
        }
        answer.push(cnt);
    }
    
    return answer;
}