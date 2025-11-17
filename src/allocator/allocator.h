#include <cstddef>
#include <new>

template <typename T> class allocator {
public:
  using value_type = T;
  using pointer = T *;
  using size_type = size_t;

  allocator() noexcept {}
  ~allocator() {}

  pointer allocate(size_type n) {
    return static_cast<pointer>(::operator new(n * sizeof(T)));
  }

  void deallocate(pointer p, size_type n = 0) { ::operator delete(p); }

  void construct(pointer p, const T &value) { new (p) T(value); }

  void destroy(pointer p) { p->~T(); }

  template <typename U> struct rebind {
    using other = allocator<U>;
  };
};
