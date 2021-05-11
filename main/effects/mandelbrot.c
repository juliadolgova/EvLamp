/**
 * Mandelbrot set effect
 */
#include "effects/mandelbrot.h"

#include <lib8tion.h>
#include <math.h>
#include <esp_timer.h>

#define P_SPEED  0

EFFECT_PARAMS(mandelbrot, 1) = {
    DECL_PARAM(P_SPEED, "Speed", 10, 100, 50),
};

#define PALETTE_SIZE 4

static const rgb_t C_BLACK = { 0 };

static const size_t max_iterations = 15;
static const float max_calc = 16;

static const float zoom_factor = 0.0016;
static const float x_offset = 0;
static const float y_offset = 0.1;

static float real, imaginary, zoom;
static float x_min, y_min, dx, dy;

static rgb_t palette[PALETTE_SIZE];

esp_err_t effect_mandelbrot_prepare(framebuffer_t *fb)
{
    for (size_t i = 0; i < PALETTE_SIZE; i++)
        palette[i] = hsv2rgb_rainbow(hsv_from_values(random8(), 255, random8_between(128, 255)));

    return ESP_OK;
}

static void change_palette()
{
    for (size_t i = 0; i < PALETTE_SIZE; i++)
        palette[i] = rgb_blend(
            palette[i],
            hsv2rgb_rainbow(hsv_from_values(random8(), 255, random8_between(128, 255))),
            24
        );
}

static void resize(framebuffer_t *fb)
{
    zoom = 5000 * fabsf(sinf(esp_timer_get_time() / 2000000.0f)) + 200;
    real = -0.94299;
    imaginary = 0.3162;

    x_min = real - 1.0 / zoom / zoom_factor + x_offset;
    y_min = imaginary - 1.0 / zoom / zoom_factor + y_offset;
    float x_max = real + 1.0 / zoom / zoom_factor + x_offset;
    float y_max = imaginary + 1.0 / zoom / zoom_factor + y_offset;

    dx = (x_max - x_min) / (fb->width);
    dy = (y_max - y_min) / (fb->height);
}

esp_err_t effect_mandelbrot_run(framebuffer_t *fb)
{
    CHECK(fb_begin(fb));

//    if (fb->frame_num % 100)
//        change_palette();

    resize(fb);

    float y = y_min;
    for (size_t row = 0; row < fb->height; row++, y += dy)
    {
        float x = x_min;
        for (size_t col = 0; col < fb->width; col++, x += dx)
        {
            float a = x;
            float b = y;
            size_t i = 0;
            while (i < max_iterations)
            {
                float aa = a * a;
                float bb = b * b;
                float len = aa + bb;
                if (len > max_calc)
                    break;
                b = 2 * a * b + y;
                a = aa - bb + x;
                i++;
            }

            rgb_t color = i == max_iterations
                    ? C_BLACK
                    : hsv2rgb_rainbow(hsv_from_values(i * 255 / max_iterations, 255, 255));
                    //: color_from_palette_rgb(palette, PALETTE_SIZE, i * 255 / max_iterations, 255 - i, true);
            fb_set_pixel_rgb(fb, col, row, color);
        }
    }

    fb_blur2d(fb, 64);

    return fb_end(fb);
}
