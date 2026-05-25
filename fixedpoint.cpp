#include <cstdint>

class fixed {
    int32_t value; 
public:

    explicit fixed(float f) : value(f * 1000) {}
    
    fixed(int32_t v) : value(v * 1000) {}

    fixed operator+(fixed o) const { return fixed::raw(value + o.value); }
    
    fixed operator-(fixed o) const { return fixed::raw(value - o.value); }
    fixed operator*(fixed o) const { return fixed::raw((value * o.value) / 1000); }
    fixed operator/(fixed o) const { return fixed::raw((value * 1000) / o.value); }

    float toFloat() const { return value / 1000.0f; }
    int32_t toInt() const { return value / 1000; }


    static fixed raw(int32_t v) { fixed f(0); f.value = v; return f; }
};

int main() {
    
    fixed x(3.14f);
    fixed y(2.0f);
    fixed z = x + y; 
    float result = z.toFloat(); 
    
};





