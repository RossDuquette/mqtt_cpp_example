#ifndef SUBSCRIBER_H_
#define SUBSCRIBER_H_

#include <functional>

class Subscriber {
    public:
        Subscriber(const char* topic,
                   std::function<void(const char*)> callback);
};

#endif
