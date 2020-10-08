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
      Double check lock
      这个solution也有bug
      compiler 可能会reorder 变量的赋值操作
      instance = new Singleton(); 有可能先 赋值，再调用构造器，
      假设恰好此时Thread B 运行到 Line 31，此时instance!=nullptr,
      那么Thread B会得到一个无效的instance
      * 总体来看还不如低效的 single check

      C#, Java 使用 volatile 关键字来阻止reorder
    -----------------------------------*/
    if (instance == nullptr)    // Check 1
    {
      // 会有多个线程一起执行到这一句， lock 会让这些线程先后执行，因此要再次判断 null
      std::lock_guard<std::mutex> lock(m_);
      if (instance == nullptr)  // Check 2
      {
        instance = new Singleton();
      }
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