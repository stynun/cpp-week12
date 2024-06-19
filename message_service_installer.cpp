#include "message_service_installer.h"

MessageService *MessageServiceInstaller::install(Host *host) {
    short availport = ServiceInstaller::assignPort(host);
    MessageService *messageService = new MessageService(host, availport, destAddress_, destPort_);
    ServiceInstaller::install(host, messageService);

    return messageService;
}