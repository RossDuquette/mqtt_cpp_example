#include "subscriber.h"

Subscriber::Subscriber(MqttWrapper& client,
                       const char* topic,
                       std::function<void(const char*)> callback)
{
    client.register_callback(topic, callback);
    client.subscribe(topic);
}
