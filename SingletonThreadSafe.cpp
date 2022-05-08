#include<iostream>
#include<mutex>

using namespace std;

class Singleton
{
public:
    static Singleton* getInstance()
    {
        if(!instance)
            {
                unique_lock<mutex> lock(mtx);       ///Here lock_guard<mutex> mylock(mtx) can be used;
                instance =  new Singleton();
            }
        return instance;
    }
private:
    Singleton() = default;
    static Singleton *instance;
    static mutex mtx;

    ~Singleton() = default;     ///Destructor
    Singleton(const Singleton &obj) = delete;   ///Copy Constructor
    Singleton(Singleton &&obj) = delete;        ///Move Constructor
    Singleton& operator=(const Singleton &obj) = delete;    ///Copy Assignment
    Singleton& operator=(Singleton &&obj) = delete;         ///Move Assignment
};
mutex Singleton::mtx;
Singleton* Singleton::instance = nullptr;

int main()
{
    for(int i=0; i<5;i++)
    {
        Singleton *instance = Singleton::getInstance();
        cout<<instance<<endl;
    }
    return 0;
}
