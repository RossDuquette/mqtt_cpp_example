#ifndef MQTT_WRAPPER_H_
#define MQTT_WRAPPER_H_

#include "mqtt/client.h"

#include <functional>
#include <map>

class MqttWrapper : public mqtt::client {
    public:
        MqttWrapper(const char* app_name);

        void register_callback(const char* topic, std::function<void(const char*)> cb);
        void spin_once();

    private:
        std::map<const char*, std::function<void(const char*)>> callbacks;
};

#endif
