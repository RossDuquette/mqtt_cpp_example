#ifndef MQTT_WRAPPER_H_
#define MQTT_WRAPPER_H_

#include "mqtt/client.h"

#include <functional>
#include <map>

class MqttWrapper : public mqtt::client {
    public:
        static void init(const char* app_name);
        static mqtt::client& get_client();
        static void register_callback(const char* topic, std::function<void(const char*)> cb);
        static void spin_once();

    private:
        static MqttWrapper* instance;
        static std::map<const char*, std::function<void(const char*)>> callbacks;

        MqttWrapper(const char* app_name);
};

#endif
