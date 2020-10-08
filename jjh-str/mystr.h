
#ifndef MY_STRING_H
#define MY_STRING_H

#include <typeinfo>
#include <memory>
#include <iostream>

class MyString
{
private:
  char *_data;
  size_t _len;
  void _init_data(const char *s)
  {
    _data = new char[_len + 1];
    memcpy(_data, s, _len);
    _data[_len] = '\0';
  }

public:
  //default ctor
  MyString() : _data(NULL), _len(0) {}

  //ctor
  MyString(const char *p) : _len(strlen(p))
  {
    _init_data(p);
  }

  // copy ctor
  MyString(const MyString &str) : _len(str._len)
  {
    std::cout << "Copy Constructor is called! source: " << str._data << " [" << (void *)(str._data) << ']' << std::endl;
    _init_data(str._data); //COPY
  }

  //move ctor, with "noexcept"
  MyString(MyString &&str) noexcept : _data(str._data), _len(str._len)
  {
    std::cout << "Move Constructor is called! source: " << str._data << " [" << (void *)(str._data) << ']' << std::endl;
    str._len = 0;
    str._data = NULL; //避免 delete (in dtor)
  }

  //copy assignment
  MyString &operator=(const MyString &str)
  {
    std::cout << "Copy Assignment is called! source: " << str._data << " [" << (void *)(str._data) << ']' << std::endl;
    if (this != &str)
    {
      if (_data)
        delete _data;
      _len = str._len;
      _init_data(str._data); //COPY!
    }
    else
    {
      std::cout << "Self Assignment, Nothing to do." << std::endl;
    }
    return *this;
  }

  //move assignment
  MyString &operator=(MyString &&str) noexcept
  { //注意 noexcept
    std::cout << "Move Assignment is called! source: " << str._data << " [" << (void *)(str._data) << ']' << std::endl;
    if (this != &str)
    {
      if (_data)
        delete _data;
      _len = str._len;
      _data = str._data; //MOVE!
      str._len = 0;
      str._data = NULL; //避免 delete (in dtor)
    }
    return *this;
  }

  //dtor
  virtual ~MyString()
  { //文檔說需 noexcept 但本處無. destructor is noexcept by default. Johan Lundberg Mar 18 '13 at 12:12
    std::cout << "Destructor is called! "
         << "source: ";
    if (_data)
      std::cout << _data;
    std::cout << " [" << (void *)(_data) << ']' << std::endl;

    if (_data)
    {
      delete _data;
    }
  }

  const char * c_str() const {
    return _data;
  }
};

#endif