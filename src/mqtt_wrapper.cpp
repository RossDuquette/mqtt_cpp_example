#include "mqtt_wrapper.h"

MqttWrapper* MqttWrapper::instance = nullptr;
std::map<const char*, std::function<void(const char*)>> MqttWrapper::callbacks = {};

void MqttWrapper::init(const char* app_name)
{
    if (!instance) {
        instance = new MqttWrapper(app_name);
    }
}

mqtt::client& MqttWrapper::get_client()
{
    return *instance;
}

void MqttWrapper::spin_once()
{
    auto msg = get_client().consume_message();
    if (msg) {
          for (auto it = callbacks.begin(); it != callbacks.end(); it++) {
              if (msg->get_topic() == it->first) {
                  it->second(msg->to_string().c_str());
              }
          }
    }
}

void MqttWrapper::register_callback(const char* topic, std::function<void(const char*)> cb)
{
    callbacks[topic] = cb;
}

MqttWrapper::MqttWrapper(const char* app_name) :
    mqtt::client("localhost", app_name)
{
    connect();
}
