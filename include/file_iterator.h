/**
 * @file
 * @version 0.1
 *
 * @copyright Copyright 2022 Chris Morgan <chmorgan@gmail.com>
 *
 *      Licensed under the Apache License, Version 2.0 (the "License");
 *      you may not use this file except in compliance with the License.
 *      You may obtain a copy of the License at
 *
 *               http://www.apache.org/licenses/LICENSE-2.0
 *
 *      Unless required by applicable law or agreed to in writing, software
 *      distributed under the License is distributed on an "AS IS" BASIS,
 *      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *      See the License for the specific language governing permissions and
 *      limitations under the License.
 */

#pragma once

#include <stddef.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct  {
    size_t count;
    size_t index;
    char **list;
    const char *directory_path;
} file_iterator_instance_t;

/**
 * @brief Initialize the iterator
 *
 * @param base_path Folder containing files file(s)
 * @return
 *    - ESP_OK: Success
 *    - Others: Fail
 */
file_iterator_instance_t* file_iterator_new(const char *base_path);

/**
 * @brief Delete the iterator instance
 *
 * @param i the instance pointer
 */
void file_iterator_delete(file_iterator_instance_t *i);

/**
 * @brief Move to next song
 *
 * @return
 *    - ESP_OK: Success
 *    - Others: Fail
 */
esp_err_t file_iterator_next(file_iterator_instance_t* i);

/**
 * @brief Move to previous song
 *
 * @return
 *    - ESP_OK: Success
 *    - Others: Fail
 */
esp_err_t file_iterator_prev(file_iterator_instance_t* i);

/**
 * @brief Get the number of items in the playlist
 *
 * @return size_t The number of items in the playlist
 */
size_t file_iterator_get_count(file_iterator_instance_t* i);

/**
 * @brief Get the index of the selected
 *
 * @return Index of audio being played
 */
size_t file_iterator_get_index(file_iterator_instance_t* i);

/**
 * @brief Set the index if the index is valid otherwise set the index to zero
 *
 * @param index
 */
void file_iterator_set_index(file_iterator_instance_t* i, size_t index);

/**
 * @brief Get file name of given index
 *
 * @param index Index of audio file
 * @return Name of audio file with given index. NULL if not exist.
 */
const char *file_iterator_get_name_from_index(file_iterator_instance_t* i, size_t index);

/**
 * @brief
 *
 * @param path - pointer to a buffer of length 'path_len'
 * @return the number of characters stored into path OR the number that would have
 *         been stored had there been enough space, or 0 if the index isn't valid.
 */
int file_iterator_get_full_path_from_index(file_iterator_instance_t* i, size_t index, char* path, size_t path_len);

#ifdef __cplusplus
}
#endif
