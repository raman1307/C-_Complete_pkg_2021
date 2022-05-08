/*
The function std::call_once and the flag std::once_flag

You can use the function std::call_once to register a callable which will be executed exactly once.
The flag std::call_once in the following implementation guarantees that the singleton will be thread-safe initialized.

Note: static member function can use only  static member variable and static member functions.
*/
#include<iostream>
#include<mutex>

using namespace std;

class Singleton
{
public:
    static Singleton& getInstance()                 /// Inside static member function each member used must be static.
    {
        call_once(initFlagOnce,&Singleton::initSingletonOnce);

        return *instance;
    }
private:
    Singleton() = default;
    static Singleton *instance;
    static once_flag initFlagOnce;

    static void initSingletonOnce()
    {
        instance = new Singleton;
    }

    ~Singleton() = default;
    Singleton(const Singleton &obj) = delete;
    Singleton(Singleton &&obj) = delete;
    Singleton& operator=(const Singleton &obj) = delete;
    Singleton& operator=(Singleton &&obj) = delete;
};

Singleton* Singleton::instance = nullptr;
once_flag Singleton::initFlagOnce;

int main()
{
    for(int i=0; i<5;i++)
    {
        Singleton &instance = Singleton::getInstance();
        cout<<&instance<<endl;
    }
    return 0;
}
