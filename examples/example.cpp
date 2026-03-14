#include <crcle/crcle.hpp>

int main(int argc, char** argv)
{
	exit(crc32::zip::header()  &&
	     crc16::  arc::check() &&
	     crc32::  zip::check() &&
	     crc32::iscsi::check() &&
	     crc32::mpeg2::check() &&
	     crc32::ccitt::check() ? 
	     EXIT_SUCCESS : EXIT_FAILURE);

}
