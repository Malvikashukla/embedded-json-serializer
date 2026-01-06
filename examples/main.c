#include <stdio.h>
#include <string.h>
#include "data_model.h"
#include "json_serializer.h"

int main(void)
{
    GatewayData gateway;
    char json_buffer[1024];

    /* Gateway metadata */
    strcpy(gateway.gateway_id, "gateway_1234");
    strcpy(gateway.date, "1970-01-01");
    strcpy(gateway.device_type, "stromleser");
    gateway.interval_minutes = 15;
    gateway.total_readings = 1;

    /* One device */
    gateway.values.device_count = 1;

    DeviceReading *dev = &gateway.values.readings[0];
    strcpy(dev->media, "water");
    strcpy(dev->meter, "waterstarm");
    strcpy(dev->device_id, "stromleser_50898527");
    strcpy(dev->unit, "m3");

    dev->data_count = 1;

    DataPoint *dp = &dev->data[0];
    strcpy(dp->timestamp, "1970-01-01 00:00");
    strcpy(dp->meter_datetime, "1970-01-01 00:00");
    dp->total_value = 107.752;
    strcpy(dp->status, "OK");

    if (serialize_to_json(&gateway, json_buffer, sizeof(json_buffer)) < 0) {
        printf("JSON serialization failed\n");
        return -1;
    }

    printf("%s\n", json_buffer);
    return 0;
}

