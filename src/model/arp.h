#ifndef ARP_H
#define ARP_H
#include "cstdint"
#include "../../lib/libnet/libnet-types.h"
#include "../../lib/libnet/libnet-macros.h"
#include "../../lib/libnet/libnet-headers.h"

#define MAC_LENTH 6

class ARP
{

private:
    struct packet {
        libnet_ethernet_hdr eth_header;
        libnet_arp_hdr arp_header;

        uint8_t send_mac[MAC_LENTH];
        uint32_t send_ip;
        uint8_t target_mac[MAC_LENTH];
        uint32_t target_ip;
    };
   packet packet;
   uint16_t ether_type = 0x0608;
   uint16_t arp_replay = 0x0100;
   uint8_t broadcast[MAC_LENTH] = {0xff,0xff,0xff,0xff,0xff,0xff};




public:
       ARP();

       void setEthernetHeader(uint8_t sender_mac[MAC_LENTH], uint8_t target_mac[MAC_LENTH]);
       void setArpHeader(uint8_t sender_mac[MAC_LENTH], char *sender_ip, uint8_t target_mac[MAC_LENTH], char *target_ip);
       void setArpReply();



};

#endif // ARP_H
