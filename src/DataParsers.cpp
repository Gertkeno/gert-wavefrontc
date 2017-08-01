#include <string>
#include <types.h>
#include <iostream>

Vertex parse_vertex( const std::string& line )
{
	Vertex out;
	size_t firstMark = line.find( ' ', 0 ) + 1;
	size_t secondMark = line.find( ' ', firstMark ) + 1;
	size_t thirdMark = line.find( ' ', secondMark ) + 1;
	out.x = std::strtof( line.substr( firstMark, std::string::npos ).c_str(), nullptr );
	out.y = std::strtof( line.substr( secondMark, std::string::npos ).c_str(), nullptr );
	out.z = std::strtof( line.substr( thirdMark, std::string::npos ).c_str(), nullptr );
	std::cout << out.x << ", " << out.y << ", " << out.z << ", " << std::endl;
	//std::cout << firstMark << ", " << secondMark << ", " << thirdMark << ", " << std::endl;
	return out;
}
