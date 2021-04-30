#ifndef MAIN_SURFACE_H_
#define MAIN_SURFACE_H_

#include "common.h"

esp_err_t surface_init();

esp_err_t surface_prepare_effect(size_t effect);

esp_err_t surface_set_effect(size_t num);

esp_err_t surface_next_effect();

esp_err_t surface_set_brightness(uint8_t val);

esp_err_t surface_set_fps(uint8_t val);

#endif /* MAIN_SURFACE_H_ */
