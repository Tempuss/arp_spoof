#include <iostream>
#include <stdlib.h>
#include <arpa/inet.h>
#include <cstdint>
#include <string.h>
#include <pcap.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <sstream>
#include <sys/types.h>
#include <ifaddrs.h>
#include "../header/define.h"
#include "../lib/libnet/libnet-macros.h"
#include "../lib/libnet/libnet-types.h"
#include "../lib/libnet/libnet-headers.h"
#include "./model/arp.h"
#include "./model/mac.h"

using namespace std;

/**
 * @brief getIpAddress
 * @details Get My Network Interface's IP
 * @param interface
 * @return
 */
char* getIpAddress(char *interface)
{
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;

    getifaddrs (&ifap);
    for (ifa = ifap; ifa; ifa = ifa->ifa_next) {

        if (strcmp(ifa->ifa_name, interface) == 0)
        {
           if (ifa->ifa_addr->sa_family==AF_INET) {
                sa = (struct sockaddr_in *) ifa->ifa_addr;
                inet_ntoa(sa->sin_addr);
                //printf("Interface: %s\tAddress: %s\n", ifa->ifa_name, addr);
                freeifaddrs(ifap);
                return inet_ntoa(sa->sin_addr);
           }
        }
    }

    freeifaddrs(ifap);

}
int main(int argc, char **argv)
{
    //Parameter Count Check
    if (argc < 2 || argc %2 != 0)
    {
        cout << "Invalid Parameters" <<endl;
        return 0;
    }

    char *interface = argv[1];
    char *sender_ip[] = {};
    char *target_ip[] = {};
    char errbuf[PCAP_ERRBUF_SIZE];
    char *my_ip = getIpAddress(interface);
    Mac mac(interface);
    //mac.getMacAddress();


    //Push IP Info
    for(int i=2;i<argc;i++)
    {
        if (i%2==0)
        {
            sender_ip[(i/2)-1] = argv[i];
        }
        else
        {
            target_ip[(i%2)-1] = argv[i];
        }
    }

    /*
    for (int i = 0; i<(argc-2)/2; i++)
    {
        cout << sender_ip[i] << std::endl;
    }

    for (int i = 0; i<(argc-2)/2; i++)
    {
        cout << target_ip[i] << std::endl;
    }
    */


    return 0;
}
