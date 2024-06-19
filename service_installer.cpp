#include "service_installer.h"

void ServiceInstaller::install(Host *host, Service *service) {
    host->services_.push_back(service);
}

short ServiceInstaller::assignPort(Host *host) {
    short availPort = 1000;

    bool done = false;
    while (!done) {
        done = true;
        for (int i = 0; i < host->servicesSize(); i++) {
            if (host->services_[i]->port_ == availPort) {
                availPort++;
                done = false;
                break;
            }
        }  
    }
    
    return availPort;
}