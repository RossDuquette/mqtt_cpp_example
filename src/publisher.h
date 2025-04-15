#ifndef PUBLISHER_H_
#define PUBLISHER_H_

class Publisher {
    public:
        Publisher(const char* topic);

        void send(const char* payload);

    private:
        const char* topic;
};

#endif
