
#ifndef SCLYR_H
#define SCLYR_H

#include <wayland-client.h>

struct SCLYR_STATE
{
    struct wl_compositor *WL_COMPOSITOR;
    struct wl_shm *WL_SHARED_MEMORY;
};

#endif