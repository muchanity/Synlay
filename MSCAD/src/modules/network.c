#include "../../include/mscad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>

void get_network_info() {
    int fd;
    struct ifreq ifr;

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);

    if (ioctl(fd, SIOCGIFADDR, &ifr) >= 0) {
        void* tmp = &((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr;
        char addressBuffer[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, tmp, addressBuffer, INET_ADDRSTRLEN);
        
        printf("Network Interface: eth0\n");
        printf("IP Address: %s\n", addressBuffer);
    }

    close(fd);
}