#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int x1 = dots[0][0];
    int y1 = dots[0][1];

    int x2 = dots[1][0];
    int y2 = dots[1][1];

    int x3 = dots[2][0];
    int y3 = dots[2][1];

    int x4 = dots[3][0];
    int y4 = dots[3][1];

    // (1-2) vs (3-4)
    if ((y2 - y1) * (x4 - x3) == (y4 - y3) * (x2 - x1))
        return 1;

    // (1-3) vs (2-4)
    if ((y3 - y1) * (x4 - x2) == (y4 - y2) * (x3 - x1))
        return 1;

    // (1-4) vs (2-3)
    if ((y4 - y1) * (x3 - x2) == (y3 - y2) * (x4 - x1))
        return 1;

    return 0;
}