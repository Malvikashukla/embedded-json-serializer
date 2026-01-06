#include <stdio.h>
#include <string.h>
#include "data_model.h"

int serialize_to_json(const GatewayData *data,
                      char *buffer,
                      size_t buffer_size)
{
    size_t offset = 0;
    int written = 0;

    if (!data || !buffer || buffer_size == 0) {
        return -1;
    }

    /* JSON serialization will be implemented step-by-step */
      written = snprintf(buffer + offset, buffer_size - offset, "  {\n");
    if (written < 0 || (size_t)written >= buffer_size - offset) {
        return -1;
          written = snprintf(buffer + offset, buffer_size - offset,
                       "    \"gatewayId\": \"%s\",\n", data->gateway_id);
    if (written < 0 || (size_t)written >= buffer_size - offset) {
        return -1;
    }
    offset += written;

    }
    offset += written;

    if (written < 0 || (size_t)written >= buffer_size - offset) {
        return -1;
    }
    offset += written;

    /* Closing bracket for now */
    written = snprintf(buffer + offset, buffer_size - offset, "]\n");
    if (written < 0 || (size_t)written >= buffer_size - offset) {
        return -1;
          written = snprintf(buffer + offset, buffer_size - offset,
                       "    \"date\": \"%s\",\n", data->date);
    if (written < 0 || (size_t)written >= buffer_size - offset) {
        return -1;
    }
    offset += written;

    }
    offset += written;

    return (int)offset;
}
