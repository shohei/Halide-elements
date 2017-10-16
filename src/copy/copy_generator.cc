#include <iostream>
#include "Halide.h"

using namespace Halide;

template<typename T>
class Copy : public Halide::Generator<Copy<T>> {
public:
    ImageParam src{type_of<T>(), 2, "src"};
    Param<int32_t> width{"width", 1024};
    Param<int32_t> height{"height", 768};

    Var x, y;

    Func build() {

        Func dst("dst");
        dst(x, y) = src(x, y);
        
        return dst;
    }
};

RegisterGenerator<Copy<uint8_t>> copy_u8{"copy_u8"};
RegisterGenerator<Copy<uint16_t>> copy_u16{"copy_u16"};
