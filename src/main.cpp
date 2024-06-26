#include <iostream>


#include <lib/client/client.h>



int main()
{

    auto client = net::Client(8888, "127.0.0.1");

    client.connect();

    return 0;
}