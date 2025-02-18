#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    GFATAL("A test message: %f", 3.14f);
    GERROR("A test message: %f", 3.14f);
    GWARN("A test message: %f", 3.14f);
    GINFO("A test message: %f", 3.14f);
    GDEBUG("A test message: %f", 3.14f);
    GTRACE("A test message: %f", 3.14f);

    GASSERT(1 == 0);

    return 0;
}