#include <iterator>

namespace mini_stl {
template <typename T> class VectorIterator {
public:
  using iterator_category = std::random_access_iterator_tag;
  using value_type = T;
  using pointer = T *;
  using reference = T &;
  using difference_type = std::ptrdiff_t;

  VectorIterator() : ptr_(nullptr) {}
  VectorIterator(pointer p) : ptr_(p) {}

  auto operator*() const -> reference { return *ptr_; }
  auto operator->() const -> pointer { return ptr_; }
  auto operator[](difference_type n) const -> reference { return *(ptr_ + n); }

  auto operator++() -> VectorIterator & {
    ++ptr_;
    return *this;
  }

  auto operator++(int) -> VectorIterator {
    auto tmp = *this;
    ++ptr_;
    return tmp;
  }

  auto operator--() -> VectorIterator & {
    --ptr_;
    return *this;
  }

  auto operator--(int) -> VectorIterator {
    auto tmp = *this;
    --ptr_;
    return tmp;
  }

  auto operator+(difference_type n) const -> VectorIterator {
    return VectorIterator(ptr_ + n);
  }

  auto operator+=(difference_type n) -> VectorIterator & {
    ptr_ += n;
    return *this;
  }

  auto operator-(difference_type n) const -> VectorIterator {
    return VectorIterator(ptr_ - n);
  }

  auto operator-=(difference_type n) -> VectorIterator & {
    ptr_ -= n;
    return *this;
  }

  auto operator==(const VectorIterator &rhs) const -> bool {
    return ptr_ == rhs.ptr_;
  }
  auto operator!=(const VectorIterator &rhs) const -> bool {
    return ptr_ != rhs.ptr_;
  }
  auto operator<(const VectorIterator &rhs) const -> bool {
    return ptr_ < rhs.ptr_;
  }
  auto operator>(const VectorIterator &rhs) const -> bool {
    return ptr_ > rhs.ptr_;
  }
  auto operator<=(const VectorIterator &rhs) const -> bool {
    return ptr_ <= rhs.ptr_;
  }
  auto operator>=(const VectorIterator &rhs) const -> bool {
    return ptr_ >= rhs.ptr_;
  }

private:
  pointer ptr_;
};
} // namespace mini_stl
