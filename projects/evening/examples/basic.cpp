#include <ecosnail/evening.hpp>

#include <iostream>
#include <vector>

namespace ev = ecosnail::evening;

ev::Channel channel;

class Subscriber : ev::Subscriber {
public:
    Subscriber()
    {
        subscribe<int>(
            channel,
            [this] (int value) {
                _values.push_back(value);
            });
    }

    void printValues() const
    {
        for (auto value : _values) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

private:
    std::vector<int> _values;
};

int main()
{
}
