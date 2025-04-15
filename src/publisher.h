#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include "mqtt/client.h"

class Publisher {
    public:
        Publisher(mqtt::client& client, const char* topic);

        void send(const char* payload);

    private:
        mqtt::client& client;
        const char* topic;
};

#endif
