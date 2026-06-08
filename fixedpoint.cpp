#include <cstdint>

class fixed {
    int32_t value; 
public:

    explicit fixed(float f) : value(f * 1000) {}
    
    fixed(int32_t v) : value(v * 1000) {}
    

    fixed operator+(fixed o) const { 
        return fixed::raw(value + o.value); 
    }
    
    fixed operator-(fixed o) const { 
        return fixed::raw(value - o.value); 
    }
        
    fixed operator*(fixed o) const { 
        int64_t intermediate = static_cast<int64_t>(value) * o.value; 
        return fixed::raw(static_cast<int32_t>(intermediate / 1000)); 
    }

    fixed operator/(fixed o) const { 
         int64_t intermediate = static_cast<int64_t>(value) * 1000;
        return fixed::raw(static_cast<int32_t>(intermediate / o.value)); 
    }
    
    bool operator<=(fixed o) const {
        return (value <= o.value);
    }
    
    bool operator<(fixed o) const {
        return (value < o.value);
    }
    
    bool operator==(fixed o) const {
        return (value == o.value);
    }
    
    bool operator>(fixed o) const {
        return (value > o.value);
    }
    
    bool operator>=(fixed o) const {
        return (value >= o.value);
    }



    float toFloat() const { 
        return value / 1000.0f; }
        
    int32_t toInt() const { 
        return value / 1000; }


    static fixed raw(int32_t v) { //turns an int32_t into fixed
        fixed f(0); 
        f.value = v;
        return f; }
};


int main() {
    
    fixed x(3.14f);
    fixed y(2.0f);
    fixed z = x + y; 
    float result = z.toFloat(); 
    
};




