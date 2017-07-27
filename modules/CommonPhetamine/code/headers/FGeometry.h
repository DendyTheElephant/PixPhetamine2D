////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////====================================================================================================================================////
/// | \file		FGeometry
///	| \author	Daniel Huc
/// | \date		July 2017
/// |----------------------------------------------------------------------------------------------------------------------------------
/// | \brief	Blabla
/// | \details	Blabla
////====================================================================================================================================////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
/* Standard library includes */
#include <math.h>

/* External dependencies */

/* Modules include */
#include "DBasicTypes.h"
#include "DBasicGeometryTypes.h"

/* Internal headers includes */

/* Specific defines */

//// ---- Namespaces ---- ////
namespace CommonPhetamine {
	namespace Geometry {

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//// ---- Functions -----																												////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		static pxVec3f(*normalize)(pxVec3f const& vector) = &glm::normalize;
		static pxVec3f(*cross)(pxVec3f const& vector1, pxVec3f const& vector2) = &glm::cross;
		static pxFloat(*mod)(pxFloat value, pxFloat module) = &std::fmod;
		static pxFloat(*toRadians)(pxFloat const& value) = &glm::radians;
		static pxFloat(*clamp)(pxFloat const& value, pxFloat const& min, pxFloat const& max) = &glm::clamp;

		/// \brief		Useless function
		/// \details    Forces to have a cpp file ( dumb microsoft's visual studio project proprieties only displays c++ section if cpp exists
		///				also __declspec(dllexport) to generate a .lib (dumb VC compiler again)
		__declspec(dllexport) void dummyfunction();
	}
}
