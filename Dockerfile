FROM ubuntu:22.04

RUN apt update \
    && apt install -y build-essential g++ make cmake libssl-dev \
    && apt clean \
    && rm -rf /var/cache/apt/archives /var/lib/apt/lists

COPY paho.mqtt.cpp/ /paho_mqtt/
RUN cd /paho_mqtt/ \
    && cmake -Bbuild -H. -DPAHO_WITH_MQTT_C=ON -DPAHO_BUILD_EXAMPLES=ON \
    && cmake --build build/ --target install \
    && ldconfig
