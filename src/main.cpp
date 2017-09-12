#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <Version.h>
#include <types.h>

bool parse_file( std::ifstream& filedata, std::vector<Vertex>& vert, std::vector<Texture>& text, std::vector<Normal>& norm, std::vector<Face>& face );
bool write_file( std::ostream& file, const std::string&, const std::vector<Vertex>&, const std::vector<Texture>&, const std::vector<Normal>&, const std::vector<Face>& );
bool write_file_raw( std::ostream& file, const std::string& prefix, const std::vector<float>& d );
std::vector<float> expand_faces( const std::vector<Vertex>& v, const std::vector<Texture>& t, const std::vector<Normal>& n, const std::vector<Face>& f );

int main( int argc, char ** argv )
{
	if( argc <= 1 )
	{
		std::cerr << "[ERROR] No input files, use -help\n";
		return EXIT_FAILURE;
	}
	bool useCout( false );
	bool writeFaces( false );
	for( int i = 1; i < argc; ++i )
	{
		if( argv[i][0] == '-' )
		{
			if( std::strcmp( "-h", argv[i] ) == 0 or std::strcmp( "-help", argv[i] ) == 0 )
			{
				std::cout << R"(HOW TO EXECUTE:
gert-wavefrontc [options] FILENAME
	you can use multiple files as input if space seperated

OPTIONS:
	-h[elp]         displays this text
	-v[ersion]      displays the version number
	-c[out]         output is using std::cout, can be piped into files
	-f[aces]        output is blocked into vertex, texture coordinates, normals and faces
)" << std::endl;
			}
			else if( std::strcmp( "-v", argv[i] ) == 0 or std::strcmp( "-version", argv[i] ) == 0 )
			{
				std::cerr << "[INFO] gert-wavefrontc version #" << version::str << std::endl;
			}
			else if( std::strcmp( "-c", argv[i] ) == 0 or std::strcmp( "-cout", argv[i] ) == 0 )
			{
				useCout = true;
			}
			else if( std::strcmp( "-f", argv[i] ) == 0 or std::strcmp( "-faces", argv[i] ) == 0 )
			{
				writeFaces = true;
			}
			else
			{
				std::cerr << "[WARNING] Unrecognized argument \"" << argv[i] << "\" use -help\n";
			}
			continue;
		}
		std::ifstream wavefrontFile( argv[i] );
		if( not wavefrontFile.is_open() )
		{
			std::cerr << "[ERROR] File " << argv[i] << " couldn't open\n";
			continue;
		}
		//data loaded ready to go

		std::vector<Vertex> _vert;
		std::vector<Texture> _text;
		std::vector<Normal> _norm;
		std::vector<Face> _face;

		std::cout << "//Using file " << argv[i] << std::endl;
		if( not parse_file( wavefrontFile, _vert, _text, _norm, _face ) )
		{
			std::cerr << "[ERROR] Couldn't parse file " << argv[i] << " aborting operation\n";
		}

		std::vector<float> _raw = expand_faces( _vert, _text, _norm, _face );
		//std::cerr << "[INFO] expanded size | face count: " << _raw.size()/8 << " | " << _face.size()*3 << std::endl;

		std::ofstream outFile;
		if( not useCout )
		{//get outfilename
			std::string outname( argv[i] );
			size_t slashfind = outname.rfind( '/' );
			if( slashfind == std::string::npos ) slashfind = 0;
			else ++slashfind;
			outname = outname.substr( slashfind );
			outname = outname.substr( 0, outname.rfind( '.' ) );
			outname.append( ".c" );
			std::cerr << "[INFO] Output file: " << outname << std::endl;
			outFile.open( outname.c_str() );
			if( not outFile.is_open() )
			{
				std::cerr << "[ERROR] Couldn't open output file " << outname << std::endl;
				continue;
			}
		}
		std::string prefix( argv[i] );
		size_t slashfind = prefix.rfind( '/' );
		if( slashfind == std::string::npos ) slashfind = 0;
		else ++slashfind;
		prefix = prefix.substr( slashfind );
		prefix = prefix.substr( 0, prefix.find( '.' ) );
		std::ostream* currentOut = &outFile;
		if( useCout )
		{
			currentOut = &std::cout;
		}
		if( writeFaces and ( not write_file( *currentOut, prefix, _vert, _text, _norm, _face ) ))
		{
			std::cerr << "[ERROR] Writing file failed\n";
			continue;
		}
		else if( not write_file_raw( *currentOut, prefix, _raw ) )
		{
			std::cerr << "[ERROR] Writing raw failed\n";
			continue;
		}
	}
	return EXIT_SUCCESS;
}
