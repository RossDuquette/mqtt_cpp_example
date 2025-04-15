#include "publisher.h"

Publisher::Publisher(mqtt::client& client, const char* topic) :
    client(client),
    topic(topic)
{
}

void Publisher::send(const char* payload)
{
    auto msg = mqtt::make_message(topic, payload);
    msg->set_qos(1);
    client.publish(msg);
}
