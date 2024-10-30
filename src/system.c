#include <system.h>

System *data_hook(System *tosave) {
	static System	*saved;
	if (tosave != NULL)
		saved = tosave;
	return saved;
}

int *readpixel(const Texture *t, int x, int y) {
	return (&t->buffer[y * t->Width + x]);
}


// void drawcircle(int radius, int x, int y) {

// }

void	ProcessTexture(Texture *texture) {
	// for (int y = 0; y < texture->Width; y++) {
	// 	int x = texture->Width / 2;
	// 	// for (int x = 0; x < texture->Height; x++) {
	// 		*readpixel(texture, x,y) = 0xff0000;
	// 	// }
	// }
	
	int center_x = 100;
	int center_y = 100;
	int radius = 50;
	int color = 0x00FF00; // Green color

	// Draw a circle using the equation x^2 + y^2 = r^2
	for (int y = 0; y < texture->Width ; y++) {
		int x = 0;
		for (int x = 0; x < texture->Height; x++) {
			int dx = x - center_x;
			int dy = y - center_y;
			if (dx * dx + dy * dy <= radius * radius) {
				texture->buffer[y * texture->Width + x] = color;
			}
		}
	}
}