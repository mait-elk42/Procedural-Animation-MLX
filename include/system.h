#ifndef SYSTEM_H
#define SYSTEM_H
#include <libft.h>
#include <mlx.h>
#include <stdbool.h>
#include <math.h>
#include <macros.h>

#define LENGTH 10


typedef struct {
	int		keycode;
	bool	pressed;
}	Key;

typedef struct {
	float	x;
	float	y;
}	PointF;

typedef struct {
	int	x;
	int	y;
}	PointI;

typedef struct {
	void	*ptr;
	int		*buffer;
	int		Width;
	int		Height;
	int 	bits_per_pixel;
	int 	size_line;
	int 	endian;
}	Texture;

typedef struct {
	PointI	position;
	PointI	targetposition;
	bool	initialized;
	int		color;
	int		radius;
}	Object;

typedef struct {
	void	*MlxPtr;
	int		Win_Width;
	int		Win_Height;
	void	*WinPtr;
	Texture maintexture;
	Object	snake[1024];
	Key		keys[1024];
	bool mousekeypressed;

}	System;

System	*data_hook(System *tosave) ;

int		*readpixel(const Texture *t, PointI point) ;

int		ev_systemloop(System *system) ;
int		ev_keydown(int keycode, System *system) ;
int		ev_keyup(int keycode, System *system) ;
int		ev_mousekeydown(int button, int x, int y, System *system) ;
int		ev_mousekeyup(int button, int x, int y, System *system) ;


void	ProcessTexture(Texture *texture) ;
void	Init_Keys_Recorder(Key *keys) ;
void	RecordNewKey(Key *keys, Key torecord) ;

Key	read_key(int keycode) ;


#endif