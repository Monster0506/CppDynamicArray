template <typename T>
class Array {
   public:
    Array();
    ~Array();

    void push_back(const T& value);
    size_t size() const { return size_; }
    T& operator[](size_t i) { return data_[i]; }

   private:
    size_t size_;
    size_t capacity_;
    T* data_;
};
