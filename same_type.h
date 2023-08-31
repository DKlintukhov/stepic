namespace same_type
{
    template <typename T1, typename T2>
    struct SameType
    {
        static const bool value = false;
    };

    template <typename T>
    struct SameType<T, T>
    {
        static const bool value = true;
    };
} // namespace same_type
