## bitwise_test_nano

---

### Note

Just a simple program to practice bitwise operation with Arduino


```c++
mask0 {0b00000001};
mask1 {0b00000010};
flag {0b00010110};

// set
flag |= mask0;
00010111

// reset
flag &= ~mask1;
00010101

// flip
flag ^= mask1;
00010111

// flip multiple
flag |= (mask0 | mask1)
00010100

```
---

2022-10-10
