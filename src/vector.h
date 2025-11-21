#include "allocator.h"
#include <cstddef>
#include <utility>

namespace mini_stl {

template <typename T, typename Alloc = mini_stl::Allocator<T>> class Vector {
public:
  using value_type = T;
  using allocator_type = Alloc;
  using difference_type = std::ptrdiff_t;
  using iterator = T *;
  using const_iterator = const T *;
  using reference = T &;
  using const_reference = const T &;
  using pointer = T *;
  using const_pointer = const T *;
  using size_type = size_t;

private:
  allocator_type alloc_;
  pointer data_ = nullptr; // 已分配内存
  size_type size_ = 0;
  size_type cap_ = 0;

public:
  Vector() noexcept = default;

  explicit Vector(size_type n) {}

private:
  auto reserve(size_type new_cap) {
    if (new_cap <= cap_)
      return;

    pointer new_data = alloc_.allocate(new_cap);

    size_type i = 0;
    try {
      for (size_type i = 0; i < size_; ++i) {
        alloc_.construct(new_data + i, std::move_if_noexcept(data_[i]));
      }
    } catch (...) {
      for (size_type j = 0; j < i; ++j) {
        alloc_.destroy(new_data + j);
      }
      alloc_.deallocate(new_data, new_cap);
      throw;
    }

    for (size_type i = 0; i < size_; ++i) {
      alloc_.destroy(data_ + i);
    }

    if (data_) {
      alloc_.deallocate(data_, cap_);
    }
  }
};

} // namespace mini_stl
