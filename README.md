# lib CJSON

## Description
CJSON is a C library that provides utility functions for working with JSON data. It contains various functions to facilitate parsing and accessing JSON objects.

## Installation
To use CJSON in your C project, follow these steps:

1. Download the `CJSON.h` and `CJSON.a` files.
2. Place them in your project directory.
3. Include `CJSON.h` in your C source files where you intend to use the library functions.
``` C
#include "CJSON.h"
```
5. Compile your project, linking `CJSON.a` with your source files.

## Usage
### Functions
**JSON_get_from_key**

``` c
char *JSON_get_from_key(char *JSON, const char *key);
    Description: Retrieves the value of a JSON object based on the specified key.
    Parameters:
        json_string: The JSON string to parse.
        key: The key of the value to retrieve.
    Returns:
        A dynamically allocated string containing the value associated with the key, or NULL if the key is not found.
```

**JSON_get_from_keys**

```c
char *JSON_get_from_keys(char *JSON, int count, [KEYS...]);
    Description: Retrieves the value of a nested JSON object based on multiple layers of keys.
    Parameters:
        JSON: The JSON string to parse.
        count: The number of keys in the keys array.
        KEY... : layer of keys needed to retrieve the value
    Returns:
        A dynamically allocated string containing the value associated with the specified keys, or NULL if the keys are not found.
```

**get_file_content**
```c
char *get_file_content(char *file_path);
    Description : returns an allocated char * of the content of a file.
    Parameters :
        file_path : path of the file the content will retrieve
    Returns :
        A dinamically allocated string containing the value associated with the specified keys, or NULL if it encounters an error.
```
