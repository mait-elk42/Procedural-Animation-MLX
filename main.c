#include <system.h>

int main() {
	System system = {
		.MlxPtr = mlx_init(),
		.Win_Height = 700,
		.Win_Width = 700,
		.WinPtr = mlx_new_window(system.MlxPtr, system.Win_Width, system.Win_Height, "Procedural Animation")
	};

	
	Texture img = {
		.ptr = mlx_new_image(system.MlxPtr, system.Win_Width, system.Win_Height),
		.Width = system.Win_Width,
		.Height = system.Win_Height,
		.buffer = (int *)mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.size_line, &img.endian),
	};

	ProcessTexture(&img);
	mlx_clear_window(system.MlxPtr, system.WinPtr);
	mlx_put_image_to_window(system.MlxPtr, system.WinPtr, img.ptr, 0, 0);
	mlx_loop(system.MlxPtr);
}

