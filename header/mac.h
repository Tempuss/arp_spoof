#ifndef MAC_H
#define MAC_H
#include "cstdint"

class Mac
{
private:
    uint8_t mac_address[6] = {0x00};
public:
    Mac();
    uint8_t *getMacAddress();
    uint8_t *setMacAddrss();
};

#endif // MAC_H
