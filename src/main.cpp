#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include "unistd.h"

// std::mutex m;

// std::once_flag flag;
// int n = 1;

// struct X {
//     X(int v) {
//         ::n += v;
//         std::cout << n << std::endl;
//     }
// };


// void f()
// {
//     // // std::lock_guard<std::mutex> lc{m};
//     // m.lock();
//     // std::cout << std::this_thread::get_id() << '\n';

//     // usleep(1000000);
//     // std::cout << "skipppp" << std::endl;
//     // m.unlock();

//     // std::call_once(flag, [] {
//     //     ++n;
//     //     std::cout << "di " << n << "ci diaoyong\n";
//     //     // throw std::runtime_error("error");
//     // });

//     X* p = new X{1};
//     delete p;
// }

// int main()
// {
//     // std::vector<std::thread> threads;
//     // for (std::size_t i = 0; i < 10; ++i)
//     //     threads.emplace_back(f);

//     // for (auto& thread : threads)
//     //     thread.join();
    
//     // // return 0;


//     // try
//     // {
//         f();
//     // }
//     // catch(const std::exception& e)
//     // {
//     //     std::cerr << e.what() << '\n';
//     //     // throw;
//     // }

//     // try{
//         // f();
//     // }
//     // catch (std::exception& e) {
//     //     std::cerr << e.what() << '\n';}
    

// }



// ----------------------------------------------------------------------
#include <iostream>
#include <thread>
#include <future> // 引入 future 头文件

int task(int n) {
    std::cout << "异步任务 ID: " << std::this_thread::get_id() << '\n';
    return n * n;
}

int main() {
    std::future<int> future = std::async(task, 10);
    std::cout << "main: " << std::this_thread::get_id() << '\n';
    std::cout << std::boolalpha << future.valid() << '\n'; // true
    std::cout << future.get() << '\n';
    std::cout << std::boolalpha << future.valid() << '\n'; // false
}

