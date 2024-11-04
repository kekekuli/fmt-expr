#include "Useless.hpp"

int main(){
    {
        Useless one(10, 'x');
        Useless two = one;
        Useless three(20, 'o');
        Useless four(one + three);
        std::cout << "Object one: ";
        one.ShowData();
        std::cout << "Object two: ";
        two.ShowData();
        std::cout << "Object three: ";
        three.ShowData();
        std::cout << "Object four: ";
        four.ShowData();
    }
    return 0;
}