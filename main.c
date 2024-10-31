#include <system.h>

int main() {
	System system = {
		.MlxPtr = mlx_init(),
		.Win_Height = 1000,
		.Win_Width = 1000,
		.WinPtr = mlx_new_window(system.MlxPtr, system.Win_Width, system.Win_Height, "Procedural Animation"),
		.maintexture = {
			.ptr = mlx_new_image(system.MlxPtr, system.Win_Width, system.Win_Height),
			.Width = system.Win_Width,
			.Height = system.Win_Height,
			.buffer = (int *)mlx_get_data_addr(system.maintexture.ptr, &system.maintexture.bits_per_pixel, &system.maintexture.size_line, &system.maintexture.endian),
		},
		.mousekeypressed = false
	};
	ft_bzero(system.snake, sizeof(system.snake));
	data_hook(&system);
	Init_Keys_Recorder(system.keys);
	for (int i = 0; i < 18; i++) {
		system.snake[i].position = (PointI){system.maintexture.Width/2, system.maintexture.Height/2};
		system.snake[i].targetposition = system.snake[0].position;
	}

	
	mlx_hook(system.WinPtr,  ON_KEYDOWN, 0, ev_keydown, &system);
	mlx_hook(system.WinPtr,  ON_KEYUP, 0, ev_keyup, &system);

	mlx_hook(system.WinPtr,  ON_MOUSEDOWN, 0, ev_mousekeydown, &system);
	mlx_hook(system.WinPtr,  ON_MOUSEUP, 0, ev_mousekeyup, &system);

	mlx_loop_hook(system.MlxPtr, ev_systemloop, &system);

	mlx_loop(system.MlxPtr);
}


