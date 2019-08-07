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
#include "../header/arp.h"
#include "../header/mac.h"

using namespace std;

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
    Mac mac;
    cout<<mac.getMacAddress()<<endl;

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


    cout << argc <<endl;

    return 0;
}
