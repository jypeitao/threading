// #include <string>
// class Thread {
//  public:
//   using Runnable = std::function<void()>;

//   Thread(const Thread &thread) = delete;
//   Thread &operator=(const Thread &thread) = delete;

//   explicit Thread(const Runnable &runnable,
//                   const std::string &name = std::string());
//   ~Thread();

//   int join();

//   const std::string &name() const { return name_; }

//  private:
//   std::string name_;  // 线程名字
// };