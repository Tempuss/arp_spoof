#include "mac.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template<typename Out>
void split(string &s, char delim, Out result)
{
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim))
        *(result++) = item;
}


vector<string> split(string &s, char delim)
{
    vector<string> elem;
    split(s, delim, back_inserter(elem));

    return elem;
}

Mac::Mac(char *interface)
{
    setInterface(interface);
}

/**
 * @brief Mac::getMacAddress
 * @detail Get Specefic Interface's MAC Address
 * @return uint8_t* mac_address
 */
uint8_t* Mac::getMacAddress()
{
    return Mac::mac_address;
}

void Mac::setInterface(char *interface)
{
    Mac::interface = interface;

    string path = "/sys/class/net/"+(string)interface+"/address";
    string data = "";

    ifstream openFile(path.data());
    if( openFile.is_open() ){
        string line;
        while(getline(openFile, line)){
            data = line;
        }
        openFile.close();
    }

    vector<string> x = split(data, ':');
    for(int i=0;i<6;i++)
    {
       mac_address[i] =(uint8_t) stoi(x[i], 0, 16);
    }
}

