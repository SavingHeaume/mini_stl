
#include <iterator>
namespace mini_stl {
template <typename Iterator> class IteratorTraits {
  using iterator_category = typename Iterator::iterator_category;
  using value_type = typename Iterator::value_type;
  using difference_type = typename Iterator::difference_type;
  using pointer = typename Iterator::pointer;
  using reference = typename Iterator::reference;
};

template <typename T> class IteratorTraits<T *> {
  using iterator_category = std::random_access_iterator_tag;
  using value_type = T;
  using pointer = T *;
  using reference = T &;
  using difference_type = std::ptrdiff_t;
};
} // namespace mini_stl
