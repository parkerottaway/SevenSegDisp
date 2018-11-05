#ifndef BCD_HPP
#define BCD_HPP

class BCD{
  public:
    unsigned char segments; // {DP, g, f, e, d, c, b, a}
    BCD();
    void dispInt(int n);
};
#endif
