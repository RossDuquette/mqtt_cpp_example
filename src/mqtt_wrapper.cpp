#include "mqtt_wrapper.h"

MqttWrapper::MqttWrapper(const char* app_name) :
    mqtt::client("localhost", app_name),
    callbacks()
{
}

void MqttWrapper::register_callback(const char* topic, std::function<void(const char*)> cb)
{
    callbacks[topic] = cb;
}

void MqttWrapper::spin_once()
{
    auto msg = consume_message();
    if (msg) {
          for (auto it = callbacks.begin(); it != callbacks.end(); it++) {
              if (msg->get_topic() == it->first) {
                  it->second(msg->to_string().c_str());
              }
          }
    }
}
