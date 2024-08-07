#include <stdio.h>
#include "emu.h"
#include "cart.h"
#include "cpu.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/* 
1. Cartridge Rom
2. CPU
3. Address Bus
4. PPU
5. Timer
*/

static emu_context ctx;
emu_context *emu_get_context() {
    return &ctx;
}
void delay(u32 ms) {
    SDL_Delay(ms);
}

int emu_run(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: emu <rom_file>\n");
        return -1;
    }
    if(!cart_load(argv[1])) {
        printf("Failed to load ROM FILE: %s\n", argv[1]);
        return -2;
    }
    printf("Loaded ROM FILE: %s\n", argv[1]);
    SDL_Init(SDL_INIT_VIDEO);
    printf("SDL INIT\n");
    TTF_Init();
    printf("TTF INIT\n");

    cpu_init();
    ctx.running = true;
    ctx.paused = false;
    ctx.ticks = 0;

    while (ctx.running) {
        if (ctx.paused) {
            delay(10);
            continue;
        }
        if(!cpu_step()) {
            printf("CPU step failed and stopped\n");
            return -3;
        }
        ctx.ticks++;
    }
    return 0;
}
