#include "ALI/api.hpp"

namespace ali {
    
float avg(std::vector<float> values) {
    float total = 0;
    for(float val : values) {
        total += val;
    }
    return total / values.size();
}

}