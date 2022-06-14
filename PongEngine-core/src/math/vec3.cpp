#include "vec3.h"

namespace pongEngine { namespace math {

	vec3::vec3() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(const float& x, const float& y, const float& z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3& vec3::add(const vec3& other) {
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	vec3& vec3::subtract(const vec3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	vec3& vec3::multiply(const vec3& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	vec3& vec3::divide(const vec3& other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	vec3& vec3::normalize() {
		float magnitude = this->magnitude();
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;

		return *this;
	}

	float vec3::magnitude() {
		return std::sqrt(std::pow(x, 2.0f) + pow(y, 2.0f) + pow(z, 2.0f));
	}

	vec3 vec3::normalized() {
		vec3 normVec = vec3();
		float magnitude = this->magnitude();
		normVec.x /= magnitude;
		normVec.y /= magnitude;
		normVec.z /= magnitude;

		return normVec;
	}

	vec3 operator+(vec3 left, const vec3& right) {
		return left.add(right);
	}

	vec3 operator-(vec3 left, const vec3& right) {
		return left.subtract(right);
	}

	vec3 operator*(vec3 left, const vec3& right) {
		return left.multiply(right);
	}

	vec3 operator/(vec3 left, const vec3& right) {
		return left.divide(right);
	}

	vec3& vec3::operator+=(const vec3& other) {
		return this->add(other);
	}

	vec3& vec3::operator-=(const vec3& other) {
		return this->subtract(other);
	}

	vec3& vec3::operator*=(const vec3& other) {
		return this->multiply(other);
	}

	vec3& vec3::operator/=(const vec3& other) {
		return this->divide(other);
	}

	bool vec3::operator==(const vec3& other) {
		return x == other.x && y == other.y && z == other.z;
	}

	bool vec3::operator!=(const vec3& other) {
		return !(*this == other);
	}

	std::ostream& operator<<(std::ostream& stream, const vec3& vector) {
		stream << "vec3(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}

} }