#ifndef FAST16_H
#define FAST16_H

#include <vector>
#include <cstdint>

namespace fast16
{

  using ::std::vector;

  struct fast16_xy
  {
    short x, y;
    fast16_xy(short x_, short y_) : x(x_), y(y_) {}
  };

  typedef uint16_t fast16_px;

  /// plain C++ version of the corner 10
  void fast16_corner_detect_10(const fast16_px *img, int imgWidth, int imgHeight, int widthStep, short barrier, std::vector<fast16_xy> &corners);

  /// corner score 10
  void fast16_corner_score_10(const fast16_px *img, const int img_stride, const std::vector<fast16_xy> &corners, const int threshold, std::vector<int> &scores);

  /// Nonmax Suppression on a 3x3 Window
  void fast16_nonmax_3x3(const std::vector<fast16_xy> &corners, const std::vector<int> &scores, std::vector<int> &nonmax_corners);

  /*
  // It's either a dark-center-bright-background (DARK = true) corner,
  // or a bright-center-on-dark-background (DARK = false) corner.
  // Don't mix them!
  template<bool DARK = true>
  struct fast16_corner
  {
     fast16_corner()
        : x(-1), y(-1), score(-1) {}
     fast16_corner(const fast16_xy& corner, short score_)
        : x(corner.x), y(corner.y), score(score_) {}

     short x, y;
     short score;
  };

  typedef fast16_corner<true> DarkCorner;
  typedef fast16_corner<false> BrightCorner;
  typedef std::vector<DarkCorner> DarkCorners;
  typedef std::vector<BrightCorner> BrightCorners;


  /// Nonmax Suppression on a 5x5 window
  void fast16_nonmax_5x5(const fast16_px* img, int imgWidth, int imgHeight, int widthStep, const std::vector<fast_xy>& corners,
                       short barrier, DarkCorners& darkCorners, BrightCorners& brightCorners);

  /// special corner score. Sum of the absolute radiometric differences between the center pixel and the pixels on the circle.
  short corner_score_test(const fast16_px* img, const int *pointer_dir, short barrier, bool* type);
  */

} // namespace Fast16

#endif
