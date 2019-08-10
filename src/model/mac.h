#ifndef MAC_H
#define MAC_H
#include "cstdint"

class Mac
{
private:
    uint8_t mac_address[6] = {0x00};
    char *interface = {};

public:
    Mac(char *interface);
    uint8_t *getMacAddress();
    void *setMacAddrss();

    void setInterface(char *interface);
    //void getInterface();
};

#endif // MAC_H
