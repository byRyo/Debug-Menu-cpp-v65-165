#pragma once
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

namespace utils::memory {
    inline uintptr_t get_base(const char *lib) {
        FILE *fp = fopen("/proc/self/maps", "r");
        if (!fp) return 0;
        char line[512];
        uintptr_t base = 0;
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, lib) && strstr(line, "r-xp")) {
                base = strtoull(line, nullptr, 16);
                break;
            }
        }
        fclose(fp);
        return base;
    }

    inline void wait_for_lib(const char *lib) {
        while (!get_base(lib)) usleep(500000);
    }

    inline uintptr_t rebase(const char *lib, uintptr_t offset) {
        return get_base(lib) + offset;
    }
}