#pragma once

#include <string>

class Raster;
Raster* get_cached_image(const std::string& name);
void clear_image_cache();
