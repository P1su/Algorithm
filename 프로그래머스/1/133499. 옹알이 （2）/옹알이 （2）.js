//4가지 단어 중 처음 나오는 것만 확인하면 된다. 

function solution(babblings) {
    const words = ['aya', 'ye', 'woo', 'ma'];
    var answer = 0;
    var prevWord = '';
    
    function slice(babbling, prevWord) {
        for(i = 0 ; i < 4 ; i++){
            if(babbling.startsWith(words[i])){
                //이전 글자와 겹치면 return 
                if(words[i] === prevWord){
                    return;
                }else{
                    //문자열 자르기 substr
                    babbling = babbling.substr(words[i].length);
                    if(babbling === ''){
                        //전부 발음
                        answer++;
                        return
                    }else{
                        //남은 문자를 확인
                        slice(babbling, words[i]);
                    }
                }
            }
        }
        return;
    }
    
    babblings.forEach((babbling) => {
        slice(babbling);
    })
    
    return answer;
}