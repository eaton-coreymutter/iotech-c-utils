//
// Copyright (c) 2019 IOTech
//
// SPDX-License-Identifier: Apache-2.0
//
#ifndef _IOT_CONTAINER_H_
#define _IOT_CONTAINER_H_

/**
 * @file
 * @brief IOTech Container API
 */

#include "iot/component.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef char * (*iot_container_config_load_fn_t) (const char * name, void * from);

typedef struct iot_container_config_t
{
  iot_container_config_load_fn_t load;
  void * from;
} iot_container_config_t;


/**
 * @brief Allocate a named container
 *
 * The function to allocate memory for a container and set it's name
 *
 * @param name  Name of the container, must be unique
 * @return  Pointer to the created container
 */
extern iot_container_t * iot_container_alloc (const char * name);

/**
 * @brief Find a named container
 *
 * The function to find a named container
 *
 * @param name  Name of the container
 * @return  Pointer container if found, NULL otherwise
 */
extern iot_container_t * iot_container_find (const char * name);

/**
 * @brief Initialise the container for a given configuration
 *
 * The function to initialise the container with a configuration provided
 *
 * @param cont  Pointer to the container to initialise
 * @param conf  Pointer to the config structure to load the JSON file from a specified location
 * @return      'true' if the container initialisation is successful
 */
extern bool iot_container_init (iot_container_t * cont, iot_container_config_t * conf);

/**
 *  @brief Start the components within the container
 *
 * The function that invokes start function of the components defined within the container
 *
 * @param cont  Pointer to the container
 * @return      'true' if all the components within the container is started successfully, 'false' otherwise
 */
extern bool iot_container_start (iot_container_t * cont);

/**
 * @brief Stop the components within the container
 *
 * The function that invokes stop function of the components defined within the container
 *
 * @param cont  Pointer to the container
 */
extern void iot_container_stop (iot_container_t * cont);

/**
 * @brief Destroy the container and the associated components
 *
 * The function that invokes free function of the components defined within the container to release the resources
 *
 * @param cont  Pointer to the container
 */
extern void iot_container_free (iot_container_t * cont);

/**
 * @brief Find a named component in a container
 *
 * The function to find a component factory within the container
 *
 * @param cont  Pointer to the container
 * @param name  Name of the component to find
 * @return      Pointer to the component if found within the container, NULL otherwise
 */
extern iot_component_t * iot_container_find_component (iot_container_t * cont, const char * name);

#ifdef __cplusplus
}
#endif
#endif
