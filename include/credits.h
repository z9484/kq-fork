#pragma once

class Raster;

/*! Allocate memory for credits display */
void allocate_credits();

/*! Deallocate memory */
void deallocate_credits();

/*! Display credits (call in a loop) */
void display_credits(Raster* double_buffer);
