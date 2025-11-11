template <typename T>
class Array {
   public:
    Array() : data_(nullptr), capacity_(0), size_(0) {}
    ~Array() {
        for (size_t i = 0; i < size_; i++) data_[i].~T();
        ::operator delete(data_);
    }

    void push_back(const T& value) {
        if (size_ == capacity_) grow();
        new (data_ + size_) T(value);
        ++size_;
    }
    size_t size() const { return size_; }
    T& operator[](size_t i) { return data_[i]; }

   private:
    size_t size_;
    size_t capacity_;
    T* data_;

    void grow();
};
