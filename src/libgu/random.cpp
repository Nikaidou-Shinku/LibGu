#include "random.hpp"

namespace gu {
    
namespace details {

RandomMachine *RandomMachine::rndInstance = nullptr;

RandomMachine* RandomMachine::get() {
    if (rndInstance == nullptr)
        rndInstance = new RandomMachine;
    return rndInstance;
}

} // end namespace details

} // end namespace gu
