#include "mqtt_wrapper.h"
#include "publisher.h"
#include "subscriber.h"

static MqttWrapper client("example_client");

void echo(const char* msg)
{
    Publisher pub(client, "echo");
    pub.send(msg);
}

int main()
{
    client.connect();
    Subscriber sub(client, "test", echo);
    while (true) {
        client.spin_once();
    }
    return 0;
}
