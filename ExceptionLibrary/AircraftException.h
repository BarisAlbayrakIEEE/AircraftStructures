/// <summary>
/// Contains exception definitions for AircraftStructures namespace
/// 
/// author: baris.albayrak.ieee@gmail.com
/// github: https://github.com/BarisAlbayrakIEEE?tab=repositories
/// </summary>

#ifndef _GeometryException_hxx_
#define _GeometryException_hxx_

#include <iostream>
using namespace std;

namespace AircraftStructures {
	class AircraftException : public std::exception
	{
	public:
		char const* what() const
		{
			return "TBD";
		}
	};
}

#endif