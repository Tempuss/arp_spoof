#ifndef ARP_H
#define ARP_H
#include <cstdint>
#include "../lib/libnet/libnet-macros.h"
#include "../lib/libnet/libnet-types.h"
#include "../lib/libnet/libnet-headers.h"


class ARP
{

private:
    struct packet {
        libnet_ethernet_hdr eth_header;
        libnet_arp_hdr arp_header;

        uint8_t send_mac[6];
        uint32_t send_ip;
        uint8_t target_mac[6];
        uint32_t target_ip;
    };

public:
    ARP();
    void setEthHeader();
    void setArpHeader();

    void getEthHeader();
    void getArpHeader();
};

#endif // ARP_H
