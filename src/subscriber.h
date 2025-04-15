#ifndef SUBSCRIBER_H_
#define SUBSCRIBER_H_

#include "mqtt_wrapper.h"

#include <functional>

class Subscriber {
    public:
        Subscriber(MqttWrapper& client,
                   const char* topic,
                   std::function<void(const char*)> callback);
};

#endif
