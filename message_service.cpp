#include "message_service.h"

void MessageService::send(std::string message) {
    Packet *messagePacket = new Packet(host_->address(), destAddress_, port_, destPort_, message);
    host_->send(messagePacket);
}

void MessageService::onReceive(Packet *packet) {
    std::cout << "MesaageService: received \"" << packet->dataString() << "\" from " << packet->srcAddress().toString() << ":" << packet->srcPort() << std::endl;
}
