function solution(triangle) {
    const depth = triangle.length - 1;

    for(i = depth - 1 ; i >= 0 ; i--){
        for(j = 0 ; j < i + 1 ; j++){
            triangle[i][j] = Math.max(triangle[i][j] + triangle[i + 1][j], triangle[i][j] + triangle[i + 1][j + 1]);
        }
    }
    
    return triangle[0][0];
}