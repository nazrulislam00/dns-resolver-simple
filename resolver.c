#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main() {
    struct hostent *host;
    struct in_addr **addr_list;

    host = gethostbyname("example.com");

    if (host == NULL) {
        printf("DNS lookup failed\n");
        return 1;
    }

    addr_list = (struct in_addr **) host->h_addr_list;

    for (int i = 0; addr_list[i] != NULL; i++) {
        printf("IP address: %s\n", inet_ntoa(*addr_list[i]));
    }

    return 0;
}
