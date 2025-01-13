#include <iostream>
#include <thread>

class joining_thread{
    std::thread t;
public:
    joining_thread() noexcept = default;

    template<typename Callable, typename... Args>
    explicit joining_thread(Callable&& func, Args&&...args) :
        t{std::forward<Callable>(func), std::forward<Args>(args)...}
    {}

    explicit joining_thread(std::thread t_) noexcept : t{std::move(t_)} {}

    joining_thread(joining_thread&& other) noexcept : t{std::move(other.t)} {}

    joining_thread& operator=(std::thread&& other) noexcept
    {
        if (t.joinable())
            t.join();

        t = std::move(other);
        return *this;
    }

    ~joining_thread()
    {
        if (t.joinable())
            t.join();
    }

    void swap(joining_thread& other) noexcept
    {
        t.swap(other.t);
    }
    std::thread::id get_id() const noexcept
    {
        return t.get_id();
    }

    bool joinable() const noexcept
    {
        return t.joinable();
    }

    void join() {
        t.join();
    }

    void detach() {
        t.detach();
    }

    std::thread& data() noexcept
    {
        return t;
    }

    const std::thread& data() const noexcept
    {
        return t;
    }

};



int main(int argc,char *argv[])
{
    std::cout << std::this_thread::get_id() << '\n';
    joining_thread thread{[] {
        std::cout << std::this_thread::get_id() << '\n';
    }};

    joining_thread thread2{std::move(thread)};
    
    
}
