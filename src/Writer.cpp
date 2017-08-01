#include <iostream>
#include <fstream>
#include <vector>
#include <types.h>

constexpr int LINE_BREAK_RATE = 3;

bool write_file( std::ofstream& file, const std::string& prefix, const std::vector<Vertex>& v, const std::vector<Texture>& t, const std::vector<Normal>& n, const std::vector<Face>& f )
{
	//start vertex writing
	file << "const float " << prefix << "_vert[] = {";
	for( auto i = 0u; i < v.size(); ++i )
	{
		if( i%LINE_BREAK_RATE == 0 )
		{
			file << "\n";
		}
		file << std::to_string( v[i].x ) << ", ";
		file << std::to_string( v[i].y ) << ", ";
		file << std::to_string( v[i].z ) << ", ";
	}
	file << "};\n";
	//texture
	file << "const float " << prefix << "_uv[] = {";
	for( auto i = 0u; i < t.size(); ++i )
	{
		if( i%LINE_BREAK_RATE == 0 )
		{
			file << "\n";
		}
		file << std::to_string( t[i].u ) << ", ";
		file << std::to_string( t[i].v ) << ", ";
	}
	file << "};\n";
	//normals
	file << "const float " << prefix << "_norm[] = {";
	for( auto i = 0u; i < n.size(); ++i )
	{
		if( i%LINE_BREAK_RATE == 0 )
		{
			file << "\n";
		}
		file << std::to_string( n[i].x ) << ", ";
		file << std::to_string( n[i].y ) << ", ";
		file << std::to_string( n[i].z ) << ", ";
	}
	file << "};\n";
	//face
	file << "const unsigned int " << prefix << "_norm[] = {";
	for( auto i = 0u; i < f.size(); ++i )
	{
		file << "\n";
		for( unsigned char a = 0; a < 3; ++a )
		{
			file << std::to_string( f[i].v[a] ) << ", ";
			file << std::to_string( f[i].t[a] ) << ", ";
			file << std::to_string( f[i].n[a] ) << ", ";
		}
	}
	file << "};\n";
	file << "const unsigned int " << prefix << "_len = " << f.size()*3 << ";\n";
	//std::cout << f.size() << std::endl;
	return true;
}
