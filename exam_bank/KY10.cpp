// 球的半径和体积
// https://www.nowcoder.com/practice/4b733a850c364c32b368555c8c2ec96b
// Hard
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double PI = acos(-1);

class Ball{
    int x0, y0, z0, x1, y1, z1;
public:
    double radius;
    double volume;
    Ball(int cx, int cy, int cz, int xx, int xy, int xz) : x0(cx), y0(cy), z0(cz), x1(xx), y1(xy), z1(xz) {
        radius = sqrt(abs(cx - xx) * abs(cx - xx) + abs(cy - xy) * abs(cy - xy) + abs(cz - xz) * abs(cz - xz));
        volume = double(4.0 / 3.0) * PI * radius * radius * radius;
    }
};

int main(){
    int a, b, c, d, e, f;
    while( cin >> a >> b >> c >> d >> e >> f ){
        Ball* ba = new Ball(a, b, c, d, e, f);
        printf("%.3f %.3f" , ba->radius, ba->volume);
        cout << endl;
    }
}