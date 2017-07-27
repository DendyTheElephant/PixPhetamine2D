////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////====================================================================================================================================////
/// | \file		DInternalTypesAliases
///	| \author	Daniel Huc
/// | \date		February 2017
/// |----------------------------------------------------------------------------------------------------------------------------------
/// | \brief	Aliases for types
/// | \details	Using standart types may cause confusion in memory representation (depending on system) \n
///	|			Plus if some mathematical functions will be changed in the future, we want to avoid multiple modifications!
////====================================================================================================================================////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

/* Standard library includes */

/* External dependencies */
#include <glm/gtc/type_ptr.hpp>


//// ---- Namespaces ---- ////
///* Substitution Aliases */
using pxVec2i = glm::i32vec2;		/// Signed 32*2b integer vector
using pxVec2f = glm::f32vec2;		/// Signed 32*2b floating-point vector
using pxVec3f = glm::f32vec3;		/// Signed 32*3b floating-point vector
using pxVec4f = glm::f32vec4;		/// Signed 32*4b floating-point vector
using pxVec3f64 = glm::f64vec3;		/// Signed 64*3b floating-point vector
using pxMat4f = glm::f32mat4;		/// Signed 32*4*4b floating-point matrix