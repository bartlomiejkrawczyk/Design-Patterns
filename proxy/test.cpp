#include <iostream>

#include "copy_on_write_proxy.h"
#include "lazy_copy.h"
#include "virtual_proxy.h"

int main() {
    VirtualProxy virtualProxy;

    virtualProxy.operation();

    CopyOnWriteProxy* proxy = new CopyOnWriteProxy(1);

    CopyOnWriteProxy copy1 = *proxy;
    CopyOnWriteProxy copy2 = *proxy;

    copy1.set(2);

    std::cout << proxy->get() << std::endl;
    std::cout << copy1.get() << std::endl;
    delete proxy;
    std::cout << copy2.get() << "\n" << std::endl;

    std::cout << "line: " << __LINE__ << std::endl;
    LazyFoo x(1);
    std::cout << "line: " << __LINE__ << std::endl;
    LazyFoo y(x);
    std::cout << "line: " << __LINE__ << std::endl;
    y.get();
    std::cout << "line: " << __LINE__ << std::endl;
    x.set(2);
    std::cout << "line: " << __LINE__ << std::endl;
    y.set(3);
    std::cout << "line: " << __LINE__ << std::endl;
    return 0;

    return 0;
}