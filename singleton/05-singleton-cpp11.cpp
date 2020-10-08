#include <iostream>
#include <mutex>

using namespace std;
/*

The C++11 standards guarantees that the initialization of function scope 
objects are initialized in a synchronized manner.

This can be used to implement a thread-safe singleton with lazy initialization.

https://riptutorial.com/cplusplus/example/9075/lazy-initialization
*/
class Singleton {
 public:
  static Singleton& getInstance() {
    // Since it's a static variable, if the class has already been created,
    // it won't be created again.
    // And it **is** thread-safe in C++11.
    static Singleton myInstance;

    // Return a reference to our instance.
    return myInstance;
  }

  // delete copy and move constructors and assign operators
  Singleton(Singleton const&) = delete;             // Copy construct
  Singleton(Singleton&&) = delete;                  // Move construct
  Singleton& operator=(Singleton const&) = delete;  // Copy assign
  Singleton& operator=(Singleton &&) = delete;      // Move assign

  // Any other public methods.
  int getData()
  {
    return this->data;
  }

  void setData(int data)
  {
    this->data = data;
  }
 protected:
  Singleton():data(0) {
    // Constructor code goes here.
  }

  ~Singleton() {
    // Destructor code goes here.
  }

 private:
  int data;
};

int main()
{
  Singleton& s = Singleton::getInstance();
  cout << s.getData() << endl;
  s.setData(100);
  cout << s.getData() << endl;
  return 0;
}