/*
1. Thread Safe Singleton
2. Implemented 5 Rule of C++
3. C++11 because of static variable only one time initialization for all threads
4. getInstance is inline function. A function defined inside class is Inline function.
5. We should avoid locking mechanism because it make the program slow.
If multiple threads attempt to initialize the same static local variable concurrently,
the initialization occurs exactly once (similar behaviour can be obtained for arbitrary functions with std::call_once).

*/
#include<iostream>

using namespace std;
class Singleton
{
public:
   static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }
    void print()
    {
        cout<<"This is Singleton Thread safe class with 5 Rules of C++ "<<endl;
    }
private:
    Singleton() = default;
    ~Singleton() = default;                      ///Destructor
    Singleton(const Singleton &obj) = delete;    ///Copy Constr
    Singleton(Singleton &&obj)  = delete;         ///Move Constr
    Singleton& operator=(const Singleton &obj) = delete;     ///Copy Assignment
    Singleton& operator=(Singleton &&obj) = delete;          ///Move Assignment

};
int main()
{
    for(int i=0;i<5;i++)
    {
        Singleton &instance = Singleton::getInstance();
        ///cout<<&instance<<endl;       ///Always, It will return same address or instance.
        instance.print();
        Singleton &insta = instance;
    }

    return 0;
}
