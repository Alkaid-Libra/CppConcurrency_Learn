#include <iostream>
#include <thread>
using namespace std;

void hello() 
{
    cout << "Hello Concurrent world\n";
}

int main()
{
    thread t(hello) ;
    t.join();
    return 0;
}