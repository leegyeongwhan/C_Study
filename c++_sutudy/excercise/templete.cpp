#include<iostream>
#include<string>
//함수 
namespace my_template_space{

//템플릿이 없을때
    int sum (int a, int b){
        return a+b;
    }
    
    double sum(double a, double b){
        return a+b;
    }
}


//class
using namespace std;
template<typename T>
T sum (T a, T b){
        return a+b;
    }

template<class T1, class T2>
void printAll(T1 a, T2 b){
     count << "T1: " << a << endl;
     count << "T2: " << b << endl;
}

int main(){
    string s1 = "my1"; 
    string s2 = "my2"; 
    int num1 = 1; 
    int num2 = 5;

    printAll(s1,s2);
    printAll(num1,num2);
}
