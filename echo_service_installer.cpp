#include "echo_service_installer.h"

EchoService *EchoServiceInstaller::install(Host *host) {
    EchoService *echo = new EchoService(host, listenPort_);
    ServiceInstaller::install(host, echo);

    return echo;
}