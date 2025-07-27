
#include <stdlib.h>

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>

#include "sclyr.h"

int32_t main(int32_t argc, char *argv[])
{
    struct wl_display *SCLYR_DISPLAY = wl_display_connect(NULL);

    if (SCLYR_DISPLAY == NULL)
    {
        fprintf(stderr, "Failed to connect to Wayland display!\n");

        return EXIT_FAILURE;
    }

    wl_display_disconnect(SCLYR_DISPLAY);

    return EXIT_SUCCESS;
}