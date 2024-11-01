#include <system.h>

int main() {
	System system = {
		.MlxPtr = mlx_init(),
		.Win_Height = 1300,
		.Win_Width = 1300,
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
	struct {
		int	color;
		int	radius;
	} snake[LENGTH] = {
		{0xff0000,100},
		{0xfff000,90},
		{0xffff00,80},
		{0xfffff0,70},
		{0xffffff,60},
		{0xff5fff,50},
		{0xff1111,45},
		{0xff5555,40},
		{0xff0000,30},
		{0xff0000,25},
	};
	for (int i = 0; i < LENGTH; i++) {
		system.snake[i].position = (PointI){system.maintexture.Width/2, system.maintexture.Height/2};
		system.snake[i].targetposition = system.snake[0].position;
		system.snake[i].color = snake[i].color;
		system.snake[i].radius = snake[i].radius;
	}

	
	mlx_hook(system.WinPtr,  ON_KEYDOWN, 0, ev_keydown, &system);
	mlx_hook(system.WinPtr,  ON_KEYUP, 0, ev_keyup, &system);

	mlx_hook(system.WinPtr,  ON_MOUSEDOWN, 0, ev_mousekeydown, &system);
	mlx_hook(system.WinPtr,  ON_MOUSEUP, 0, ev_mousekeyup, &system);

	mlx_loop_hook(system.MlxPtr, ev_systemloop, &system);

	mlx_loop(system.MlxPtr);
}


