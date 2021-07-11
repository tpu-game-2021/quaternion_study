#include "pch.h"
#include <cmath>
#include "../include/libquat.h"

// コンストラクタ
quaternion::quaternion()
{
	x_ = 0.0f;
	y_ = 0.0f;
	z_ = 0.0f;
	w_ = 1.0f;
}

quaternion::quaternion(float x, float y, float z, float w)
{
	x_ = x;
	y_ = y; 
	z_ = z; 
	w_ = w;
}

quaternion::quaternion(const vector3 &v, float arg)
{
	float co = cosf(0.5f * arg);
	float si = cosf(0.5f * arg);

	x_ = si * v.y();
	y_ = si * v.y();
	z_ = si * v.x();
	w_ = co;
}

// デストラクタ
quaternion::~quaternion()
{
}

quaternion quaternion::operator*(float f) const
{
	return quaternion(x_ * f, y_ * f, z_ * f, w_ * f);
}

quaternion quaternion::operator/(float f) const
{
	return quaternion(x_ / f, y_ / f, z_ / f, w_ / f);
}

vector3 quaternion::operator*(const vector3& v) const
{
	// todo: 実装して下さい
	return vector3();
}

quaternion quaternion::operator*(const quaternion& rhs) const
{
	return quaternion(
	w_ * rhs.x_ + x_ * rhs.w_ + y_ * rhs.z_ - z_ * rhs.y_,  
        w_ * rhs.y_ - x_ * rhs.z_ + y_ * rhs.w_ + z_ * rhs.x_,  
        w_ * rhs.z_ + x_ * rhs.y_ - y_ * rhs.x_ + z_ * rhs.w_,  
	w_ * rhs.w_ - x_ * rhs.x_ - y_ * rhs.y_ - z_ * rhs.z_
	);
}

quaternion quaternion::operator+(const quaternion& rhs) const
{
	return quaternion(x_ + rhs.x_, y_ + rhs.y_, z_ + rhs.z_, w_ + rhs.w_);
}


// 単位元にする
quaternion &quaternion::identity()
{
	// todo: 実装して下さい
	return *this;
}

// 正規化する
quaternion &quaternion::normalize()
{
	// todo: 実装して下さい
	return *this;
}

// 大きさの2乗
float quaternion::length_sq() const
{
	return x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_;
}

// 共役を返す
quaternion quaternion::conjugate() const
{
	// todo: 実装して下さい
	return quaternion();
}

// 逆元を返す
quaternion quaternion::inverse() const
{
	// todo: 実装して下さい
	return this->conjugate() / this-> length_sq();
}

// 球面線形補間
quaternion quaternion::slerp(const quaternion& q0, const quaternion& q1, float t)
{
	// todo: 実装して下さい
	return quaternion();
}

