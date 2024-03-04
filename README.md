# elapse: A class to measure the elapsed time of a function or block of C++, header file only classes.

## How to use

Include **elapse.h** and just **declare a variable of type Elapse** at the beginning of the function or block you want to measure elapsed time, **that it!** Fx:
```
#include "elapse.h"

int kerokero(){
  auto prefix = std::string(__FILE__) + ":" + std::to_string(__LINE__) + ":" +__func__;

  // Show elapsed time of this FUNC with prefix message.
  ELAPSE elapse(prefix);

  return 2;
}

void kerokerokero(){
  // Show elapsed time of this FUNC with prefix message.
  ELAPSE elapse(__func__);
}

int main(){
  // Show elapsed time of MAIN with prefix message.
  ELAPSE elapse(__func__);
  {
    // Show elapsed time of this BLOCK without prefix message.
    ELAPSE elapse;
    kerokero();
//    std::cout << kerokero() << std::endl;
  }
  kerokerokero();
  {
    // Show elapsed time of this BLOCK without prefix message.
    ELAPSE elapse;
    kerokerokero();
  }
  {
    // Show elapsed time of this BLOCK without prefix message.
    ELAPSE elapse;
    kerokero();
  }
  return 0;
}
```

The output is as follows:

```
./a.out 
test.cpp:4:kerokero : 83 ns
49669 ns
kerokerokero : 76 ns
kerokerokero : 61 ns
2634 ns
test.cpp:4:kerokero : 54 ns
3634 ns
main : 66058 ns
```

## Just question
In my environment (Apple Clang version 11.0.0), why does the execution of the **first block** take about **10 times longer** than the execution of subsequent blocks?

## for other language
**golang** version is available at https://github.com/UedaTakeyuki/erapse.
