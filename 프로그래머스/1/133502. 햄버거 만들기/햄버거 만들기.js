// 1->2->3->1 의 순서 찾기 ,, 123 오름차순 혹은 총합이 7
//스택..?

function solution(ingredients) {
    var ans = 0;
    var list = [];
    
    ingredients.forEach((ingredient) => {
        list.push(ingredient);
        if(JSON.stringify(list.slice(-4))=== JSON.stringify([ 1, 2, 3, 1 ])){
            list.splice(list.length-4, 4);
            ans ++;
        }
    })
    
    return ans;
}