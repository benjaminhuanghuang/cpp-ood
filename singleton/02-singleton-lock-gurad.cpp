#include <iostream>
#include <mutex>

using namespace std;

class Singleton
{
  static Singleton *instance;
  int data;
  static std::mutex m_;

  // Private constructor so that no objects can be created.
  Singleton()
  {
    data = 0;
  }
  // delete copy and move constructors and assign operators
  Singleton(Singleton const&) = delete;             // Copy construct
  Singleton(Singleton&&) = delete;                  // Move construct
  Singleton& operator=(Singleton const&) = delete;  // Copy assign
  Singleton& operator=(Singleton &&) = delete;      // Move assign

public:
  static Singleton *getInstance()
  {
    /*-----------------------------------
      A lock guard is an object that manages a mutex object by keeping it always locked.
      using a local lock_guard to lock mtx guarantees unlocking on destruction

      对read操作来说成本过高，
    -----------------------------------*/
    std::lock_guard<std::mutex> lock(m_);
    if (!instance)
    {
      instance = new Singleton();
    }
    return instance;
  }

  int getData()
  {
    return this->data;
  }

  void setData(int data)
  {
    this->data = data;
  }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;

int main()
{
  Singleton *s = s->getInstance();
  cout << s->getData() << endl;
  s->setData(100);
  cout << s->getData() << endl;
  return 0;
}