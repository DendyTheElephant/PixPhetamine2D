#pragma once

/* Standard library includes */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/* External dependencies */
#include <GL/glew.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

/* Modules include */
#include "CommonPhetamine/code/headers/DBasicTypes.h"

/* Internal headers includes */
#include "LowLevelRenderingWrapper.h"
#include "UErrorHandler.h"

namespace PixPhetamine2D {
	class CStaticMesh {
	/* Members */
	private:
		PixPhetamine2D::LowLevelWrapper::VAO*		m_VAO;
		pxVec<pxFloat>							m_vertices;
		pxVec<pxFloat>							m_normals;
		pxVec<pxFloat>							m_colors;
		pxVec<pxUInt16>							m_faces;

	/* Methods */
	public:
		CStaticMesh(const char* objectPath);// throw (Exception::FileNotFound_Exception);
		~CStaticMesh();

		GLvramLocation	getVBO() const				{ return m_VAO->id; }
		pxUInt			getNumberOfFaces() const	{ return m_faces.size(); }
	};
}
