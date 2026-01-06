#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H

#include <stddef.h>
#include "data_model.h"

/*
 * Serializes GatewayData into a JSON string.
 *
 * Parameters:
 *  - data: Pointer to input data structure
 *  - buffer: Output buffer provided by the caller
 *  - buffer_size: Size of the output buffer
 *
 * Returns:
 *  - Number of bytes written on success
 *  - -1 on error (invalid input or buffer too small)
 */
int serialize_to_json(const GatewayData *data,
                      char *buffer,
                      size_t buffer_size);

#endif /* JSON_SERIALIZER_H */
