#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <types.h>

bool parse_file( std::ifstream& filedata, std::vector<Vertex>& vert, std::vector<Texture>& text, std::vector<Normal>& norm, std::vector<Face>& face );
bool write_file( std::ofstream& file, const std::string&, const std::vector<Vertex>&, const std::vector<Texture>&, const std::vector<Normal>&, const std::vector<Face>& );

int main( int argc, char ** argv )
{
	if( argc <= 1 )
	{
		std::cout << "No input files, use -help\n";
		return EXIT_FAILURE;
	}
	for( int i = 1; i < argc; ++i )
	{
		if( argv[i][0] == '-' )
		{
			if( std::strcmp( "-help", argv[i] ) == 0 )
			{
				std::cout << "no help yet\n";
			}
			continue;
		}
		std::ifstream wavefrontFile( argv[i] );
		if( not wavefrontFile.is_open() )
		{
			std::cout << "File " << argv[i] << " couldn't open\n";
			continue;
		}
		//data loaded ready to go
		
		std::vector<Vertex> _vert;
		std::vector<Texture> _text;
		std::vector<Normal> _norm;
		std::vector<Face> _face;

		std::cout << "--Starting file " << argv[i] << std::endl;
		if( not parse_file( wavefrontFile, _vert, _text, _norm, _face ) )
		{
			std::cout << "ERROR: Couldn't parse file " << argv[i] << " aborting operation\n";
		}
		
		std::ofstream outFile;
		{//get outfilename
			std::string outname( argv[i] );
			outname = outname.substr( 0, outname.rfind( '.' ) );
			outname.append( ".c" );
			std::cout << "--Output file: " << outname << std::endl;
			outFile.open( outname.c_str() );
		}
		std::string prefix( argv[i] );
		prefix = prefix.substr( 0, prefix.find( '.' ) );
		if( not outFile.is_open() )
		{
			std::cout << "ERROR: Couldn't open output file\n";
			continue;
		}
		if( not write_file( outFile, prefix, _vert, _text, _norm, _face ) )
		{
			std::cout << "ERROR: Writing file failed\n";
			continue;
		}
	}
	return EXIT_SUCCESS;
}
