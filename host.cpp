#include "host.h"
#include <iostream>
#include <ctime>

void Host::initialize() {}

void Host::send(Packet *packet) {
    std::cout << "Host #" << id() << ": " << "sending packet (from: " << packet->srcAddress().toString() << ", to: " << packet->destAddress().toString() << ", " << packet->dataSize() << " bytes)" << std::endl;

    srand(unsigned(time(NULL)));
    int index = rand() % int(links_.size());

    links_[index]->onReceive(this, packet);
}

void Host::onReceive(Packet *packet) {
    Service *service;
    bool done = false;
    for (int i = 0; i < servicesSize(); i++) {
        Service *s = services_[i];
        if (s->port() == packet->destPort()) {
            service = s;
            std::cout << "Host #" << id() << ": received packet, destination port: " << service->port() << std::endl;
            done = true;
            break;  
        }
    }

    if (done) {
        service->onReceive(packet);
    }
    else {
        std::cout << "Host #" << id() << ": no service for packet (from: " << packet->srcAddress().toString() << ", to: " << packet->destAddress().toString() << ", " << packet->dataSize() << " bytes)" << std::endl;
    }
}
