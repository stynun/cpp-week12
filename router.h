#ifndef ROUTER_H
#define ROUTER_H

#include "node.h"
#include <iostream>

struct RoutingEntry {
public:
  Address destination;
  Link *nextLink;
};

class Router : public Node {
protected:
  std::vector<RoutingEntry> routingTable_;

  void onReceive(Packet *packet) override;
  
public:
  ~Router();
  int routingTableSize() { return routingTable_.size(); }
};

#endif