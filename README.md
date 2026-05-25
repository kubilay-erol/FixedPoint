# Fixed-Point Math for Embedded C++

A lightweight fixed-point arithmetic class for bare-metal embedded systems.

## Why?
`float` arithmetic is slow on MCUs without an FPU (STM32F1, AVR, etc.).
This class stores decimal numbers as integers internally, doing all math
with integer operations, and only converts back to float when needed.

## How it works
Values are scaled by 1000 internally:
- `3.14f` is stored as `3140`
- All math happens on integers
- Call `.toFloat()` at the end to get the result back

## Usage
```cpp
Fixed voltage(3.14f);
Fixed offset(0.5f);
Fixed result = voltage + offset;
float output = result.toFloat(); // 3.640f
```

## Limitations
- 3 decimal places of precision (scale factor 1000)
- Overflow if values get too large (int32_t max is ~2 billion)
