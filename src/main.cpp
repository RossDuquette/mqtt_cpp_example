#include "mqtt_wrapper.h"
#include "publisher.h"
#include "subscriber.h"

void echo(const char* msg)
{
    Publisher pub("echo");
    pub.send(msg);
}

int main()
{
    MqttWrapper::init("example_client");
    Subscriber sub("test", echo);
    while (true) {
        MqttWrapper::spin_once();
    }
    return 0;
}
