#include <iostream>
#include <algorithm>
#include <iterator>
#include <lambda/lambda.hpp>

int main() {
    typedef std::istream_iterator<int> in;
    std::for_each(in(std::cin), in(), std::cout << (_1 * 3) << " ");
    return 0;
}
