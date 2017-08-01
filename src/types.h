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
	unsigned int v1, t1, n1;
	unsigned int v2, t2, n2;
	unsigned int v3, t3, n3;
};

#endif //TYPES_H
