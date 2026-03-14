#include <crcle/crcle.hpp>

int main(int argc, char** argv)
{
	exit(crc32::  zip::hdr() &&
	     crc16::  arc::chk() &&
	     crc32::  zip::chk() &&
	     crc32::iscsi::chk() &&
	     crc32::mpeg2::chk() &&
	     crc32::ccitt::chk() ? 
	     EXIT_SUCCESS : EXIT_FAILURE);
}
