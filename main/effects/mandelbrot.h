/**
 * Mandelbrot set effect
 */
#ifndef __EFFECTS_MANDELBROT_H__
#define __EFFECTS_MANDELBROT_H__

#include "effect.h"

extern EFFECT_PARAMS(mandelbrot, 1);

esp_err_t effect_mandelbrot_prepare(framebuffer_t *fb);

esp_err_t effect_mandelbrot_run(framebuffer_t *fb);

#define DESCR_EFFECT_MANDELBROT DECL_EFFECT_FULL(mandelbrot, "Mandelbrot set")

#endif /* __EFFECTS_MANDELBROT_H__ */
