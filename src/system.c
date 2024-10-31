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
	{
		for (int y = 0; y < texture->Height; y++) {
			for (int x = 0; x < texture->Width; x++) {
				*readpixel(texture, (PointI){x, y}) = 0x000000;
			}
		}
	}
	int radius = 50;
	// PointI center = {texture->Width/2, texture->Height/2};

	// if (PointFdistance(data_hook(NULL)->ppp, center) <= (int)radius)
	// 	;
	// else {
	// 	;
		
	// 	float angle = atan2(data_hook(NULL)->ppp.y - center.y, data_hook(NULL)->ppp.x - center.x);

	// 	// Move p to boundary
	// 	data_hook(NULL)->ppp.x = center.x + (int)(radius * cos(angle));
	// 	data_hook(NULL)->ppp.y = center.y + (int)(radius * sin(angle));
	// }
	// if (data_hook(NULL)->ppp.x != data_hook(NULL)->targetppp.x && data_hook(NULL)->ppp.y != data_hook(NULL)->targetppp.y)
	{
		// if (PointFdistance(data_hook(NULL)->snake[0].position, data_hook(NULL)->snake[1].position) <= (int)radius)
		// 	;
		// else {
		// 		float angle = atan2(data_hook(NULL)->snake[1].position.y - data_hook(NULL)->snake[0].position.y, data_hook(NULL)->snake[1].position.x - data_hook(NULL)->snake[0].position.x);

		// 		// Move p to boundary
		// 		data_hook(NULL)->snake[1].position.x = data_hook(NULL)->snake[0].position.x + (int)(radius * cos(angle));
		// 		data_hook(NULL)->snake[1].position.y = data_hook(NULL)->snake[0].position.y + (int)(radius * sin(angle));
		// }
		// if (PointFdistance(data_hook(NULL)->snake[1].position, data_hook(NULL)->snake[2].position) <= (int)radius)
		// 	;
		// else {
		// 		float angle = atan2(data_hook(NULL)->snake[2].position.y - data_hook(NULL)->snake[1].position.y, data_hook(NULL)->snake[2].position.x - data_hook(NULL)->snake[1].position.x);

		// 		// Move p to boundary
		// 		data_hook(NULL)->snake[2].position.x = data_hook(NULL)->snake[1].position.x + (int)(radius * cos(angle));
		// 		data_hook(NULL)->snake[2].position.y = data_hook(NULL)->snake[1].position.y + (int)(radius * sin(angle));
		// }
		for (int i = 0; i < 18; i++) {
			int currI = i;
			int targI = i -1;
			if (i == 0)
				targI = 0;
			if (PointFdistance(data_hook(NULL)->snake[targI].position, data_hook(NULL)->snake[currI].position) <= (int)radius)
				;
			else {
					float angle = atan2(data_hook(NULL)->snake[currI].position.y - data_hook(NULL)->snake[targI].position.y, data_hook(NULL)->snake[currI].position.x - data_hook(NULL)->snake[targI].position.x);

					// Move p to boundary
					data_hook(NULL)->snake[currI].position.x = data_hook(NULL)->snake[targI].position.x + (int)(radius * cos(angle));
					data_hook(NULL)->snake[currI].position.y = data_hook(NULL)->snake[targI].position.y + (int)(radius * sin(angle));
			}
		}
		// if (PointFdistance(data_hook(NULL)->ppp3, data_hook(NULL)->ppp4) <= (int)radius)
		// 	;
		// else {
		// 		float angle = atan2(data_hook(NULL)->ppp4.y - data_hook(NULL)->ppp3.y, data_hook(NULL)->ppp4.x - data_hook(NULL)->ppp3.x);

		// 		// Move p to boundary
		// 		data_hook(NULL)->ppp4.x = data_hook(NULL)->ppp3.x + (int)(radius * cos(angle));
		// 		data_hook(NULL)->ppp4.y = data_hook(NULL)->ppp3.y + (int)(radius * sin(angle));
		// }
		// if (PointFdistance(data_hook(NULL)->ppp4, data_hook(NULL)->ppp5) <= (int)radius)
		// 	;
		// else {
		// 		float angle = atan2(data_hook(NULL)->ppp5.y - data_hook(NULL)->ppp4.y, data_hook(NULL)->ppp5.x - data_hook(NULL)->ppp4.x);

		// 		// Move p to boundary
		// 		data_hook(NULL)->ppp5.x = data_hook(NULL)->ppp4.x + (int)(radius * cos(angle));
		// 		data_hook(NULL)->ppp5.y = data_hook(NULL)->ppp4.y + (int)(radius * sin(angle));
		// }
		// if (PointFdistance(data_hook(NULL)->ppp5, data_hook(NULL)->ppp6) <= (int)radius)
		// 	;
		// else {
		// 		float angle = atan2(data_hook(NULL)->ppp6.y - data_hook(NULL)->ppp5.y, data_hook(NULL)->ppp6.x - data_hook(NULL)->ppp5.x);

		// 		// Move p to boundary
		// 		data_hook(NULL)->ppp6.x = data_hook(NULL)->ppp5.x + (int)(radius * cos(angle));
		// 		data_hook(NULL)->ppp6.y = data_hook(NULL)->ppp5.y + (int)(radius * sin(angle));
		// }
		data_hook(NULL)->snake[0].position.x = data_hook(NULL)->snake[0].targetposition.x + (int)((data_hook(NULL)->snake[0].position.x - data_hook(NULL)->snake[0].targetposition.x) * 0.8f);
		data_hook(NULL)->snake[0].position.y = data_hook(NULL)->snake[0].targetposition.y + (int)((data_hook(NULL)->snake[0].position.y - data_hook(NULL)->snake[0].targetposition.y) * 0.8f);
		// data_hook(NULL)->ppp = data_hook(NULL)->targetppp;
	}


	for (int i = 0; i < 18; i++) {
		drawcircle(texture, radius, data_hook(NULL)->snake[i].position, 0xffff00);
	}
	// drawcircle(texture, radius, data_hook(NULL)->ppp4, 0x00ff00);
	// drawcircle(texture, radius, data_hook(NULL)->ppp5, 0x0ffff0);
	// drawcircle(texture, radius, data_hook(NULL)->ppp6, 0x0fff00);

}