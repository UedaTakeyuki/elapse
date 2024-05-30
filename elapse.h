#ifndef ELAPSE_H_
#define ELAPSE_H_

#include <iostream>
#include <chrono>
#include <string_view>
#include <string>

#ifndef NO_PRINT
class ELAPSE {
  public:
    ELAPSE(std::string_view prefix){
      prefix_string = prefix;
      start = std::chrono::steady_clock::now();
    }
    ELAPSE(){
      start = std::chrono::steady_clock::now();
    }
    ~ELAPSE(){
      auto end = std::chrono::steady_clock::now();
      if (!prefix_string.empty()){
        std::cout << prefix_string << " : ";
      }
      std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
      << " ns" << std::endl;
    }
    // copy/move construction and any kind of assignment would lead to the cleanup function getting
    // called twice. We can't have that.
    ELAPSE(ELAPSE &&) = delete;
    ELAPSE(const ELAPSE &) = delete;
    ELAPSE &operator=(const ELAPSE &) = delete;
    ELAPSE &operator=(ELAPSE &&) = delete;
  private:
    std::string prefix_string;
    std::chrono::steady_clock::time_point start;
};
#else
class ELAPSE {
  public:
    ELAPSE(std::string_view prefix){
    }
    ELAPSE(){
    }
    ~ELAPSE(){
    }
    // copy/move construction and any kind of assignment would lead to the cleanup function getting
    // called twice. We can't have that.
    ELAPSE(ELAPSE &&) = delete;
    ELAPSE(const ELAPSE &) = delete;
    ELAPSE &operator=(const ELAPSE &) = delete;
    ELAPSE &operator=(ELAPSE &&) = delete;
  private:
};
#endif

#endif // ELAPSE_H_
