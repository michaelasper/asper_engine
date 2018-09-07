#include <array>
#include <iostream>
#include <sstream>
#include <string>

namespace engine {
namespace math {
template <typename T, uint32_t size> class Vec {

private:
  std::array<T, size> data;

public:
  Vec() : Vec<T, size>(T(0)) {}

  Vec(T value) {
    for (int i = 0; i < size; ++i) {
      data[i] = value;
    }
  }

  Vec(std::array<T, size> data) { this->data = data; }

public:
  inline T &operator[](uint32_t i) { return data[i]; }
  inline T operator[](uint32_t i) const { return data[i]; }

  /* Operators with vectors*/
  inline Vec<T, size> operator+(const Vec<T, size> right) {
    std::array<T, size> result;
    for (int i = 0; i < size; ++i) {
      result[i] = (this->data[i] + right[i]);
    }
    return Vec<T, size>(result);
  }
  inline Vec<T, size> operator-(const Vec<T, size> right) {
    std::array<T, size> result;
    for (int i = 0; i < size; ++i) {
      result[i] = (this->data[i] - right[i]);
    }
    return Vec<T, size>(result);
  }
  inline Vec<T, size> operator*(const Vec<T, size> right) {
    std::array<T, size> result;
    for (int i = 0; i < size; ++i) {
      result[i] = (this->data[i] * right[i]);
    }
    return Vec<T, size>(result);
  }
  inline Vec<T, size> operator/(const Vec<T, size> right) {

    std::array<T, size> result;
    for (int i = 0; i < size; ++i) {
      result[i] = (this->data[i] / right[i]);
    }
    return Vec<T, size>(result);
  }

  /* Operators with vectors*/
  inline Vec<T, size> operator+=(const Vec<T, size> right) {
    for (int i = 0; i < size; ++i) {
      this->data[i] += right[i];
    }
    return *this;
  }
  inline Vec<T, size> operator-=(const Vec<T, size> right) {
    for (int i = 0; i < size; ++i) {
      this->data[i] -= right[i];
    }
    return *this;
  }
  inline Vec<T, size> operator*=(const Vec<T, size> right) {
    for (int i = 0; i < size; ++i) {
      this->data[i] *= right[i];
    }
    return *this;
  }
  inline Vec<T, size> operator/=(const Vec<T, size> right) {

    for (int i = 0; i < size; ++i) {
      this->data[i] /= right[i];
    }
    return *this;
  }

  /* Operators with scalar*/
  inline Vec<T, size> operator+(T scalar) {
    std::array<T, size> result;
    for (int i = 0; i < size; ++i) {
      result[i] = (this->data[i] + scalar);
    }
    return Vec<T, size>(result);
  }
  inline Vec<T, size> operator-(T scalar) {
    std::array<T, size> result;
    for (int i = 0; i < size; ++i) {
      result[i] = (this->data[i] - scalar);
    }
    return Vec<T, size>(result);
  }
  inline Vec<T, size> operator*(T scalar) {

    std::array<T, size> result;
    for (int i = 0; i < size; ++i) {
      result[i] = (this->data[i] * scalar);
    }
    return Vec<T, size>(result);
  }
  inline Vec<T, size> operator/(T scalar) {

    std::array<T, size> result;
    for (int i = 0; i < size; ++i) {
      result[i] = (this->data[i] / scalar);
    }
    return Vec<T, size>(result);
  }
  inline Vec<T, size> operator+=(T scalar) {
    for (int i = 0; i < size; ++i) {
      this->data[i] += scalar;
    }
    return *this;
  }
  inline Vec<T, size> operator-=(T scalar) {
    for (int i = 0; i < size; ++i) {
      this->data[i] -= scalar;
    }
    return *this;
  }
  inline Vec<T, size> operator*=(T scalar) {

    for (int i = 0; i < size; ++i) {
      this->data[i] *= scalar;
    }
    return *this;
  }
  inline Vec<T, size> operator/=(T scalar) {

    for (int i = 0; i < size; ++i) {
      this->data[i] /= scalar;
    }
    return *this;
  }
  inline bool operator==(const Vec<T, size> &other) const {
    for (int i = 0; i < size; ++i) {
      if (this->data[i] != other->data[i])
        return false;
    }

    return true;
  }
  inline bool operator!=(const Vec<T, size> &other) const {
    return !this == other;
  }

  inline bool operator<(const Vec<T, size> &other) const {
    for (int i = 0; i < size; ++i) {
      if (this->data[i] >= other->data[i])
        return false;
    }
    return true;
  }

  inline bool operator<=(const Vec<T, size> &other) const {
    for (int i = 0; i < size; ++i) {
      if (this->data[i] > other->data[i])
        return false;
    }
    return true;
  }

  inline bool operator>(const Vec<T, size> &other) const {
    return !this <= other;
  }

  inline bool operator>=(const Vec<T, size> &other) const {
    return !this < other;
  }

  T Magnitude() const;
  Vec<T, size> Normalise() const;
  T Distance(const Vec<T, size> &other) const;
  T Dot(const Vec<T, size> &other) const;
  Vec<T, size> cross(const Vec<T, size> &other);

  std::string toString() const {
    std::stringstream result;
    for (int i = 0; i < size; ++i) {
      result << this->data[i] << " ";
    }
    return result.str();
  }

  friend std::ostream &operator<<(std::ostream &stream,
                                  const Vec<T, size> &vector) {
    stream << vector.toString();
    return stream;
  }
};

template <typename T> using Vec2 = Vec<T, 2>;
template <typename T> using Vec3 = Vec<T, 3>;
template <typename T> using Vec4 = Vec<T, 4>;
} // namespace math
} // namespace engine