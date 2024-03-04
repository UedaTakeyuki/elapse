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