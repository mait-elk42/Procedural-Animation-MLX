#include <system.h>

System *data_hook(System *tosave) {
	static System	*saved;
	if (tosave != NULL)
		saved = tosave;
	return saved;
}

int *readpixel(const Texture *t, PointI point) {
	return (&t->buffer[point.y * t->Width + point.x]);
}


void drawcircle(const Texture *texture, int radius, PointI position, int color) {
	// Draw a circle using the equation >>>>>>>> x^2 + y^2 = r^2
	int y = position.y-radius;
	int x = 0;
	while (y < position.y+radius) {
		x = position.x-radius;
		while (x < position.x+radius) {
			int dx = x - position.x;
			int dy = y - position.y;
			if (!(x < 0 || x >= texture->Width || y < 0 || y >= texture->Height))
				if (dx * dx + dy * dy <= radius * radius)
					*readpixel(texture, (PointI){x, y}) = color;
			x++;
		}
		y++;
	}
}

float PointFdistance(PointI p1, PointI p2) {
	(void)p1;
	(void)p2;
	return (sqrt(pow(abs(p2.x - p1.x), 2) + pow(abs(p2.y - p1.y), 2)));
}

void	ProcessTexture(Texture *texture) {
	System *system = data_hook(NULL);
	{
		for (int y = 0; y < texture->Height; y++) {
			for (int x = 0; x < texture->Width; x++) {
				*readpixel(texture, (PointI){x, y}) = 0x000000;
			}
		}
	}
	{
		for (int i = 0; i < LENGTH; i++) {
			int currI = i;
			int targI = i -1;
			if (i == 0)
				targI = 0;
			if (PointFdistance(system->snake[targI].position, system->snake[currI].position) <= (int)system->snake[i].radius)
				;
			else {
					float angle = atan2(system->snake[currI].position.y - system->snake[targI].position.y, system->snake[currI].position.x - system->snake[targI].position.x);

					// Move p to boundary of my circle
					system->snake[currI].position.x = system->snake[targI].position.x + (int)(system->snake[i].radius * cos(angle));
					system->snake[currI].position.y = system->snake[targI].position.y + (int)(system->snake[i].radius * sin(angle));
			}
			// system->snake[currI].position.y += 17.5f; // GRAVITY ?
		}
		//lerp to make the movement smooth..
		system->snake[0].position.x = system->snake[0].targetposition.x + (int)((system->snake[0].position.x - system->snake[0].targetposition.x) * 0.8f);
		system->snake[0].position.y = system->snake[0].targetposition.y + (int)((system->snake[0].position.y - system->snake[0].targetposition.y) * 0.8f);
	}


	for (int i = 0; i < LENGTH; i++)
		drawcircle(texture, system->snake[i].radius, system->snake[i].position, system->snake[i].color);

}