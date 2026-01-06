#include <stdio.h>
#include <string.h>
#include "json_serializer.h"

/*
 * Serializes GatewayData into JSON.
 * Returns number of bytes written or -1 on error.
 */
int serialize_to_json(const GatewayData *data,
                      char *buffer,
                      size_t buffer_size)
{
    size_t offset = 0;
    int written = 0;

    if (!data || !buffer || buffer_size == 0) {
        return -1;
    }

    /* Start outer JSON array */
    written = snprintf(buffer + offset, buffer_size - offset, "[\n");
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    /* Start JSON object */
    written = snprintf(buffer + offset, buffer_size - offset, "  {\n");
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    /* Gateway metadata */
    written = snprintf(buffer + offset, buffer_size - offset,
                       "    \"gatewayId\": \"%s\",\n", data->gateway_id);
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    written = snprintf(buffer + offset, buffer_size - offset,
                       "    \"date\": \"%s\",\n", data->date);
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    written = snprintf(buffer + offset, buffer_size - offset,
                       "    \"deviceType\": \"%s\",\n", data->device_type);
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    written = snprintf(buffer + offset, buffer_size - offset,
                       "    \"interval_minutes\": %u,\n",
                       data->interval_minutes);
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    written = snprintf(buffer + offset, buffer_size - offset,
                       "    \"total_readings\": %u,\n",
                       data->total_readings);
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    /* Values object (empty for now) */
    written = snprintf(buffer + offset, buffer_size - offset,
                       "    \"values\": {\n"
                       "    }\n");
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    /* Close object and array */
    written = snprintf(buffer + offset, buffer_size - offset,
                       "  }\n]\n");
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    return (int)offset;
}

