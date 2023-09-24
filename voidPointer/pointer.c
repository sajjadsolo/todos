#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    INTEGER,
    FLOAT,
    CHARACTER,
    BOOLEAN,
    UNKNOWN
} DataType;

typedef union {
    int intValue;
    float floatValue;
    char charValue;
    bool boolValue;
} DataValue;

typedef struct {
    DataType type;
    DataValue value;
} Data;

bool isInteger(const char* input) {
    char* endPtr;
    strtol(input, &endPtr, 10);
    return (*endPtr == '\0');
}

bool isFloat(const char* input) {
    char* endPtr;
    strtof(input, &endPtr);
    return (*endPtr == '\0');
}

bool isCharacter(const char* input) {
    return (input[0] != '\0' && input[1] == '\0');
}

bool isBoolean(const char* input) {
    return (strcmp(input, "true") == 0 || strcmp(input, "false") == 0);
}

void determineDataType(Data* data, const char* input) {
    if (isInteger(input)) {
        data->type = INTEGER;
        data->value.intValue = atoi(input);
    } else if (isFloat(input)) {
        data->type = FLOAT;
        data->value.floatValue = atof(input);
    } else if (isCharacter(input)) {
        data->type = CHARACTER;
        data->value.charValue = input[0];
    } else if (isBoolean(input)) {
        data->type = BOOLEAN;
        data->value.boolValue = (strcmp(input, "true") == 0);
    } else {
        data->type = UNKNOWN;
    }
}

void printDataInfo(const Data* data) {
    switch (data->type) {
        case INTEGER:
            printf("Data type: Integer\n");
            printf("Value: %d\n", data->value.intValue);
            break;
        case FLOAT:
            printf("Data type: Float\n");
            printf("Value: %f\n", data->value.floatValue);
            break;
        case CHARACTER:
            printf("Data type: Character\n");
            printf("Value: %c\n", data->value.charValue);
            break;
        case BOOLEAN:
            printf("Data type: Boolean\n");
            printf("Value: %s\n", (data->value.boolValue ? "true" : "false"));
            break;
        case UNKNOWN:
            printf("Unable to determine the data type of the input.\n");
            break;
    }
}

int main() {
    char input[100];

    printf("Enter a value: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline character

    Data data;
    determineDataType(&data, input);
    printDataInfo(&data);

    return 0;
}
