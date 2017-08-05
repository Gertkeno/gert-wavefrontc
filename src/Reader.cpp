#include <fstream>
#include <vector>
#include <types.h>
#include <iostream>

Vertex parse_vertex( const std::string& );
Texture parse_texture( const std::string& );
Normal parse_normal( const std::string& );
Face parse_face( const std::string& );

bool parse_file( std::ifstream& filedata, std::vector<Vertex>& vert, std::vector<Texture>& text, std::vector<Normal>& norm, std::vector<Face>& face )
{
	std::string activeLine;
	while( not filedata.eof() )
	{
		std::getline( filedata, activeLine, '\n' );
		if( activeLine[0] == '#' ) continue;
		std::string header( activeLine.substr( 0, activeLine.find( ' ' ) ) );
		if( header.empty() ) continue;
		if( header.compare( "v" ) == 0 )
		{
			//parse vertex
			vert.push_back( parse_vertex( activeLine ) );
		}
		else if( header.compare( "vt" )  ==  0 )
		{
			//parse texture
			text.push_back( parse_texture( activeLine ) );
		}
		else if( header.compare( "vn" ) == 0 )
		{
			//parse normal
			norm.push_back( parse_normal( activeLine ) );
		}
		else if( header.compare( "f" ) == 0 )
		{
			//parse face
			face.push_back( parse_face( activeLine ) );
		}
		else
		{
			std::cout << "//WARNING: unknown header " << header << std::endl;
		}
	}
	//std::cout << "//notice: reached end of file\n";
	return true;
}
