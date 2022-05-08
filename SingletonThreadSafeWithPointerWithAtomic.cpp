#include<iostream>
#include<mutex>
using namespace std;
mutex mtx;

class Singleton
{
public:
	static Singleton*  getInstance()
	{	if(!instance)    ///In Multi-Threaded application more than one thread can access first time simultaneously then instance is null for each thread.
		{
            unique_lock <mutex> lock(mtx);  ///locking for CS to access only one thread.
			if(!instance)                   ///after that instance is not null so after one thread, no one can access this scope.
			{
				instance = new Singleton();
			}
            addRef();
            lock.unlock();
		}

		return instance;
	}

	static void releaseInstance()
	{
		releaseRef();
        if((counter == 0) && (instance != nullptr))
        {
            delete instance;
            instance = nullptr;
        }
	}
private:
	static Singleton* instance;

    static unsigned long int counter;
    static void releaseRef()    {    --counter;   }
    static void addRef()    {    ++counter;   }

	Singleton() = default;
	~Singleton()    {cout<<"Destructor called"<<endl;};


	Singleton(const Singleton &obj)=delete;
	Singleton& operator=(const Singleton &obj)= delete;
	Singleton(Singleton &&obj) =  delete;
	Singleton& operator=(Singleton &&obj) = delete;

};
Singleton* Singleton ::instance = nullptr;
unsigned long int Singleton::counter = 0;
int main()
{
	Singleton *obj1 = Singleton::getInstance();
	Singleton *obj2 = Singleton::getInstance();
	Singleton *obj3 = Singleton::getInstance();
    Singleton::releaseInstance();
    Singleton::releaseInstance();
    Singleton::releaseInstance();       /// Destructor would called only using this call, because here count is 0


	return 0;
}
