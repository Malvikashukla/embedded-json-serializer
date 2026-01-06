#include <stdio.h>
#include <string.h>
#include "json_serializer.h"

int serialize_to_json(const GatewayData *data,
                      char *buffer,
                      size_t buffer_size)
{
    size_t offset = 0;
    int written = 0;

    if (!data || !buffer || buffer_size == 0) {
        return -1;
    }

    /* Start JSON array */
    written = snprintf(buffer + offset, buffer_size - offset, "[\n  {\n");
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    /* Gateway metadata */
    written = snprintf(buffer + offset, buffer_size - offset,
        "    \"gatewayId\": \"%s\",\n"
        "    \"date\": \"%s\",\n"
        "    \"deviceType\": \"%s\",\n"
        "    \"interval_minutes\": %u,\n"
        "    \"total_readings\": %u,\n",
        data->gateway_id,
        data->date,
        data->device_type,
        data->interval_minutes,
        data->total_readings
    );
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    /* Values object */
    written = snprintf(buffer + offset, buffer_size - offset,
        "    \"values\": {\n"
        "      \"device_count\": %u,\n"
        "      \"readings\": [\n",
        data->values.device_count
    );
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    /* Device readings */
    for (uint8_t i = 0; i < data->values.device_count; i++) {
        DeviceReading *dev = &data->values.readings[i];

        written = snprintf(buffer + offset, buffer_size - offset,
            "        {\n"
            "          \"media\": \"%s\",\n"
            "          \"meter\": \"%s\",\n"
            "          \"deviceId\": \"%s\",\n"
            "          \"unit\": \"%s\",\n"
            "          \"data\": [\n",
            dev->media,
            dev->meter,
            dev->device_id,
            dev->unit
        );
        if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
        offset += written;

        /* Data points */
        for (uint8_t j = 0; j < dev->data_count; j++) {
            DataPoint *dp = &dev->data[j];

            written = snprintf(buffer + offset, buffer_size - offset,
                "            {\n"
                "              \"timestamp\": \"%s\",\n"
                "              \"meter_datetime\": \"%s\",\n"
                "              \"total_m3\": %.3f,\n"
                "              \"status\": \"%s\"\n"
                "            }%s\n",
                dp->timestamp,
                dp->meter_datetime,
                dp->total_value,
                dp->status,
                (j < dev->data_count - 1) ? "," : ""
            );
            if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
            offset += written;
        }

        written = snprintf(buffer + offset, buffer_size - offset,
            "          ]\n"
            "        }%s\n",
            (i < data->values.device_count - 1) ? "," : ""
        );
        if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
        offset += written;
    }

    /* Close JSON */
    written = snprintf(buffer + offset, buffer_size - offset,
        "      ]\n"
        "    }\n"
        "  }\n"
        "]\n"
    );
    if (written < 0 || (size_t)written >= buffer_size - offset) return -1;
    offset += written;

    return (int)offset;
}


