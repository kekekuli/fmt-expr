#include <iostream>

class Useless{
private:
    int n;
    char *pc;
    static int ct;
    void ShowObject() const;
public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless &f);
    Useless(Useless &&f);
    ~Useless();
    Useless operator+(const Useless &f) const;
    void ShowData() const;
};

int Useless::ct = 0;

Useless::Useless(){
    ct++;
    n = 0;
    pc = nullptr;
    std::cout << "default constructor called; number of objects: " << ct << std::endl;
    ShowObject();
}
Useless::Useless(int k):n(k){
    ct++;
    pc = new char[n];
    std::cout << "int constructor called; number of objects: " << ct << std::endl;
    ShowObject();
}
Useless::Useless(int k, char ch):n(k){
    ct++;
    pc = new char[n];
    for(int i = 0; i < n; i++){
        pc[i] = ch;
    }
    std::cout << "int char constructor called; number of objects: " << ct << std::endl;
    ShowObject();
}
Useless::Useless(const Useless &f):n(f.n){
    ct++;
    pc = new char[n];
    for(int i = 0; i < n; i++){
        pc[i] = f.pc[i];
    }
    std::cout << "copy constructor called; number of objects: " << ct << std::endl;
    ShowObject();
}
Useless::Useless(Useless &&f):n(f.n){
    ct++;
    pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
    std::cout << "move constructor called; number of objects: " << ct << std::endl;
    ShowObject();
}
Useless::~Useless(){
    std::cout << "destructor called; objects left: " << --ct << std::endl;
    ShowObject();
    delete [] pc;
}
Useless Useless::operator+(const Useless &f) const{
    std::cout << "Entering operator+()\n";
    Useless temp = Useless(n + f.n);
    for(int i = 0; i < n; i++){
        temp.pc[i] = pc[i];
    }
    for(int i = n; i < temp.n; i++){
        temp.pc[i] = f.pc[i - n];
    }
    std::cout << "temp object:\n";
    std::cout << "Leaving operator+()\n";
    return temp;
}
void Useless::ShowObject() const{
    std::cout << "Number of elements: " << n;
    std::cout << " Data address: " << (void *)pc << std::endl;
}

void Useless::ShowData() const{
    if(n == 0){
        std::cout << "object empty\n";
    }else{
        for(int i = 0; i < n; i++){
            std::cout << pc[i];
        }
        std::cout << std::endl;
    }
}