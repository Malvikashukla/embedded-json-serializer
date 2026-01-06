#ifndef DATA_MODEL_H
#define DATA_MODEL_H

#include <stdint.h>

#define MAX_DEVICES        4
#define MAX_DATA_POINTS    4
#define MAX_STR_LEN        32

typedef struct {
    char timestamp[20];      // YYYY-MM-DD HH:MM
    char meter_datetime[20]; // YYYY-MM-DD HH:MM
    float total_value;
    char status[8];          // OK
} DataPoint;

typedef struct {
    char media[MAX_STR_LEN];
    char meter[MAX_STR_LEN];
    char device_id[MAX_STR_LEN];
    char unit[8];

    uint8_t data_count;
    DataPoint data[MAX_DATA_POINTS];
} DeviceReading;

typedef struct {
    uint8_t device_count;
    DeviceReading readings[MAX_DEVICES];
} MeasurementValues;

typedef struct {
    char gateway_id[MAX_STR_LEN];
    char date[11];           // YYYY-MM-DD
    char device_type[MAX_STR_LEN];
    uint16_t interval_minutes;
    uint16_t total_readings;

    MeasurementValues values;
} GatewayData;

#endif /* DATA_MODEL_H */
