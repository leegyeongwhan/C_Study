#include <iostream>


using namespace std;

//class 의 이름은 namespace의 역할을 할 수 있다.
class Vector2{
    public:
    Vector2();
    Vector2(float x, float y);

    float GetX() const; //get 함수는 const로하자
    float GetY() const;

        Vector2 Add(Vector2 rhs){
            return Vector2(x + rhs.x, y+rhs.y);
        }
    private:
     float x;
     float y;
};


    //  Vector2 Sum(Vector2 a, Vector2 b){
    //     return Vector2(a.GetX + b.GetX, a.GetY+b.GetY);
    // }

int main(){

    
    return 0;
}

