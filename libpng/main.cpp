#include <cstdio>
#include <iostream>
#include <memory>

#include <png.h>

/*
 * Details png api documentation can be found in
 * http://refspecs.linuxbase.org/LSB_3.1.0/LSB-Desktop-generic/LSB-Desktop-generic/libpng12man.html
 */
int main(int argc, char** argv) {
    std::cout << "LibPNG Demo" << std::endl;

    // Initialize write machinery, this includes a pointer to the png write context
    // and a pointer to the image information
    png_structp png_ptr = nullptr;
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);

    png_infop png_info_ptr = nullptr;
    png_info_ptr = png_create_info_struct(png_ptr);


    // Open a file for binary writing
    FILE* fp = nullptr;
    fp = fopen("./image.png", "wb");

    // Initialize IO
    png_init_io(png_ptr, fp);

    // Populate info data structure
    // Write header (8 bit colour depth)
    const std::size_t width = 800;
    const std::size_t height = 600;
    png_set_IHDR(png_ptr, png_info_ptr, width, height,
		 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
		 PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
    // Actually write the header
    png_write_info(png_ptr, png_info_ptr);

    // Allocate memory for 3 bytes per pixel. We write the output one
    // row at a time
    auto row = std::make_unique<png_byte[]>(3 * width);
    for (auto i = 0U ; i < height ; ++i) {
	for (auto j = 0U ; j < width ; ++j) {
	    row[j * 3 + 0] = 255;
	    row[j * 3 + 1] = 255 * (j / (2 * static_cast<float>(width)));
	    row[j * 3 + 2] = 255 * (j / static_cast<float>(width));
	}
	png_write_row(png_ptr, row.get());
    }

    // Write the footer (if necessary) and flush
    png_write_end(png_ptr, png_info_ptr);
    png_write_flush(png_ptr);

    // Cleanup
    // See: http://www.ludism.org/~rwhe/LSB/png/libpng-png-free-data-1.html
    png_free_data(png_ptr, png_info_ptr, PNG_FREE_ALL, -1);
    // See: http://refspecs.linuxbase.org/LSB_3.1.0/LSB-Desktop-generic/LSB-Desktop-generic/libpng12.png.destroy.write.struct.1.html
    png_destroy_write_struct(&png_ptr, &png_info_ptr);
}
