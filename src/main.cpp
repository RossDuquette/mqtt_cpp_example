#include "mqtt/client.h"

int main()
{
    mqtt::client client("localhost", "example_client");
    client.connect();
    const char* topic = "test";
    const char* payload = "hello world";
    const int qos = 1;
    auto msg = mqtt::make_message(topic, payload);
    msg->set_qos(qos);
    client.publish(msg);
    return 0;
}
