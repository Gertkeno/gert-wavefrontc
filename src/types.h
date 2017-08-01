#ifndef TYPES_H
#define TYPES_H

struct Vertex
{
	float x, y, z;
};

struct Texture
{
	float u, v;
};

struct Normal
{
	float x, y, z;
};

struct Face
{
	unsigned int v[3], t[3], n[3];
};

#endif //TYPES_H
