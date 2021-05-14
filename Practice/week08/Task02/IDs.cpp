#include "IDs.hpp"

unsigned UniqueID::uniqueID = 0;

UniqueID::UniqueID() {
    serialNumb = uniqueID;
    ++uniqueID;
}
