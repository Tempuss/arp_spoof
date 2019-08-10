#include "arp.h"
#include "cstring"
#include <arpa/inet.h>

ARP::ARP()
{

}


/**
 * @brief ARP::setEthernetHeader
 * @detail set Ethernet Header
 * @param send_mac
 * @param target_mac
 */
void ARP::setEthernetHeader(uint8_t send_mac[MAC_LENTH], uint8_t target_mac[MAC_LENTH])
{
    //Set Target MAC
    memcpy(packet.eth_header.ether_dhost, target_mac, MAC_LENTH);
    memcpy(packet.eth_header.ether_shost, send_mac, MAC_LENTH);
    packet.eth_header.ether_type = ether_type;

}

/**
 * @brief ARP::setArpReply
 * @detail Set ARP Reply Opcod
 */
void ARP::setArpReply()
{
    packet.arp_header.ar_op = arp_replay;
}

/**
 * @brief ARP::setArpHeader
 * @detail set Arp Header Info
 * @param send_mac
 * @param send_ip
 * @param target_mac
 * @param target_ip
 */
void ARP::setArpHeader(uint8_t send_mac[MAC_LENTH], char *send_ip, uint8_t target_mac[MAC_LENTH], char *target_ip)
{
    memcpy(packet.send_mac, send_mac, MAC_LENTH);
    packet.send_ip = inet_addr(send_ip);
    memcpy(packet.target_mac, target_mac, MAC_LENTH);
    packet.target_ip = inet_addr(target_ip);

}

void setSenderMacAddress(uint8_t *mac);
void setSenderIp(char *sender_ip);
void setTargetMacAddress(uint8_t *mac);
void setTargetIp(char *target_ip);

