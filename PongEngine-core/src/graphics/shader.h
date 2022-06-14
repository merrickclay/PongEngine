#pragma once

#include <GL/glew.h>

#include "../utils/fileutils.h"
#include "../math/math.h"

namespace pongEngine { namespace graphics {
	
	class Shader {
	private:
		GLuint m_ShaderId;
		const char *m_VertPath, *m_FragPath;
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();


		void setUniform(const GLchar* name, const int value);
		void setUniform(const GLchar* name, const float value);
		void setUniform(const GLchar* name, const math::vec2& value);
		void setUniform(const GLchar* name, const math::vec3& value);
		void setUniform(const GLchar* name, const math::vec4& value);
		void setUniform(const GLchar* name, const math::mat4& value);

		void enable() const;
		void disable() const;
	private:
		GLuint load();
		GLint getUniformLocation(const GLchar* name);
	};

} }