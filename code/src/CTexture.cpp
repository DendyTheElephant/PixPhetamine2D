﻿#include "CTexture.h"

namespace PixPhetamine2D {

	namespace LowLevelWrapper {

		void CTexture::initializeTexture(pxUInt16 const& a_width, pxUInt16 const& a_height, ETextureType const& a_textureType, pxBool const& a_willBeMultisampled, const void* a_data) {
			STACK_TRACE;

			m_textureType = a_textureType;
			m_isMultisampled = a_willBeMultisampled;
			m_width = a_width;
			m_height = a_height;

			GLenum target, format, dataType;
			GLint internalFormat, filtering;

			(a_willBeMultisampled) ? target = GL_TEXTURE_2D_MULTISAMPLE : target = GL_TEXTURE_2D;

			switch (a_textureType) {
			case ETextureType::NORMAL:
				internalFormat = GL_RGBA;
				format = GL_RGBA;
				filtering = GL_LINEAR;
				dataType = GL_FLOAT;
				break;
			case ETextureType::TRANSPARENT:
				internalFormat = GL_RGBA;
				format = GL_RGBA;
				filtering = GL_LINEAR;
				dataType = GL_FLOAT;
				break;
			case ETextureType::HDR:
				internalFormat = GL_RGB16F;
				format = GL_RGB;
				filtering = GL_LINEAR;
				dataType = GL_FLOAT;
				break;
			case ETextureType::HDR_TRANSPARENT:
				internalFormat = GL_RGBA16F;
				format = GL_RGBA;
				filtering = GL_LINEAR;
				dataType = GL_FLOAT;
				break;
			case ETextureType::DEPTH:
				internalFormat = GL_DEPTH_COMPONENT24;
				format = GL_DEPTH_COMPONENT;
				filtering = GL_NEAREST;
				dataType = GL_FLOAT;
				break;
			}

			glGenTextures(1, &m_id);
			glBindTexture(target, m_id);

			if (a_willBeMultisampled) {
				glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, PIX::MSAA_X, internalFormat, a_width, a_height, GL_TRUE);
			}
			else {
				glTexParameteri(target, GL_TEXTURE_MAG_FILTER, filtering);
				glTexParameteri(target, GL_TEXTURE_MIN_FILTER, filtering);
				glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, a_width, a_height, 0, format, dataType, a_data);
			}

			glBindTexture(target, 0);

			STACK_MESSAGE("Checking OpenGL errors");
			Utility::UErrorHandler::checkOpenGLErrors();

			UNSTACK_TRACE;
		}

		CTexture::CTexture(std::string const& a_texturePath, ETextureType const& a_textureType, pxBool const& a_willBeMultisampled) {
			STACK_TRACE;
			SDL_Surface *image = IMG_Load(a_texturePath.c_str());
			if (image == nullptr) {
				STACK_TRACE;
				ERROR("Failed to load image: " + a_texturePath + " please check if it exists");
			}
			initializeTexture(image->w, image->h, a_textureType, a_willBeMultisampled, image->pixels);
			SDL_FreeSurface(image);
			UNSTACK_TRACE;
		}

		CTexture::CTexture(pxUInt16 const& a_width, pxUInt16 const& a_height, ETextureType const& a_textureType, pxBool const& a_willBeMultisampled) {
			STACK_TRACE;
			initializeTexture(a_width, a_height, a_textureType, a_willBeMultisampled, nullptr);
			UNSTACK_TRACE;
		}

		CTexture::~CTexture() {
			glDeleteTextures(1, &m_id);
		}
	}
}