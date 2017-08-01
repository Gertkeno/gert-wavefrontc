#include <string>
#include <types.h>
#include <iostream>

Vertex parse_vertex( const std::string& line )
{
	Vertex out;
	size_t firstMark = line.find( ' ', 0 ) + 1;
	size_t secondMark = line.find( ' ', firstMark ) + 1;
	size_t thirdMark = line.find( ' ', secondMark ) + 1;
	out.x = std::stof( line.substr( firstMark, std::string::npos ) );
	out.y = std::stof( line.substr( secondMark, std::string::npos ) );
	out.z = std::stof( line.substr( thirdMark, std::string::npos ) );
	//std::cout << out.x << ", " << out.y << ", " << out.z << std::endl;
	return out;
}

Texture parse_texture( const std::string& line )
{
	Texture out;
	size_t firstMark = line.find( ' ', 0 ) + 1;
	size_t secondMark = line.find( ' ', firstMark ) + 1;
	out.u = std::stof( line.substr( firstMark, std::string::npos ) );
	out.v = std::stof( line.substr( secondMark, std::string::npos ) );
	//std::cout << out.u << ", " << out.v << std::endl;
	return out;
}

Normal parse_normal( const std::string& line )
{
	Normal out;
	size_t firstMark = line.find( ' ', 0 ) + 1;
	size_t secondMark = line.find( ' ', firstMark ) + 1;
	size_t thirdMark = line.find( ' ', secondMark ) + 1;
	out.x = std::stof( line.substr( firstMark, std::string::npos ) );
	out.y = std::stof( line.substr( secondMark, std::string::npos ) );
	out.z = std::stof( line.substr( thirdMark, std::string::npos ) );
	//std::cout << out.x << ", " << out.y << ", " << out.z << std::endl;
	return out;
}

Face parse_face( const std::string& line )
{
	Face out;
	size_t marks[3];
	marks[0] = line.find( ' ', 0 ) + 1;
	for( auto i = 1u; i < 3u; ++i )
	{
		marks[i] = line.find( ' ', marks[i-1] ) + 1;
	}

	for( auto i = 0u; i < 3u; ++i )
	{
		out.v[i] = std::stol( line.substr( marks[i], std::string::npos ) );
		marks[i] = line.find( '/', marks[i] ) + 1;
		out.t[i] = std::stol( line.substr( marks[i], std::string::npos ) );
		marks[i] = line.find( '/', marks[i] ) + 1;
		out.n[i] = std::stol( line.substr( marks[i], std::string::npos ) );
		//std::cout << "got face " << out.v[i] << "/" << out.t[i] << "/" << out.n[i] << std::endl;
	}

	return out;
}
