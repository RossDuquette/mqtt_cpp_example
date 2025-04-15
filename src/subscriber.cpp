#include "mqtt_wrapper.h"
#include "subscriber.h"

Subscriber::Subscriber(const char* topic,
                       std::function<void(const char*)> callback)
{
    MqttWrapper::register_callback(topic, callback);
    MqttWrapper::get_client().subscribe(topic);
}
