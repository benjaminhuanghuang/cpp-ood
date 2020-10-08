#include <iostream>

#include "mystr.h"

using namespace std;
void message(const char *s)
{
  puts(s);
  fflush(stdout);
}

int main()
{
  MyString hello = "Hello, World!";
  message(hello.c_str());
}