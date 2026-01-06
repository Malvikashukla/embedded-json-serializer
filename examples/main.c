#include <stdio.h>
#include <string.h>
#include "data_model.h"
#include "json_serializer.h"

int main(void)
{
    GatewayData gateway;
    char json_buffer[512];

    strcpy(gateway.gateway_id, "gateway_1234");
    strcpy(gateway.date, "1970-01-01");
    strcpy(gateway.device_type, "stromleser");
    gateway.interval_minutes = 15;
    gateway.total_readings = 1;

    gateway.values.device_count = 0;

    if (serialize_to_json(&gateway, json_buffer, sizeof(json_buffer)) < 0) {
        printf("JSON serialization failed\n");
        return -1;
    }

    printf("%s\n", json_buffer);
    return 0;
}
