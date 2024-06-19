#include "router.h"

Router::~Router() {
    routingTable_.clear();
}

void Router::onReceive(Packet *packet) {
    bool done = false;
    for (int i = 0; i < routingTableSize(); i++) {
      RoutingEntry entry = routingTable_[i];
      if (entry.destination == packet->destAddress()) {
        std::cout << "Router #" << id() << ": " << "forwarding packet (from: " << packet->srcAddress().toString() << ", to: " << packet->destAddress().toString() << ", " << packet->dataSize() << " bytes)" << std::endl;
        entry.nextLink->onReceive(this, packet);
        done = true;
        break;
      }
    }
    
    if (!done) {  
      std::cout << "Router #" << id() << ": " << "no route for packet (from: " << packet->srcAddress().toString() << ", to: " << packet->destAddress().toString() << ", " << packet->dataSize() << " bytes)" << std::endl;
    }
  }