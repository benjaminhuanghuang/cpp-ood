#include <iostream>

using namespace std;

class Singleton
{
private:
  // Private constructor so that no objects can be created.
  // Complaer will create these tow conctructor if class does have it.
  Singleton() : data(0){};

  // delete copy and move constructors and assign operators
  Singleton(Singleton const&) = delete;             // Copy construct
  Singleton(Singleton&&) = delete;                  // Move construct
  Singleton& operator=(Singleton const&) = delete;  // Copy assign
  Singleton& operator=(Singleton &&) = delete;      // Move assign

private:
  static Singleton *m_instance;
  int data;

public:
  static Singleton *getInstance()
  {
    if (m_instance == nullptr)
    {
      m_instance = new Singleton();
    }
    return m_instance;
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
Singleton *Singleton::m_instance = nullptr;

int main()
{
  Singleton *s = s->getInstance();
  cout << s->getData() << endl;
  s->setData(100);
  cout << s->getData() << endl;
  return 0;
}