#ifndef MAIN_H
#define MAIN_H
#include <libft.h>
#include <mlx.h>
#include <stdbool.h>

typedef struct {
	void	*MlxPtr;
	int		Win_Width;
	int		Win_Height;
	void	*WinPtr;
}	System;


typedef struct {
	void	*ptr;
	int		*buffer;
	int		Width;
	int		Height;
	int 	bits_per_pixel;
	int 	size_line;
	int 	endian;
}	Texture;


System *data_hook(System *tosave) ;
int *readpixel(const Texture *t, int x, int y) ;
void	ProcessTexture(Texture *texture) ;

#endif