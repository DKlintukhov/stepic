#include <utility>

template <typename T>
struct SharedPtr
{
    explicit SharedPtr(T *ptr = nullptr) : ptr_(ptr), counter_(0)
    {
        if (ptr_)
            counter_ = new size_t(1);
    }

    SharedPtr(const SharedPtr &other) : ptr_(other.ptr_), counter_(other.counter_)
    {
        if (ptr_)
            ++(*counter_);
    }

    ~SharedPtr()
    {
        if (ptr_ && --(*counter_) == 0)
        {
            delete ptr_;
            delete counter_;
        }
    }

    SharedPtr &operator=(const SharedPtr &other)
    {
        if (this != &other)
            SharedPtr(other).swap(*this);
        return *this;
    }

    T *get() const { return ptr_; }
    T &operator*() const { return *ptr_; }
    T *operator->() const { return ptr_; }

    void reset(T *other = nullptr)
    {
        SharedPtr(other).swap(*this);
    }

private:
    T *ptr_ = nullptr;
    size_t *counter_ = nullptr;

    void swap(SharedPtr &other)
    {
        std::swap(ptr_, other.ptr_);
        std::swap(counter_, other.counter_);
    }
};
