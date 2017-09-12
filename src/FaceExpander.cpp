#include <vector>
#include <types.h>

std::vector<float> expand_faces( const std::vector<Vertex>& v, const std::vector<Texture>& t, const std::vector<Normal>& n, const std::vector<Face>& f )
{
	std::vector<float> raw_verts;
	for( auto i = 0u; i < f.size(); ++i )
	{
		for( auto x = 0; x < 3; ++x )
		{
			raw_verts.push_back( v[ f[i].v[x] ].x );
			raw_verts.push_back( v[ f[i].v[x] ].y );
			raw_verts.push_back( v[ f[i].v[x] ].z );

			raw_verts.push_back( t[ f[i].t[x] ].u );
			raw_verts.push_back( t[ f[i].t[x] ].v );

			raw_verts.push_back( n[ f[i].n[x] ].x );
			raw_verts.push_back( n[ f[i].n[x] ].y );
			raw_verts.push_back( n[ f[i].n[x] ].z );
		}
	}

	return raw_verts;
}
