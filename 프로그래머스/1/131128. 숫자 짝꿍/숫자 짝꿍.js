function solution(X, Y) {
    if(X >Y){
        var base = [...X];
        var target = [...Y];
    }else{
        var base = [...Y];
        var target = [...X];
    }
    
    base.sort((a,b) => b - a);
    target.sort((a, b) => (b - a));
    var cnt = 0;
    var ans = '';
    
    for(i = 0 ; i < base.length ; i++){
        if(base[i] == target[cnt]){
            ans += base[i];
            cnt++;
        }else if(base[i] < target[cnt]){
            cnt ++;
            i--;
        }
    }
    
    if(ans == '') return '-1';
    else if(ans[0] == '0') return '0';
    else return ans;
}