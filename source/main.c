
#include <stdlib.h>

#include <stdint.h>
#include <stdbool.h>

#include <string.h>

#include <stdio.h>

#include "sclyr.h"

#include <errno.h>

#include <unistd.h>

struct wl_display *SCLYR_DISPLAY = NULL;

const int32_t SCLYR_WINDOW_WIDTH = 800;
const int32_t SCLYR_WINDOW_HEIGHT = 600;

struct SCLYR_STATE
{
    struct wl_compositor *WL_COMPOSITOR;
    struct wl_shm *WL_SHARED_MEMORY;
};

static void rl_handle_global(void *data, struct wl_registry *registry, 
    uint32_t name, const char *interface, uint32_t version)
{
    fprintf(stdout, "%d: '%s', version: %d\n", name, interface, version);

    struct SCLYR_STATE *sclyr_handle_state = data;

    if (strcmp(interface, wl_compositor_interface.name) == 0)
    {
        sclyr_handle_state->WL_COMPOSITOR = wl_registry_bind
        (
            registry, name, &wl_compositor_interface, version
        );

        fprintf(stdout, "Successfully bound '%s' to display!\n", interface);
    }

    if (strcmp(interface, wl_shm_interface.name) == 0)
    {
        sclyr_handle_state->WL_SHARED_MEMORY = wl_registry_bind
        (
            registry, name, &wl_shm_interface, version
        );

        fprintf(stdout, "Successfully bound '%s' to display!\n", interface);
    }
}

static void rl_handle_global_remove(void *data, struct wl_registry *registry, 
    uint32_t name)
{
    //
}

static const struct wl_registry_listener SCLYR_REGISTRY_LISTENER = 
{
    .global = rl_handle_global,
    .global_remove = rl_handle_global_remove,
};

int32_t main(int32_t argc, char *argv[])
{
    SCLYR_DISPLAY = wl_display_connect(NULL);

    if (SCLYR_DISPLAY == NULL)
    {
        fprintf(stderr, "Failed to connect to Wayland display!\n");

        return EXIT_FAILURE;
    }

    fprintf(stdout, "Connection established successfully!\n");

    struct SCLYR_STATE sclyr_runtime_state = { 0 };

    struct wl_registry *SCLYR_REGISTRY = wl_display_get_registry(SCLYR_DISPLAY);
    
    wl_registry_add_listener(SCLYR_REGISTRY, &SCLYR_REGISTRY_LISTENER, &sclyr_runtime_state);
    wl_display_roundtrip(SCLYR_DISPLAY);

    wl_display_disconnect(SCLYR_DISPLAY);

    return EXIT_SUCCESS;
}