#include <iostream>
#include <mutex>

using namespace std;

class Singleton
{
  static atomic<Singleton*> m_instance;
  int data;
  static std::mutex m_;

  // delete copy and move constructors and assign operators
  Singleton(Singleton const&) = delete;             // Copy construct
  Singleton(Singleton&&) = delete;                  // Move construct
  Singleton& operator=(Singleton const&) = delete;  // Copy assign
  Singleton& operator=(Singleton &&) = delete;      // Move assign


public:
  static Singleton *getInstance()
  {
    /*-----------------------------------
    C++ 11 Solution
     -----------------------------------*/
    Singleton* tmp = m_instance.load(std::memory_order_relaxed);

    // 获取内存fence
    std::atomic_thread_fence(std::memory_order_acquire);

    if (tmp == nullptr)  
    {
      std::lock_guard<std::mutex> lock(m_);
      tmp = m_instance.load(std::memory_order_relaxed);
      if (tmp == nullptr)  
      {
        tmp = new Singleton();   // 此时不会出现reorder
        // release memory fence
        std::atomic_thread_fence(std::memory_order_release);  
        m_instance.store(tmp,std::memory_order_relaxed);
      }
    }
    return tmp;
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

std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_;

int main()
{
  Singleton *s = s->getInstance();
  cout << s->getData() << endl;
  s->setData(100);
  cout << s->getData() << endl;
  return 0;
}