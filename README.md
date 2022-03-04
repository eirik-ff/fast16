# FAST16: FAST Corner Detector for 16-bit images

This repository is a subset of the [`uzh-rpg/fast_neon`](https://github.com/uzh-rpg/fast_neon) repository used in [`uzh-rpg/rpg_svo_pro_open`](https://github.com/uzh-rpg/rpg_svo_pro_open). The original repository contains features such as SSE vectorization and ARM NEON vectorization. For simplicity, this repository removes all vectorization implementations.

This repository is meant to be used only for a 16-bit implementation of SVO, so all features not used there are removed. 

The conversion to 16-bit was simply to redefine `fast_byte` to be `uint16_t` instead of `uint8_t` (`unsigned char`). Since all calculations are done using pointer arithmetic, when the pointer type changes all calculations are automatically done on the full 16-bit image. The other changes are only name changes to distinguish it from the original.

