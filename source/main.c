
#include <stdlib.h>

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>

#include <wayland-client.h>

int32_t main(int32_t argc, int8_t *argv[])
{
    struct wl_display *SCLYR_DISPLAY = wl_display_connect(NULL);

    if (!SCLYR_DISPLAY) 
    {
        fprintf(stderr, "Failed to connect to Wayland display!\n");

        return EXIT_FAILURE;
    }

    fprintf(stdout, "Connection established successfully!\n");

    wl_display_disconnect(SCLYR_DISPLAY);

    return EXIT_SUCCESS;
}