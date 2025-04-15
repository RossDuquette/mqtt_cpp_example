#include "mqtt/client.h"

#include <vector>

int main()
{
    mqtt::client client("localhost", "example_client");
    client.connect();

    const std::vector<std::string> TOPICS = {
        "test",
    };
    client.subscribe(TOPICS);

    while (true) {
        auto rx_msg = client.consume_message();
        if (rx_msg && rx_msg->get_topic() == "test") {
            const char* topic = "echo";
            auto tx_msg = mqtt::make_message(topic, rx_msg->to_string());
            tx_msg->set_qos(1);
            client.publish(tx_msg);
        }
    }
    return 0;
}
