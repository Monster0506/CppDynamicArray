#include <cstddef>
#include <iostream>
#include <utility>

template <typename T>
class Array {
   public:
    Array() : data_(nullptr), capacity_(0), size_(0) {}
    ~Array() {
        for (size_t i = 0; i < size_; i++) data_[i].~T();
        ::operator delete(data_);
    }

    void push_back(const T& value) {
        std::cout << "Pushing back" << std::endl;
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

    void grow() {
        std::cout << "Growing back" << std::endl;
        size_t newCap = capacity_ == 0 ? 2 : capacity_ * 2;

        T* newData = static_cast<T*>(::operator new(newCap * sizeof(T)));
        for (size_t i = 0; i < size_; ++i) {
            new (newData + i) T(std::move(data_[i]));
            data_[i].~T();
        }

        ::operator delete(data_);
        data_ = newData;
        capacity_ = newCap;
    }
};
