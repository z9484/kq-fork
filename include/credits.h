#pragma once

class Raster;

/*! Allocate memory for credits display */
void allocate_credits(void);

/*! Deallocate memory */
void deallocate_credits(void);

/*! Display credits (call in a loop) */
void display_credits(Raster *);
