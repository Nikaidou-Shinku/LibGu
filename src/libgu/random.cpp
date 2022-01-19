#include "random.hpp"

namespace gu {
    
namespace random {

RandomMachine *RandomMachine::rndInstance = nullptr;

RandomMachine* RandomMachine::get() {
    if (rndInstance == nullptr)
        rndInstance = new RandomMachine;
    return rndInstance;
}

} // end namespace random

} // end namespace gu
