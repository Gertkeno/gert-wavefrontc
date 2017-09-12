#include <iostream>
#include <fstream>
#include <vector>
#include <types.h>
#include <Version.h>

constexpr int LINE_BREAK_RATE = 8;

bool write_file_raw( std::ostream& file, const std::string& prefix, const std::vector<float>& d )
{
	//version control
	file << "//made with gert-wavefrontc #" << version::str << "\n";
	//start write
	file << "const float " << prefix << "_vertices[] = {";
	for( auto i = 0u; i < d.size(); ++i )
	{
		if( i%LINE_BREAK_RATE == 0 )
		{
			file << "\n";
		}
		file << std::to_string( d[i] ) << ", ";
	}
	file << "};\n";
	//total vertices count
	file << "const unsigned int " << prefix << "_len = " << d.size()/8 << ";\n";
	return true;
}
