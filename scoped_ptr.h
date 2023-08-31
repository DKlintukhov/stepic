
template <typename T>
struct ScopedPtr
{
    explicit ScopedPtr(T *ptr = nullptr)
    {
        ptr_ = ptr;
    }
    ~ScopedPtr()
    {
        delete ptr_;
    }
    T *get() const
    {
        return ptr_;
    }
    T *release()
    {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }
    void reset(T *ptr = nullptr)
    {
        delete ptr_;
        ptr_ = ptr;
    }
    T &operator*() const
    {
        return *ptr_;
    }
    T *operator->() const
    {
        return ptr_;
    }

    ScopedPtr(const ScopedPtr &) = delete;
    ScopedPtr &operator=(const ScopedPtr &) = delete;

private:
    T *ptr_;
};
