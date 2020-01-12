#include <pthread.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <iostream>
static void* myFunc3(void* context);
// void* pFunc(void*) {
//   std::cout << "thread" << std::endl;
//   return 0;
// }
// static void* myFunc(void* context);
class Test;
static void* myFunc(void* context) {
  std::cout << "thread" << std::endl;
  Test* data = static_cast<Test*>(context);
  // data->mTid = syscall(SYS_gettid);
  return nullptr;
}

class Test {
 public:
  Test();
  //  {
  //   int ret = pthread_create(&mPthreadT, NULL, , nullptr);
  //   std::cout << "ret=" << ret;
  // }

  bool join() {
    if (0 == pthread_join(mPthreadT, NULL)) {
      return true;
    }
    return false;
  }

  bool detach() {
    if (0 == pthread_detach(mPthreadT)) {
      return true;
    }

    return false;
  }

  // static friend void* pFunc(void* context) {
  //   std::cout << "thread" << std::endl;
  //   Test *data = static_cast<Test *>(context);
  //   data->mTid = syscall(SYS_gettid) return nullptr;
  // }

  // friend void* myFunc(void* context);

  // friend void* myFunc3(void* context);
  static void* mytest1(void* context);

 private:
  pthread_t mPthreadT;
  pid_t *mTid;
};

Test::Test() {
  auto tid = new pid_t;
  mTid = tid;
  int ret = pthread_create(&mPthreadT, NULL, Test::mytest1, tid);
  std::cout << "ret=" << ret;
}

void* Test::mytest1(void* context) {
  Test* data = static_cast<Test*>(context);
  data->mTid = 2;
  return nullptr;
}

// void* Test::myFunc3(void* context) {
//   Test* data = static_cast<Test*>(context);
//   data->mTid = syscall(SYS_gettid);
// }

int main(int argc, char* argv[]) {
  std::cout << "Hello Easy C++ project!" << std::endl;
  Test t;
  // pthread_t thread1;
  // int ret = pthread_create(&thread1, NULL, &Test::pFunc, nullptr);
}