#include "publisher.h"
#include "mqtt_wrapper.h"

Publisher::Publisher(const char* topic) :
    topic(topic)
{
}

void Publisher::send(const char* payload)
{
    auto msg = mqtt::make_message(topic, payload);
    msg->set_qos(1);
    MqttWrapper::get_client().publish(msg);
}
