#pragma once
#include <assert.h>

struct Vec2 {
	float x;
	float y;

public:
	Vec2()
		:x(0.f)
		, y(0.f)
	{}

	Vec2(int _x, int _y)
		: x((float)_x)
		, y((float)_y)
	{}

	Vec2(float _x, float _y)
		: x(_x)
		, y(_y)
	{}

	Vec2(const Vec2& v) 
		: x(v.x)
		, y(v.y) 
	{}

	Vec2 operator +(const Vec2& _other) {
		return Vec2(this->x + _other.x, this->y + _other.y);
	}

	Vec2 operator -(const Vec2& _other) {
		return Vec2(this->x - _other.x, this->y - _other.y);
	}

	Vec2 operator *(const Vec2& _other) {
		return Vec2(this->x * _other.x, this->y * _other.y);
	}

	Vec2 operator /(const Vec2& _other) {
		assert(_other.x == 0 || _other.y == 0);
		return Vec2(this->x / _other.x, this->y / _other.y);
	}
};




