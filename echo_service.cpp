#include "echo_service.h"

void EchoService::onReceive(Packet *packet) {
    std::cout << "EchoService: received \"" << packet->dataString() << "\" from " << packet->srcAddress().toString() << ":" << packet->srcPort() << ", send reply with same data" << std::endl;

    Packet *messagePacket = new Packet(packet->destAddress(), packet->srcAddress(), packet->destPort(), packet->srcPort(), packet->data());
    host_->send(messagePacket);   
}