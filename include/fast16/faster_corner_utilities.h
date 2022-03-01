#ifndef FAST16_CORNER_UTILITIES_H
#define FAST16_CORNER_UTILITIES_H

#include <cstddef>

namespace fast16
{

  /// Check if the pointer is aligned to the specified byte granularity
  template <int bytes>
  bool is_aligned(const void *ptr);
  template <>
  inline bool is_aligned<8>(const void *ptr) { return ((reinterpret_cast<std::size_t>(ptr)) & 0x7) == 0; }
  template <>
  inline bool is_aligned<16>(const void *ptr) { return ((reinterpret_cast<std::size_t>(ptr)) & 0xF) == 0; }

  struct Less
  {
    template <class T1, class T2>
    static bool eval(const T1 a, const T2 b)
    {
      return a < b;
    }
    static short prep_t(short pixel_val, short barrier)
    {
      return pixel_val - barrier;
    }
  };

  struct Greater
  {
    template <class T1, class T2>
    static bool eval(const T1 a, const T2 b)
    {
      return a > b;
    }
    static short prep_t(short pixel_val, short barrier)
    {
      return pixel_val + barrier;
    }
  };

} // namespace Fast16

#endif
