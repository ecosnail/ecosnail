#include <ecosnail/tempo.hpp>

#include <iostream>

namespace tempo = ecosnail::tempo;

class System {
public:
    void update(double deltaSeconds)
    {
        _secondsPassed += deltaSeconds;
    }

    void print()
    {
        std::cout << "seconds passed: " << _secondsPassed << "\n";
    }

private:
    double _secondsPassed = 0;
};

int main()
{
    static const auto FPS = 3;

    System system;
    auto timer = tempo::FrameTimer{FPS};
    for (;;) {
        auto framesPassed = timer();
        for (auto i = framesPassed; i > 0; i--) {
            system.update(timer.delta());
        }

        if (framesPassed > 0) {
            system.print();
        }
    }
}
