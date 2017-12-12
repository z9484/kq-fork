#pragma once

#include <allegro.h>

void display_console(uint32_t, uint32_t);
void do_console_command(const char*);
void init_console();
void run_console();
void scroll_console(const char*);
