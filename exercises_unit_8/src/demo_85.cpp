#include <iostream>     // std::cout
#include <new>          // std::bad_alloc

int main () {
  try
  {
    int* Array= new int[100000000000000];//trying to allocate dynamic memory 
    std::cout << "Tried successfully\n";
  }
  catch (std::bad_alloc& e)
  {
    std::cerr << "bad_alloc caught: " << e.what() << '\n';
  }
  return 0;
}