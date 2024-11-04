#include <fmt/core.h>
#include <fmt/color.h>
#include <vector>
#include <iostream>
#include <string>

void remodel(std::string &str)
{
    std::string *ps = new std::string(str);
    str = *ps;
    delete ps;
    return;
}

template<auto x> constexpr auto constant = x;

template<typename U, int I>
class MyArray{
public:
    U arr[I];
    U& operator[](int i){
        return arr[i];
    }
};

template<typename T, template<typename U, int I> class Arr, int I>
class MyClass{
public:
    T t;
    Arr<T, I> arr;
    void print(){
        for(int i = 0; i < I; i++){
            fmt::print("arr[{}] = {}\n", i, arr[i]);
        }
    }
};

template <typename T, typename Allocator = std::allocator<T>>
class vector{

};

template<typename T>
struct list_node{
    T data;
};

template<typename T> struct PTS{
    enum{
        IsPointer = 0,
        IsPointerToDataMember = 0;
    };
};

template<typename T> struct PTS<T*>{
    enum{
        IsPointer = 1,
        IsPointerToDataMember = 0
    };
};

template<class T, class U> struct PTS<T U::*>{
    enum{
        IsPointer = 1,
        IsPointerToDataMember = 1
    };
};

struct S{
    int age;
};

class Reflection{
private:
    int r;
};

template <template<typename, typename> typename Container, typename Type>
class Example{
public:
    Container<Type, std::allocator<Type>> c;
};  

template<typename T>
void foo(T t){
    fmt::print("No pointer\n");
}

template<typename T>
void foo(T* t){
    fmt::print("Pointer\n");
}

void foo(MyClass<int, MyArray, 10>* t){
    fmt::print("Vector\n"); 
}

void PrintCin(){
    while(std::cin>>std::ws){
        std::string str;
        std::getline(std::cin, str);
        // remodel(str);
        fmt::print("{}\n", str);
    }
}


void template_expr(){
    // auto x = constant<42>;
    // auto y = constant<'a'>;
    // auto z = constant<3.14>;

    // fmt::print("x = {}\n", x);
    // fmt::print("y = {}\n", y);
    // fmt::print("z = {}\n", z);

    // MyClass<int, MyArray, 10> mc;
    // mc.print();

    // MyClass<std::string, MyArray, 5> mc;
    // mc.arr[0] = "Hello";
    // mc.print();
    
    // vector<int> v;

    // fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "Hello, world!\n");
    // fmt::print(fg(fmt::color::green) | fmt::emphasis::italic, "你好世界!\n");
    

    // Example<std::vector, int> e;

    // fmt::print("{}", (int)PTS<int*>::IsPointer);

    // fmt::print("{}", (int)PTS<int S::*>::IsPointer);     

    // int S::* p = nullptr;
    // p = &S::age;

    // S s;
    // s.age = 42;

    // fmt::print("{}\n", s.*p); 
    // s.*p = 43;
    // fmt::print("{}\n", s.age);

    // int Reflection::* p = nullptr;

    // foo(42);
    // vector<int>* t = nullptr;
    // foo(t);
    // MyClass<int, MyArray, 10> *mc = nullptr;
    // foo(mc);

}