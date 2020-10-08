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

public:
  static Singleton *getInstance()
  {
    /*-----------------------------------

    */
    if (!instance)
    {
      std::lock_guard<std::mutex> lock(m_);
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