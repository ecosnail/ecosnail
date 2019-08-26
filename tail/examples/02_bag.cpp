#include <ecosnail/tail/bag.hpp>
#include <ecosnail/tail/identifier.hpp>

#include <iostream>

namespace tail = ecosnail::tail;

ECOSNAIL_IDENTIFIER(X, x);
ECOSNAIL_IDENTIFIER(Y, y);
ECOSNAIL_IDENTIFIER(Z, z);

using XYZBag = tail::Bag<int, X, Y, Z>;

int main()
{
    auto printBag = [] (const auto& bag)
    {
        std::cout <<
            "    [0]: " << tail::get<0>(bag) <<
            " [1]: " << tail::get<1>(bag) <<
            " [2]: " << tail::get<2>(bag) << "\n" <<
            "    {x}: " << bag.x <<
            " {y}: " << bag.y <<
            " {z}: " << bag.z << "\n";
    };

    auto bagWithConstructor = XYZBag{1, 2, 3};
    std::cout << "bag with constructor:\n";
    printBag(bagWithConstructor);

    XYZBag manualBag;
    manualBag.x = 10;
    tail::get<1>(manualBag) = 20;
    manualBag.z = tail::get<0>(manualBag);
    std::cout << "manually filled bag:\n";
    printBag(manualBag);
}
