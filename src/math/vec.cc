#include "include/vec.h"

namespace engine {
namespace math {

template <typename T, uint32_t size> T Vec<T, size>::Magnitude() const {
  T help = 0;
  for (int i = 0; i < size; ++i) {
    help += this->data[i] * this->data[i];
  }
  return sqrt(help);
}
template <typename T, uint32_t size>
Vec<T, size> Vec<T, size>::Normalise() const {
  Vec<T, size> result;
  T length = this->Magnitude();
  for (int i = 0; i < size; ++i) {
    result = this->data[i] / length;
  }

  return result;
}
template <typename T, uint32_t size>
T Vec<T, size>::Distance(const Vec<T, size> &other) const {
  T answer = 0;

  for (int i = 0; i < size; ++i) {
    answer += ((this->data[i] - other[i]) * (this->data[i] - other[i]));
  }

  return sqrt(answer);
}
template <typename T, uint32_t size>
T Vec<T, size>::Dot(const Vec<T, size> &other) const {
  T help = 0;
  for (int i = 0; i < size; ++i) {
    help += this->data[i] * other[i];
  }
  return help;
}

template <typename T, uint32_t size>
Vec<T, size> Vec<T, size>::cross(const Vec<T, size> &other) {
  static_assert(size == 3, "Crossproduct is only defined for Vecs of size 3!");

  Vec<T, size> result;
  result[0] = this->data[1] * other[2] - this->data[2] * other[1];
  result[1] = this->data[2] * other[0] - this->data[0] * other[2];
  result[2] = this->data[0] * other[1] - this->data[1] * other[0];
  return result;
}

} // namespace math
} // namespace engine