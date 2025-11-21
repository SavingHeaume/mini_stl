#include <iterator>

namespace mini_stl {
template <typename T> class vector_iterator {
public:
  using iterator_category = std::random_access_iterator_tag;
  using value_type = T;
  using pointer = T *;
  using reference = T &;
  using difference_type = std::ptrdiff_t;

  vector_iterator() : ptr_(nullptr) {}
  vector_iterator(pointer p) : ptr_(p) {}

  auto operator*() const -> reference { return *ptr_; }
  auto operator->() const -> pointer { return ptr_; }
  auto operator[](difference_type n) const -> reference { return *(ptr_ + n); }

  auto operator++() -> vector_iterator & {
    ++ptr_;
    return *this;
  }

  auto operator++(int) -> vector_iterator {
    auto tmp = *this;
    ++ptr_;
    return tmp;
  }

  auto operator--() -> vector_iterator & {
    --ptr_;
    return *this;
  }

  auto operator--(int) -> vector_iterator {
    auto tmp = *this;
    --ptr_;
    return tmp;
  }

  auto operator+(difference_type n) const -> vector_iterator {
    return vector_iterator(ptr_ + n);
  }

  auto operator+=(difference_type n) -> vector_iterator & {
    ptr_ += n;
    return *this;
  }

  auto operator-(difference_type n) const -> vector_iterator {
    return vector_iterator(ptr_ - n);
  }

  auto operator-=(difference_type n) -> vector_iterator & {
    ptr_ -= n;
    return *this;
  }

  auto operator==(const vector_iterator &rhs) const -> bool {
    return ptr_ == rhs.ptr_;
  }
  auto operator!=(const vector_iterator &rhs) const -> bool {
    return ptr_ != rhs.ptr_;
  }
  auto operator<(const vector_iterator &rhs) const -> bool {
    return ptr_ < rhs.ptr_;
  }
  auto operator>(const vector_iterator &rhs) const -> bool {
    return ptr_ > rhs.ptr_;
  }
  auto operator<=(const vector_iterator &rhs) const -> bool {
    return ptr_ <= rhs.ptr_;
  }
  auto operator>=(const vector_iterator &rhs) const -> bool {
    return ptr_ >= rhs.ptr_;
  }

private:
  pointer ptr_;
};
} // namespace mini_stl
