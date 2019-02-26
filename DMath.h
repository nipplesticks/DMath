#pragma once
#include <DirectXMath.h>
#include <string>
namespace DM
{
	// TODO :: Cross and Dot for Integer vectors


	struct Vec2f
	{
	public:
#pragma region Constructors
		Vec2f(float _x = 0.0f, float _y = 0.0f)
		{
			vec.x = _x;
			vec.y = _y;
		}

		Vec2f(const DirectX::XMFLOAT2 & _xmFlt)
		{
			vec = _xmFlt;
		}

		Vec2f(const Vec2f & _vec2)
		{
			vec = _vec2.vec;
		}
		
#pragma endregion

#pragma region Vector Operators

		Vec2f & operator=(const Vec2f & _vec2f)
		{
			if (this != &_vec2f)
			{
				vec = _vec2f.vec;
			}

			return *this;
		}

		Vec2f & operator=(const DirectX::XMFLOAT2 & _xmFlt)
		{
			vec = _xmFlt;
			
			return *this;
		}

		Vec2f operator+(const DirectX::XMVECTOR & _xmVec) const
		{
			Vec2f sum;

			sum.Store(DirectX::XMVectorAdd(Load(), _xmVec));

			return sum;
		}
		
		Vec2f operator-(const DirectX::XMVECTOR & _xmVec) const
		{
			Vec2f sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), _xmVec));

			return sum;
		}
		
		Vec2f operator*(const DirectX::XMVECTOR & _xmVec)
		{
			Vec2f product;

			product.Store(DirectX::XMVectorMultiply(Load(), _xmVec));

			return product;
		}

		Vec2f operator/(const DirectX::XMVECTOR & _xmVec)
		{
			Vec2f product;

			product.Store(DirectX::XMVectorDivide(Load(), _xmVec));

			return product;
		}

		Vec2f operator+(const Vec2f & _vec2f) const
		{
			Vec2f sum;
			
			sum.Store(DirectX::XMVectorAdd(Load(), _vec2f.Load()));

			return sum;
		}

		Vec2f operator+(const DirectX::XMFLOAT2 & _xmFlt) const
		{
			Vec2f sum;

			sum.Store(DirectX::XMVectorAdd(Load(), DirectX::XMLoadFloat2(&_xmFlt)));

			return sum;
		}

		Vec2f operator-(const Vec2f & _vec2f) const
		{
			Vec2f sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), _vec2f.Load()));

			return sum;
		}

		Vec2f operator-(const DirectX::XMFLOAT2 & _xmFlt) const
		{
			Vec2f sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), DirectX::XMLoadFloat2(&_xmFlt)));

			return sum;
		}

		Vec2f operator*(const Vec2f & _vec2f) const
		{
			Vec2f product;

			product.Store(DirectX::XMVectorMultiply(Load(), _vec2f.Load()));

			return product;
		}

		Vec2f operator*(const DirectX::XMFLOAT2 & _xmFlt) const
		{
			Vec2f product;

			product.Store(DirectX::XMVectorMultiply(Load(), DirectX::XMLoadFloat2(&vec)));

			return product;
		}

		Vec2f operator/(const Vec2f & _vec2f) const
		{
			Vec2f product;

			product.Store(DirectX::XMVectorDivide(Load(), _vec2f.Load()));

			return product;
		}

		Vec2f operator/(const DirectX::XMFLOAT2 & _xmFlt) const
		{
			Vec2f product;

			product.Store(DirectX::XMVectorDivide(Load(), DirectX::XMLoadFloat2(&vec)));

			return product;
		}

		Vec2f & operator+=(const Vec2f & _vec2f)
		{
			*this = *this + _vec2f;

			return *this;
		}

		Vec2f & operator+=(const DirectX::XMFLOAT2 & _xmFlt)
		{
			*this = *this + _xmFlt;

			return *this;
		}

		Vec2f & operator+=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this + _xmVec;

			return *this;
		}

		Vec2f & operator-=(const Vec2f & _vec2f)
		{
			*this = *this - _vec2f;

			return *this;
		}

		Vec2f & operator-=(const DirectX::XMFLOAT2 & _xmFlt)
		{
			*this = *this - _xmFlt;

			return *this;
		}

		Vec2f & operator-=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this - _xmVec;

			return *this;
		}

		Vec2f & operator*=(const Vec2f & _vec2f)
		{
			*this = *this * _vec2f;

			return *this;
		}

		Vec2f & operator*=(const DirectX::XMFLOAT2 & _xmFlt)
		{
			*this = *this * _xmFlt;

			return *this;
		}

		Vec2f & operator*=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this * _xmVec;

			return *this;
		}

		Vec2f & operator/=(const Vec2f & _vec2f)
		{
			*this = *this / _vec2f;

			return *this;
		}

		Vec2f & operator/=(const DirectX::XMFLOAT2 & _xmFlt)
		{
			*this = *this / _xmFlt;

			return *this;
		}

		Vec2f & operator/=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this / _xmVec;

			return *this;
		}

		bool operator==(const Vec2f & _vec2f) const
		{
			static float EPSILON = 0.0001f;

			Vec2f rest = (*this - _vec2f).Abs();

			return rest.x < EPSILON && rest.y < EPSILON;
		}

		bool operator==(const DirectX::XMFLOAT2 & _xmFlt) const
		{
			static float EPSILON = 0.0001f;

			Vec2f rest = (*this - _xmFlt).Abs();

			return rest.x < EPSILON && rest.y < EPSILON;
		}

		bool operator==(const DirectX::XMVECTOR & _xmVec) const
		{
			static float EPSILON = 0.0001f;

			Vec2f rest = (*this - _xmVec).Abs();

			return rest.x < EPSILON && rest.y < EPSILON;
		}

#pragma endregion

#pragma region Matrix Operators
		Vec2f operator*(const DirectX::XMMATRIX & _matrix)
		{
			Vec2f val;

			val.Store(DirectX::XMVector2Transform(Load(), _matrix));

			return val;
		}

		Vec2f operator*(const DirectX::XMFLOAT4X4 & _matrix)
		{
			return *this * DirectX::XMLoadFloat4x4(&_matrix);
		}

		Vec2f operator*(const DirectX::XMFLOAT3X3 & _matrix)
		{
			return *this * DirectX::XMLoadFloat3x3(&_matrix);
		}
#pragma endregion

#pragma region Functions
		
		DirectX::XMVECTOR Load() const
		{
			return DirectX::XMLoadFloat2(&vec);
		}
		
		void Store(const DirectX::XMVECTOR & vector)
		{
			DirectX::XMStoreFloat2(&vec, vector);
		}

		const DirectX::XMFLOAT2 & AsXmFloat2() const
		{
			return vec;
		}

		DirectX::XMFLOAT3 AsXmFloat3() const
		{
			DirectX::XMFLOAT3 val;
			val.x = x;
			val.y = y;
			val.z = 0.0f;

			return val;
		}

		DirectX::XMFLOAT4 AsXmFloat4() const
		{
			DirectX::XMFLOAT4 val;
			val.x = x;
			val.y = y;
			val.z = 0.0f;
			val.w = 0.0f;

			return val;
		}

		DirectX::XMINT2 AsXmInt2() const
		{
			DirectX::XMINT2 val;
			val.x = (int)x;
			val.y = (int)y;

			return val;
		}

		DirectX::XMINT3 AsXmInt3() const
		{
			DirectX::XMINT3 val;
			val.x = (int)x;
			val.y = (int)y;
			val.z = 0;

			return val;
		}

		DirectX::XMINT4 AsXmInt4() const
		{
			DirectX::XMINT4 val;
			val.x = (int)x;
			val.y = (int)y;
			val.z = 0;
			val.w = 0;

			return val;
		}

		Vec2f Abs() const
		{
			return Vec2f(fabs(x), fabs(y));
		}

		Vec2f Normalize() const
		{
			Vec2f nor;

			nor.Store(DirectX::XMVector2Normalize(Load()));

			return nor;
		}

		Vec2f Round() const
		{
			Vec2f val;
			val.Store(DirectX::XMVectorRound(Load()));
			return val;
		}

		DirectX::XMFLOAT3 Cross(const DirectX::XMVECTOR & vector)
		{
			DirectX::XMFLOAT3 val;
			DirectX::XMStoreFloat3(&val, DirectX::XMVector3Cross(Load(), vector));
			return val;
		}

		DirectX::XMFLOAT3 Cross(const Vec2f & _Vec2f)
		{
			DirectX::XMFLOAT3 val;
			DirectX::XMStoreFloat3(&val, DirectX::XMVector3Cross(Load(), _Vec2f.Load()));
			return val;
		}

		DirectX::XMFLOAT3 Cross(const DirectX::XMFLOAT3 & _xmFlt)
		{
			DirectX::XMFLOAT3 val;
			DirectX::XMStoreFloat3(&val, DirectX::XMVector3Cross(Load(), DirectX::XMLoadFloat3(&_xmFlt)));
			return val;
		}

		float Dot(const DirectX::XMVECTOR & vector)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector2Dot(Load(), vector));
		}

		float Dot(const Vec2f & _Vec2f)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector2Dot(Load(), _Vec2f.Load()));
		}

		float Dot(const DirectX::XMFLOAT2 & _xmFlt)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector2Dot(Load(), DirectX::XMLoadFloat2(&_xmFlt)));
		}

		float Length() const
		{
			return DirectX::XMVectorGetX(DirectX::XMVector2Length(Load()));
		}

		float LengthSq() const
		{
			return DirectX::XMVectorGetX(DirectX::XMVector2LengthSq(Load()));
		}

		std::string ToString() const
		{
			std::string str = "X: " + std::to_string(x) + ", " + "Y: " + std::to_string(y);
			return str;
		}
#pragma endregion

		float &	x = vec.x;
		float & y = vec.y;

	private:
		DirectX::XMFLOAT2 vec;
	};

	struct Vec3f
	{
	public:
#pragma region Constructors
		Vec3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f)
		{
			vec.x = _x;
			vec.y = _y;
			vec.z = _z;
		}

		Vec3f(const DirectX::XMFLOAT3 & _xmFlt)
		{
			vec = _xmFlt;
		}

		Vec3f(const Vec3f & _vec3)
		{
			vec = _vec3.vec;
		}

#pragma endregion

#pragma region Vector Operators

		Vec3f & operator=(const Vec3f & _Vec3f)
		{
			if (this != &_Vec3f)
			{
				vec = _Vec3f.vec;
			}

			return *this;
		}

		Vec3f & operator=(const DirectX::XMFLOAT3 & _xmFlt)
		{
			vec = _xmFlt;

			return *this;
		}

		Vec3f operator+(const DirectX::XMVECTOR & _xmVec) const
		{
			Vec3f sum;

			sum.Store(DirectX::XMVectorAdd(Load(), _xmVec));

			return sum;
		}

		Vec3f operator-(const DirectX::XMVECTOR & _xmVec) const
		{
			Vec3f sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), _xmVec));

			return sum;
		}

		Vec3f operator*(const DirectX::XMVECTOR & _xmVec)
		{
			Vec3f product;

			product.Store(DirectX::XMVectorMultiply(Load(), _xmVec));

			return product;
		}

		Vec3f operator/(const DirectX::XMVECTOR & _xmVec)
		{
			Vec3f product;

			product.Store(DirectX::XMVectorDivide(Load(), _xmVec));

			return product;
		}

		Vec3f operator+(const Vec3f & _Vec3f) const
		{
			Vec3f sum;

			sum.Store(DirectX::XMVectorAdd(Load(), _Vec3f.Load()));

			return sum;
		}

		Vec3f operator+(const DirectX::XMFLOAT3 & _xmFlt) const
		{
			Vec3f sum;

			sum.Store(DirectX::XMVectorAdd(Load(), DirectX::XMLoadFloat3(&_xmFlt)));

			return sum;
		}

		Vec3f operator-(const Vec3f & _Vec3f) const
		{
			Vec3f sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), _Vec3f.Load()));

			return sum;
		}

		Vec3f operator-(const DirectX::XMFLOAT3 & _xmFlt) const
		{
			Vec3f sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), DirectX::XMLoadFloat3(&_xmFlt)));

			return sum;
		}

		Vec3f operator*(const Vec3f & _Vec3f) const
		{
			Vec3f product;

			product.Store(DirectX::XMVectorMultiply(Load(), _Vec3f.Load()));

			return product;
		}

		Vec3f operator*(const DirectX::XMFLOAT3 & _xmFlt) const
		{
			Vec3f product;

			product.Store(DirectX::XMVectorMultiply(Load(), DirectX::XMLoadFloat3(&vec)));

			return product;
		}

		Vec3f operator/(const Vec3f & _Vec3f) const
		{
			Vec3f product;

			product.Store(DirectX::XMVectorDivide(Load(), _Vec3f.Load()));

			return product;
		}

		Vec3f operator/(const DirectX::XMFLOAT3 & _xmFlt) const
		{
			Vec3f product;

			product.Store(DirectX::XMVectorDivide(Load(), DirectX::XMLoadFloat3(&vec)));

			return product;
		}

		Vec3f & operator+=(const Vec3f & _Vec3f)
		{
			*this = *this + _Vec3f;

			return *this;
		}

		Vec3f & operator+=(const DirectX::XMFLOAT3 & _xmFlt)
		{
			*this = *this + _xmFlt;

			return *this;
		}

		Vec3f & operator+=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this + _xmVec;

			return *this;
		}

		Vec3f & operator-=(const Vec3f & _Vec3f)
		{
			*this = *this - _Vec3f;

			return *this;
		}

		Vec3f & operator-=(const DirectX::XMFLOAT3 & _xmFlt)
		{
			*this = *this - _xmFlt;

			return *this;
		}

		Vec3f & operator-=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this - _xmVec;

			return *this;
		}

		Vec3f & operator*=(const Vec3f & _Vec3f)
		{
			*this = *this * _Vec3f;

			return *this;
		}

		Vec3f & operator*=(const DirectX::XMFLOAT3 & _xmFlt)
		{
			*this = *this * _xmFlt;

			return *this;
		}

		Vec3f & operator*=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this * _xmVec;

			return *this;
		}

		Vec3f & operator/=(const Vec3f & _Vec3f)
		{
			*this = *this / _Vec3f;

			return *this;
		}

		Vec3f & operator/=(const DirectX::XMFLOAT3 & _xmFlt)
		{
			*this = *this / _xmFlt;

			return *this;
		}

		Vec3f & operator/=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this / _xmVec;

			return *this;
		}

		bool operator==(const Vec3f & _Vec3f) const
		{
			static float EPSILON = 0.0001f;

			Vec3f rest = (*this - _Vec3f).Abs();

			return rest.x < EPSILON && rest.y < EPSILON;
		}

		bool operator==(const DirectX::XMFLOAT3 & _xmFlt) const
		{
			static float EPSILON = 0.0001f;

			Vec3f rest = (*this - _xmFlt).Abs();

			return rest.x < EPSILON && rest.y < EPSILON;
		}

		bool operator==(const DirectX::XMVECTOR & _xmVec) const
		{
			static float EPSILON = 0.0001f;

			Vec3f rest = (*this - _xmVec).Abs();

			return rest.x < EPSILON && rest.y < EPSILON;
		}

#pragma endregion

#pragma region Matrix Operators
		Vec3f operator*(const DirectX::XMMATRIX & _matrix)
		{
			Vec3f val;

			val.Store(DirectX::XMVector3Transform(Load(), _matrix));

			return val;
		}

		Vec3f operator*(const DirectX::XMFLOAT4X4 & _matrix)
		{
			return *this * DirectX::XMLoadFloat4x4(&_matrix);
		}

		Vec3f operator*(const DirectX::XMFLOAT3X3 & _matrix)
		{
			return *this * DirectX::XMLoadFloat3x3(&_matrix);
		}
#pragma endregion

#pragma region Functions

		DirectX::XMVECTOR Load() const
		{
			return DirectX::XMLoadFloat3(&vec);
		}

		void Store(const DirectX::XMVECTOR & vector)
		{
			DirectX::XMStoreFloat3(&vec, vector);
		}

		DirectX::XMFLOAT2 AsXmFloat2() const
		{
			DirectX::XMFLOAT2 val;
			val.x = x;
			val.y = y;

			return val;
		}

		const DirectX::XMFLOAT3 & AsXmFloat3() const
		{
			return vec;
		}

		DirectX::XMFLOAT4 AsXmFloat4() const
		{
			DirectX::XMFLOAT4 val;
			val.x = x;
			val.y = y;
			val.z = z;
			val.w = 0.0f;

			return val;
		}

		DirectX::XMINT2 AsXmInt2() const
		{
			DirectX::XMINT2 val;
			val.x = (int)x;
			val.y = (int)y;

			return val;
		}

		DirectX::XMINT3 AsXmInt3() const
		{
			DirectX::XMINT3 val;
			val.x = (int)x;
			val.y = (int)y;
			val.z = (int)z;

			return val;
		}

		DirectX::XMINT4 AsXmInt4() const
		{
			DirectX::XMINT4 val;
			val.x = (int)x;
			val.y = (int)y;
			val.z = (int)z;
			val.w = 0;

			return val;
		}

		Vec3f Abs() const
		{
			return Vec3f(fabs(x), fabs(y), fabs(z));
		}

		Vec3f Normalize() const
		{
			Vec3f nor;

			nor.Store(DirectX::XMVector3Normalize(Load()));

			return nor;
		}

		Vec3f Round() const
		{
			Vec3f val;
			val.Store(DirectX::XMVectorRound(Load()));
			return val;
		}

		Vec3f Cross(const DirectX::XMVECTOR & vector)
		{
			Vec3f val;
			val.Store(DirectX::XMVector3Cross(Load(), vector));
			return val;
		}

		Vec3f Cross(const Vec3f & _Vec3f)
		{
			Vec3f val;
			val.Store(DirectX::XMVector3Cross(Load(), _Vec3f.Load()));
			return val;
		}

		Vec3f Cross(const DirectX::XMFLOAT3 & _xmFlt)
		{
			Vec3f val;
			val.Store(DirectX::XMVector3Cross(Load(), DirectX::XMLoadFloat3(&_xmFlt)));
			return val;
		}

		float Dot(const DirectX::XMVECTOR & vector)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Dot(Load(), vector));
		}

		float Dot(const Vec3f & _Vec3f)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Dot(Load(), _Vec3f.Load()));
		}

		float Dot(const DirectX::XMFLOAT3 & _xmFlt)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Dot(Load(), DirectX::XMLoadFloat3(&_xmFlt)));
		}

		float Length() const
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Length(Load()));
		}

		float LengthSq() const
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3LengthSq(Load()));
		}

		std::string ToString() const
		{
			std::string str = "X: " + std::to_string(x) + ", " + "Y: " + std::to_string(y) + ", " + "Z: " + std::to_string(z);
			return str;
		}
#pragma endregion

		float &	x = vec.x;
		float & y = vec.y;
		float & z = vec.z;

	private:
		DirectX::XMFLOAT3 vec;

	};

	struct Vec4f
	{
	public:
#pragma region Constructors
		Vec4f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f, float _w = 0.0f)
		{
			vec.x = _x;
			vec.y = _y;
			vec.z = _z;
			vec.w = _w;
		}

		Vec4f(const DirectX::XMFLOAT4 & _xmFlt)
		{
			vec = _xmFlt;
		}

		Vec4f(const Vec4f & _vec4)
		{
			vec = _vec4.vec;
		}

#pragma endregion

#pragma region Vector Operators

		Vec4f & operator=(const Vec4f & _Vec4f)
		{
			if (this != &_Vec4f)
			{
				vec = _Vec4f.vec;
			}

			return *this;
		}

		Vec4f & operator=(const DirectX::XMFLOAT4 & _xmFlt)
		{
			vec = _xmFlt;

			return *this;
		}

		Vec4f operator+(const DirectX::XMVECTOR & _xmVec) const
		{
			Vec4f sum;

			sum.Store(DirectX::XMVectorAdd(Load(), _xmVec));

			return sum;
		}

		Vec4f operator-(const DirectX::XMVECTOR & _xmVec) const
		{
			Vec4f sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), _xmVec));

			return sum;
		}

		Vec4f operator*(const DirectX::XMVECTOR & _xmVec)
		{
			Vec4f product;

			product.Store(DirectX::XMVectorMultiply(Load(), _xmVec));

			return product;
		}

		Vec4f operator/(const DirectX::XMVECTOR & _xmVec)
		{
			Vec4f product;

			product.Store(DirectX::XMVectorDivide(Load(), _xmVec));

			return product;
		}

		Vec4f operator+(const Vec4f & _Vec4f) const
		{
			Vec4f sum;

			sum.Store(DirectX::XMVectorAdd(Load(), _Vec4f.Load()));

			return sum;
		}

		Vec4f operator+(const DirectX::XMFLOAT4 & _xmFlt) const
		{
			Vec4f sum;

			sum.Store(DirectX::XMVectorAdd(Load(), DirectX::XMLoadFloat4(&_xmFlt)));

			return sum;
		}

		Vec4f operator-(const Vec4f & _Vec4f) const
		{
			Vec4f sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), _Vec4f.Load()));

			return sum;
		}

		Vec4f operator-(const DirectX::XMFLOAT4 & _xmFlt) const
		{
			Vec4f sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), DirectX::XMLoadFloat4(&_xmFlt)));

			return sum;
		}

		Vec4f operator*(const Vec4f & _Vec4f) const
		{
			Vec4f product;

			product.Store(DirectX::XMVectorMultiply(Load(), _Vec4f.Load()));

			return product;
		}

		Vec4f operator*(const DirectX::XMFLOAT4 & _xmFlt) const
		{
			Vec4f product;

			product.Store(DirectX::XMVectorMultiply(Load(), DirectX::XMLoadFloat4(&vec)));

			return product;
		}

		Vec4f operator/(const Vec4f & _Vec4f) const
		{
			Vec4f product;

			product.Store(DirectX::XMVectorDivide(Load(), _Vec4f.Load()));

			return product;
		}

		Vec4f operator/(const DirectX::XMFLOAT4 & _xmFlt) const
		{
			Vec4f product;

			product.Store(DirectX::XMVectorDivide(Load(), DirectX::XMLoadFloat4(&vec)));

			return product;
		}

		Vec4f & operator+=(const Vec4f & _Vec4f)
		{
			*this = *this + _Vec4f;

			return *this;
		}

		Vec4f & operator+=(const DirectX::XMFLOAT4 & _xmFlt)
		{
			*this = *this + _xmFlt;

			return *this;
		}

		Vec4f & operator+=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this + _xmVec;

			return *this;
		}

		Vec4f & operator-=(const Vec4f & _Vec4f)
		{
			*this = *this - _Vec4f;

			return *this;
		}

		Vec4f & operator-=(const DirectX::XMFLOAT4 & _xmFlt)
		{
			*this = *this - _xmFlt;

			return *this;
		}

		Vec4f & operator-=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this - _xmVec;

			return *this;
		}

		Vec4f & operator*=(const Vec4f & _Vec4f)
		{
			*this = *this * _Vec4f;

			return *this;
		}

		Vec4f & operator*=(const DirectX::XMFLOAT4 & _xmFlt)
		{
			*this = *this * _xmFlt;

			return *this;
		}

		Vec4f & operator*=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this * _xmVec;

			return *this;
		}

		Vec4f & operator/=(const Vec4f & _Vec4f)
		{
			*this = *this / _Vec4f;

			return *this;
		}

		Vec4f & operator/=(const DirectX::XMFLOAT4 & _xmFlt)
		{
			*this = *this / _xmFlt;

			return *this;
		}

		Vec4f & operator/=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this / _xmVec;

			return *this;
		}

		bool operator==(const Vec4f & _Vec4f) const
		{
			static float EPSILON = 0.0001f;

			Vec4f rest = (*this - _Vec4f).Abs();

			return rest.x < EPSILON && rest.y < EPSILON;
		}

		bool operator==(const DirectX::XMFLOAT4 & _xmFlt) const
		{
			static float EPSILON = 0.0001f;

			Vec4f rest = (*this - _xmFlt).Abs();

			return rest.x < EPSILON && rest.y < EPSILON;
		}

		bool operator==(const DirectX::XMVECTOR & _xmVec) const
		{
			static float EPSILON = 0.0001f;

			Vec4f rest = (*this - _xmVec).Abs();

			return rest.x < EPSILON && rest.y < EPSILON;
		}

#pragma endregion

#pragma region Matrix Operators
		Vec4f operator*(const DirectX::XMMATRIX & _matrix)
		{
			Vec4f val;

			val.Store(DirectX::XMVector3Transform(Load(), _matrix));

			return val;
		}

		Vec4f operator*(const DirectX::XMFLOAT4X4 & _matrix)
		{
			return *this * DirectX::XMLoadFloat4x4(&_matrix);
		}

		Vec4f operator*(const DirectX::XMFLOAT3X3 & _matrix)
		{
			return *this * DirectX::XMLoadFloat3x3(&_matrix);
		}
#pragma endregion

#pragma region Functions

		DirectX::XMVECTOR Load() const
		{
			return DirectX::XMLoadFloat4(&vec);
		}

		void Store(const DirectX::XMVECTOR & vector)
		{
			DirectX::XMStoreFloat4(&vec, vector);
		}

		DirectX::XMFLOAT2 AsXmFloat2() const
		{
			DirectX::XMFLOAT2 val;
			val.x = x;
			val.y = y;

			return val;
		}

		DirectX::XMFLOAT3 & AsXmFloat3() const
		{
			DirectX::XMFLOAT3 val;
			val.x = x;
			val.y = y;
			val.z = z;

			return val;
		}

		const DirectX::XMFLOAT4 & AsXmFloat4() const
		{
			return vec;
		}

		DirectX::XMINT2 AsXmInt2() const
		{
			DirectX::XMINT2 val;
			val.x = (int)x;
			val.y = (int)y;

			return val;
		}

		DirectX::XMINT3 AsXmInt3() const
		{
			DirectX::XMINT3 val;
			val.x = (int)x;
			val.y = (int)y;
			val.z = (int)z;

			return val;
		}

		DirectX::XMINT4 AsXmInt4() const
		{
			DirectX::XMINT4 val;
			val.x = (int)x;
			val.y = (int)y;
			val.z = (int)z;
			val.w = (int)w;

			return val;
		}

		Vec4f Abs() const
		{
			return Vec4f(fabs(x), fabs(y), fabs(z));
		}

		Vec4f Normalize() const
		{
			Vec4f nor;

			nor.Store(DirectX::XMVector4Normalize(Load()));

			return nor;
		}

		Vec4f Round() const
		{
			Vec4f val;
			val.Store(DirectX::XMVectorRound(Load()));
			return val;
		}

		Vec4f Cross(const DirectX::XMVECTOR & vector)
		{
			Vec4f val;
			val.Store(DirectX::XMVector3Cross(Load(), vector));
			return val;
		}

		Vec4f Cross(const Vec4f & _Vec3f)
		{
			Vec4f val;
			val.Store(DirectX::XMVector3Cross(Load(), _Vec3f.Load()));
			return val;
		}

		Vec4f Cross(const DirectX::XMFLOAT4 & _xmFlt)
		{
			Vec4f val;
			val.Store(DirectX::XMVector3Cross(Load(), DirectX::XMLoadFloat4(&_xmFlt)));
			return val;
		}

		float Dot(const DirectX::XMVECTOR & vector)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Dot(Load(), vector));
		}

		float Dot(const Vec3f & _Vec3f)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Dot(Load(), _Vec3f.Load()));
		}

		float Dot(const DirectX::XMFLOAT4 & _xmFlt)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Dot(Load(), DirectX::XMLoadFloat4(&_xmFlt)));
		}

		float Length() const
		{
			return DirectX::XMVectorGetX(DirectX::XMVector4Length(Load()));
		}

		float LengthSq() const
		{
			return DirectX::XMVectorGetX(DirectX::XMVector4LengthSq(Load()));
		}

		std::string ToString() const
		{
			std::string str = "X: " + std::to_string(x) + ", " + "Y: " + std::to_string(y) + ", " + "Z: " + std::to_string(z) + ", " + "W: " + std::to_string(w);
			return str;
		}
#pragma endregion


		float &	x = vec.x;
		float & y = vec.y;
		float & z = vec.z;
		float & w = vec.w;

	private:
		DirectX::XMFLOAT4 vec;
	};

	struct Vec2i
	{
	public:
#pragma region Constructors
		Vec2i(int _x = 0, int _y = 0)
		{
			vec.x = _x;
			vec.y = _y;
		}

		Vec2i(const DirectX::XMINT2 & _xmInt)
		{
			vec = _xmInt;
		}

		Vec2i(const Vec2i & _vec2)
		{
			vec = _vec2.vec;
		}

#pragma endregion

#pragma region Vector Operators

		Vec2i & operator=(const Vec2i & _Vec2i)
		{
			if (this != &_Vec2i)
			{
				vec = _Vec2i.vec;
			}

			return *this;
		}

		Vec2i & operator=(const DirectX::XMINT2 & _xmInt)
		{
			vec = _xmInt;

			return *this;
		}

		Vec2i operator+(const DirectX::XMVECTOR & _xmVec) const
		{
			Vec2i sum;

			sum.Store(DirectX::XMVectorAdd(Load(), _xmVec));

			return sum;
		}

		Vec2i operator-(const DirectX::XMVECTOR & _xmVec) const
		{
			Vec2i sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), _xmVec));

			return sum;
		}

		Vec2i operator*(const DirectX::XMVECTOR & _xmVec)
		{
			Vec2i product;

			product.Store(DirectX::XMVectorMultiply(Load(), _xmVec));

			return product;
		}

		Vec2i operator/(const DirectX::XMVECTOR & _xmVec)
		{
			Vec2i product;

			product.Store(DirectX::XMVectorDivide(Load(), _xmVec));

			return product;
		}

		Vec2i operator+(const Vec2i & _Vec2i) const
		{
			Vec2i sum;

			sum.Store(DirectX::XMVectorAdd(Load(), _Vec2i.Load()));

			return sum;
		}

		Vec2i operator+(const DirectX::XMINT2 & _xmInt) const
		{
			Vec2i sum;

			sum.Store(DirectX::XMVectorAdd(Load(), DirectX::XMLoadSInt2(&_xmInt)));

			return sum;
		}

		Vec2i operator-(const Vec2i & _Vec2i) const
		{
			Vec2i sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), _Vec2i.Load()));

			return sum;
		}

		Vec2i operator-(const DirectX::XMINT2 & _xmInt) const
		{
			Vec2i sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), DirectX::XMLoadSInt2(&_xmInt)));

			return sum;
		}

		Vec2i operator*(const Vec2i & _Vec2i) const
		{
			Vec2i product;

			product.Store(DirectX::XMVectorMultiply(Load(), _Vec2i.Load()));

			return product;
		}

		Vec2i operator*(const DirectX::XMINT2 & _xmInt) const
		{
			Vec2i product;

			product.Store(DirectX::XMVectorMultiply(Load(), DirectX::XMLoadSInt2(&vec)));

			return product;
		}

		Vec2i operator/(const Vec2i & _Vec2i) const
		{
			Vec2i product;

			product.Store(DirectX::XMVectorDivide(Load(), _Vec2i.Load()));

			return product;
		}

		Vec2i operator/(const DirectX::XMINT2 & _xmInt) const
		{
			Vec2i product;

			product.Store(DirectX::XMVectorDivide(Load(), DirectX::XMLoadSInt2(&vec)));

			return product;
		}

		Vec2i & operator+=(const Vec2i & _Vec2i)
		{
			*this = *this + _Vec2i;

			return *this;
		}

		Vec2i & operator+=(const DirectX::XMINT2 & _xmInt)
		{
			*this = *this + _xmInt;

			return *this;
		}

		Vec2i & operator+=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this + _xmVec;

			return *this;
		}

		Vec2i & operator-=(const Vec2i & _Vec2i)
		{
			*this = *this - _Vec2i;

			return *this;
		}

		Vec2i & operator-=(const DirectX::XMINT2 & _xmInt)
		{
			*this = *this - _xmInt;

			return *this;
		}

		Vec2i & operator-=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this - _xmVec;

			return *this;
		}

		Vec2i & operator*=(const Vec2i & _Vec2i)
		{
			*this = *this * _Vec2i;

			return *this;
		}

		Vec2i & operator*=(const DirectX::XMINT2 & _xmInt)
		{
			*this = *this * _xmInt;

			return *this;
		}

		Vec2i & operator*=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this * _xmVec;

			return *this;
		}

		Vec2i & operator/=(const Vec2i & _Vec2i)
		{
			*this = *this / _Vec2i;

			return *this;
		}

		Vec2i & operator/=(const DirectX::XMINT2 & _xmInt)
		{
			*this = *this / _xmInt;

			return *this;
		}

		Vec2i & operator/=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this / _xmVec;

			return *this;
		}

		bool operator==(const Vec2i & _Vec2i) const
		{
			return x == _Vec2i.x && y == _Vec2i.y;
		}

		bool operator==(const DirectX::XMINT2 & _xmInt) const
		{
			return x == _xmInt.x && y == _xmInt.y;
		}

		bool operator==(const DirectX::XMVECTOR & _xmVec) const
		{
			static float EPSILON = 0.0001f;

			Vec2i val;
			val.Store(_xmVec);

			return *this == val;
		}

#pragma endregion

#pragma region Matrix Operators
		Vec2i operator*(const DirectX::XMMATRIX & _matrix)
		{
			Vec2f val;
			Vec2i iVal;

			val.Store(DirectX::XMVector2Transform(Load(), _matrix));

			iVal = val.Round().AsXmInt2();

			return iVal;
		}

		Vec2i operator*(const DirectX::XMFLOAT4X4 & _matrix)
		{
			return *this * DirectX::XMLoadFloat4x4(&_matrix);
		}

		Vec2i operator*(const DirectX::XMFLOAT3X3 & _matrix)
		{
			return *this * DirectX::XMLoadFloat3x3(&_matrix);
		}
#pragma endregion

#pragma region Functions

		DirectX::XMVECTOR Load() const
		{
			return DirectX::XMLoadSInt2(&vec);
		}

		void Store(const DirectX::XMVECTOR & vector)
		{
			DirectX::XMStoreSInt2(&vec, vector);
		}

		DirectX::XMFLOAT2 AsXmFloat2() const
		{
			DirectX::XMFLOAT2 val;
			val.x = (float)x;
			val.y = (float)y;
			return val;
		}

		DirectX::XMFLOAT3 AsXmFloat3() const
		{
			DirectX::XMFLOAT3 val;
			val.x = (float)x;
			val.y = (float)y;
			val.z = 0.0f;

			return val;
		}

		DirectX::XMFLOAT4 AsXmFloat4() const
		{
			DirectX::XMFLOAT4 val;
			val.x = (float)x;
			val.y = (float)y;
			val.z = 0.0f;
			val.w = 0.0f;

			return val;
		}

		const DirectX::XMINT2 & AsXmInt2() const
		{
			return vec;
		}

		DirectX::XMINT3 AsXmInt3() const
		{
			DirectX::XMINT3 val;
			val.x = x;
			val.y = y;
			val.z = 0;

			return val;
		}

		DirectX::XMINT4 AsXmInt4() const
		{
			DirectX::XMINT4 val;
			val.x = x;
			val.y = y;
			val.z = 0;
			val.w = 0;

			return val;
		}

		Vec2i Abs() const
		{
			return Vec2i(abs(x), abs(y));
		}

		Vec2f Normalize() const
		{
			Vec2f nor;

			nor.Store(DirectX::XMVector2Normalize(Load()));

			return nor;
		}

		DirectX::XMINT3 Cross(const DirectX::XMVECTOR & vector)
		{
			Vec3f fVal = AsXmFloat3();
			return fVal.Cross(vector).Round().AsXmInt3();
		}

		DirectX::XMINT3 Cross(const Vec2i & _Vec2i)
		{
			Vec3f fVal = AsXmFloat3();
			return fVal.Cross(_Vec2i.AsXmFloat3()).Round().AsXmInt3();
		}

		DirectX::XMINT3 Cross(const DirectX::XMINT3 & _xmInt)
		{
			Vec3f fVal = AsXmFloat3();
			return fVal.Cross(DirectX::XMLoadSInt3(&_xmInt)).Round().AsXmInt3();
		}

		float Dot(const DirectX::XMVECTOR & vector)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector2Dot(Load(), vector));
		}

		float Dot(const Vec2i & _Vec2i)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector2Dot(Load(), _Vec2i.Load()));
		}

		float Dot(const DirectX::XMINT2 & _xmInt)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector2Dot(Load(), DirectX::XMLoadSInt2(&_xmInt)));
		}

		float Length() const
		{
			return DirectX::XMVectorGetX(DirectX::XMVector2Length(Load()));
		}

		float LengthSq() const
		{
			return DirectX::XMVectorGetX(DirectX::XMVector2LengthSq(Load()));
		}

		std::string ToString() const
		{
			std::string str = "X: " + std::to_string(x) + ", " + "Y: " + std::to_string(y);
			return str;
		}
#pragma endregion

		int & x = vec.x;
		int & y = vec.y;

	private:
		DirectX::XMINT2 vec;
	};

	struct Vec3i
	{
	public:
#pragma region Constructors
		Vec3i(int _x = 0, int _y = 0, int _z = 0)
		{
			vec.x = _x;
			vec.y = _y;
			vec.z = _z;
		}

		Vec3i(const DirectX::XMINT3 & _xmInt)
		{
			vec = _xmInt;
		}

		Vec3i(const Vec3i & _vec2)
		{
			vec = _vec2.vec;
		}

#pragma endregion

#pragma region Vector Operators

		Vec3i & operator=(const Vec3i & _Vec3i)
		{
			if (this != &_Vec3i)
			{
				vec = _Vec3i.vec;
			}

			return *this;
		}

		Vec3i & operator=(const DirectX::XMINT3 & _xmInt)
		{
			vec = _xmInt;

			return *this;
		}

		Vec3i operator+(const DirectX::XMVECTOR & _xmVec) const
		{
			Vec3i sum;

			sum.Store(DirectX::XMVectorAdd(Load(), _xmVec));

			return sum;
		}

		Vec3i operator-(const DirectX::XMVECTOR & _xmVec) const
		{
			Vec3i sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), _xmVec));

			return sum;
		}

		Vec3i operator*(const DirectX::XMVECTOR & _xmVec)
		{
			Vec3i product;

			product.Store(DirectX::XMVectorMultiply(Load(), _xmVec));

			return product;
		}

		Vec3i operator/(const DirectX::XMVECTOR & _xmVec)
		{
			Vec3i product;

			product.Store(DirectX::XMVectorDivide(Load(), _xmVec));

			return product;
		}

		Vec3i operator+(const Vec3i & _Vec3i) const
		{
			Vec3i sum;

			sum.Store(DirectX::XMVectorAdd(Load(), _Vec3i.Load()));

			return sum;
		}

		Vec3i operator+(const DirectX::XMINT3 & _xmInt) const
		{
			Vec3i sum;

			sum.Store(DirectX::XMVectorAdd(Load(), DirectX::XMLoadSInt3(&_xmInt)));

			return sum;
		}

		Vec3i operator-(const Vec3i & _Vec3i) const
		{
			Vec3i sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), _Vec3i.Load()));

			return sum;
		}

		Vec3i operator-(const DirectX::XMINT3 & _xmInt) const
		{
			Vec3i sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), DirectX::XMLoadSInt3(&_xmInt)));

			return sum;
		}

		Vec3i operator*(const Vec3i & _Vec3i) const
		{
			Vec3i product;

			product.Store(DirectX::XMVectorMultiply(Load(), _Vec3i.Load()));

			return product;
		}

		Vec3i operator*(const DirectX::XMINT3 & _xmInt) const
		{
			Vec3i product;

			product.Store(DirectX::XMVectorMultiply(Load(), DirectX::XMLoadSInt3(&vec)));

			return product;
		}

		Vec3i operator/(const Vec3i & _Vec3i) const
		{
			Vec3i product;

			product.Store(DirectX::XMVectorDivide(Load(), _Vec3i.Load()));

			return product;
		}

		Vec3i operator/(const DirectX::XMINT3 & _xmInt) const
		{
			Vec3i product;

			product.Store(DirectX::XMVectorDivide(Load(), DirectX::XMLoadSInt3(&vec)));

			return product;
		}

		Vec3i & operator+=(const Vec3i & _Vec3i)
		{
			*this = *this + _Vec3i;

			return *this;
		}

		Vec3i & operator+=(const DirectX::XMINT3 & _xmInt)
		{
			*this = *this + _xmInt;

			return *this;
		}

		Vec3i & operator+=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this + _xmVec;

			return *this;
		}

		Vec3i & operator-=(const Vec3i & _Vec3i)
		{
			*this = *this - _Vec3i;

			return *this;
		}

		Vec3i & operator-=(const DirectX::XMINT3 & _xmInt)
		{
			*this = *this - _xmInt;

			return *this;
		}

		Vec3i & operator-=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this - _xmVec;

			return *this;
		}

		Vec3i & operator*=(const Vec3i & _Vec3i)
		{
			*this = *this * _Vec3i;

			return *this;
		}

		Vec3i & operator*=(const DirectX::XMINT3 & _xmInt)
		{
			*this = *this * _xmInt;

			return *this;
		}

		Vec3i & operator*=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this * _xmVec;

			return *this;
		}

		Vec3i & operator/=(const Vec3i & _Vec3i)
		{
			*this = *this / _Vec3i;

			return *this;
		}

		Vec3i & operator/=(const DirectX::XMINT3 & _xmInt)
		{
			*this = *this / _xmInt;

			return *this;
		}

		Vec3i & operator/=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this / _xmVec;

			return *this;
		}

		bool operator==(const Vec3i & _Vec3i) const
		{
			return x == _Vec3i.x && y == _Vec3i.y;
		}

		bool operator==(const DirectX::XMINT3 & _xmInt) const
		{
			return x == _xmInt.x && y == _xmInt.y;
		}

		bool operator==(const DirectX::XMVECTOR & _xmVec) const
		{
			static float EPSILON = 0.0001f;

			Vec3i val;
			val.Store(_xmVec);

			return *this == val;
		}

#pragma endregion

#pragma region Matrix Operators
		Vec3i operator*(const DirectX::XMMATRIX & _matrix)
		{
			Vec3f val;
			Vec3i iVal;

			val.Store(DirectX::XMVector2Transform(Load(), _matrix));

			iVal = val.Round().AsXmInt3();

			return iVal;
		}

		Vec3i operator*(const DirectX::XMFLOAT4X4 & _matrix)
		{
			return *this * DirectX::XMLoadFloat4x4(&_matrix);
		}

		Vec3i operator*(const DirectX::XMFLOAT3X3 & _matrix)
		{
			return *this * DirectX::XMLoadFloat3x3(&_matrix);
		}
#pragma endregion

#pragma region Functions

		DirectX::XMVECTOR Load() const
		{
			return DirectX::XMLoadSInt3(&vec);
		}

		void Store(const DirectX::XMVECTOR & vector)
		{
			DirectX::XMStoreSInt3(&vec, vector);
		}

		DirectX::XMFLOAT2 AsXmFloat2() const
		{
			DirectX::XMFLOAT2 val;
			val.x = (float)x;
			val.y = (float)y;
			return val;
		}

		DirectX::XMFLOAT3 AsXmFloat3() const
		{
			DirectX::XMFLOAT3 val;
			val.x = (float)x;
			val.y = (float)y;
			val.z = 0.0f;

			return val;
		}

		DirectX::XMFLOAT4 AsXmFloat4() const
		{
			DirectX::XMFLOAT4 val;
			val.x = (float)x;
			val.y = (float)y;
			val.z = 0.0f;
			val.w = 0.0f;

			return val;
		}

		DirectX::XMINT2 AsXmInt2() const
		{
			DirectX::XMINT2 val;
			val.x = x;
			val.y = y;
			
			return val;
		}

		const DirectX::XMINT3 & AsXmInt3() const
		{
			return vec;
		}

		DirectX::XMINT4 AsXmInt4() const
		{
			DirectX::XMINT4 val;
			val.x = x;
			val.y = y;
			val.z = 0;
			val.w = 0;

			return val;
		}

		Vec3i Abs() const
		{
			return Vec3i(abs(x), abs(y));
		}

		Vec3f Normalize() const
		{
			Vec3f nor;

			nor.Store(DirectX::XMVector3Normalize(Load()));

			return nor;
		}

		Vec3i Cross(const DirectX::XMVECTOR & vector)
		{
			Vec3f fVal = AsXmFloat3();
			return fVal.Cross(vector).Round().AsXmInt3();
		}

		Vec3i Cross(const Vec3i & _Vec3i)
		{
			Vec3f fVal = AsXmFloat3();
			return fVal.Cross(_Vec3i.AsXmFloat3()).Round().AsXmInt3();
		}

		Vec3i Cross(const DirectX::XMINT3 & _xmInt)
		{
			Vec3f fVal = AsXmFloat3();
			return fVal.Cross(DirectX::XMLoadSInt3(&_xmInt)).Round().AsXmInt3();
		}

		float Dot(const DirectX::XMVECTOR & vector)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Dot(Load(), vector));
		}

		float Dot(const Vec3i & _Vec3i)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Dot(Load(), _Vec3i.Load()));
		}

		float Dot(const DirectX::XMINT3 & _xmInt)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Dot(Load(), DirectX::XMLoadSInt3(&_xmInt)));
		}

		float Length() const
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Length(Load()));
		}

		float LengthSq() const
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3LengthSq(Load()));
		}

		std::string ToString() const
		{
			std::string str = "X: " + std::to_string(x) + ", " + "Y: " + std::to_string(y) + "Z: " + std::to_string(z);
			return str;
		}
#pragma endregion

		int & x = vec.x;
		int & y = vec.y;
		int & z = vec.z;

	private:
		DirectX::XMINT3 vec;

	};

	struct Vec4i
	{
	public:
#pragma region Constructors
		Vec4i(int _x = 0, int _y = 0, int _z = 0, int _w = 0)
		{
			vec.x = _x;
			vec.y = _y;
			vec.z = _z;
			vec.z = _w;
		}

		Vec4i(const DirectX::XMINT4 & _xmInt)
		{
			vec = _xmInt;
		}

		Vec4i(const Vec4i & _vec2)
		{
			vec = _vec2.vec;
		}

#pragma endregion

#pragma region Vector Operators

		Vec4i & operator=(const Vec4i & _Vec4i)
		{
			if (this != &_Vec4i)
			{
				vec = _Vec4i.vec;
			}

			return *this;
		}

		Vec4i & operator=(const DirectX::XMINT4 & _xmInt)
		{
			vec = _xmInt;

			return *this;
		}

		Vec4i operator+(const DirectX::XMVECTOR & _xmVec) const
		{
			Vec4i sum;

			sum.Store(DirectX::XMVectorAdd(Load(), _xmVec));

			return sum;
		}

		Vec4i operator-(const DirectX::XMVECTOR & _xmVec) const
		{
			Vec4i sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), _xmVec));

			return sum;
		}

		Vec4i operator*(const DirectX::XMVECTOR & _xmVec)
		{
			Vec4i product;

			product.Store(DirectX::XMVectorMultiply(Load(), _xmVec));

			return product;
		}

		Vec4i operator/(const DirectX::XMVECTOR & _xmVec)
		{
			Vec4i product;

			product.Store(DirectX::XMVectorDivide(Load(), _xmVec));

			return product;
		}

		Vec4i operator+(const Vec4i & _Vec4i) const
		{
			Vec4i sum;

			sum.Store(DirectX::XMVectorAdd(Load(), _Vec4i.Load()));

			return sum;
		}

		Vec4i operator+(const DirectX::XMINT4 & _xmInt) const
		{
			Vec4i sum;

			sum.Store(DirectX::XMVectorAdd(Load(), DirectX::XMLoadSInt4(&_xmInt)));

			return sum;
		}

		Vec4i operator-(const Vec4i & _Vec4i) const
		{
			Vec4i sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), _Vec4i.Load()));

			return sum;
		}

		Vec4i operator-(const DirectX::XMINT4 & _xmInt) const
		{
			Vec4i sum;

			sum.Store(DirectX::XMVectorSubtract(Load(), DirectX::XMLoadSInt4(&_xmInt)));

			return sum;
		}

		Vec4i operator*(const Vec4i & _Vec4i) const
		{
			Vec4i product;

			product.Store(DirectX::XMVectorMultiply(Load(), _Vec4i.Load()));

			return product;
		}

		Vec4i operator*(const DirectX::XMINT4 & _xmInt) const
		{
			Vec4i product;

			product.Store(DirectX::XMVectorMultiply(Load(), DirectX::XMLoadSInt4(&vec)));

			return product;
		}

		Vec4i operator/(const Vec4i & _Vec4i) const
		{
			Vec4i product;

			product.Store(DirectX::XMVectorDivide(Load(), _Vec4i.Load()));

			return product;
		}

		Vec4i operator/(const DirectX::XMINT4 & _xmInt) const
		{
			Vec4i product;

			product.Store(DirectX::XMVectorDivide(Load(), DirectX::XMLoadSInt4(&vec)));

			return product;
		}

		Vec4i & operator+=(const Vec4i & _Vec4i)
		{
			*this = *this + _Vec4i;

			return *this;
		}

		Vec4i & operator+=(const DirectX::XMINT4 & _xmInt)
		{
			*this = *this + _xmInt;

			return *this;
		}

		Vec4i & operator+=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this + _xmVec;

			return *this;
		}

		Vec4i & operator-=(const Vec4i & _Vec4i)
		{
			*this = *this - _Vec4i;

			return *this;
		}

		Vec4i & operator-=(const DirectX::XMINT4 & _xmInt)
		{
			*this = *this - _xmInt;

			return *this;
		}

		Vec4i & operator-=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this - _xmVec;

			return *this;
		}

		Vec4i & operator*=(const Vec4i & _Vec4i)
		{
			*this = *this * _Vec4i;

			return *this;
		}

		Vec4i & operator*=(const DirectX::XMINT4 & _xmInt)
		{
			*this = *this * _xmInt;

			return *this;
		}

		Vec4i & operator*=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this * _xmVec;

			return *this;
		}

		Vec4i & operator/=(const Vec4i & _Vec4i)
		{
			*this = *this / _Vec4i;

			return *this;
		}

		Vec4i & operator/=(const DirectX::XMINT4 & _xmInt)
		{
			*this = *this / _xmInt;

			return *this;
		}

		Vec4i & operator/=(const DirectX::XMVECTOR & _xmVec)
		{
			*this = *this / _xmVec;

			return *this;
		}

		bool operator==(const Vec4i & _Vec4i) const
		{
			return x == _Vec4i.x && y == _Vec4i.y;
		}

		bool operator==(const DirectX::XMINT4 & _xmInt) const
		{
			return x == _xmInt.x && y == _xmInt.y;
		}

		bool operator==(const DirectX::XMVECTOR & _xmVec) const
		{
			static float EPSILON = 0.0001f;

			Vec4i val;
			val.Store(_xmVec);

			return *this == val;
		}

#pragma endregion

#pragma region Matrix Operators
		Vec4i operator*(const DirectX::XMMATRIX & _matrix)
		{
			Vec4f val;
			Vec4i iVal;
			val.Store(DirectX::XMVector2Transform(Load(), _matrix));

			iVal = val.Round().AsXmInt4();

			return iVal;
		}

		Vec4i operator*(const DirectX::XMFLOAT4X4 & _matrix)
		{
			return *this * DirectX::XMLoadFloat4x4(&_matrix);
		}

		Vec4i operator*(const DirectX::XMFLOAT3X3 & _matrix)
		{
			return *this * DirectX::XMLoadFloat3x3(&_matrix);
		}
#pragma endregion

#pragma region Functions

		DirectX::XMVECTOR Load() const
		{
			return DirectX::XMLoadSInt4(&vec);
		}

		void Store(const DirectX::XMVECTOR & vector)
		{
			DirectX::XMStoreSInt4(&vec, vector);
		}

		DirectX::XMFLOAT2 AsXmFloat2() const
		{
			DirectX::XMFLOAT2 val;
			val.x = (float)x;
			val.y = (float)y;
			return val;
		}

		DirectX::XMFLOAT3 AsXmFloat3() const
		{
			DirectX::XMFLOAT3 val;
			val.x = (float)x;
			val.y = (float)y;
			val.z = 0.0f;

			return val;
		}

		DirectX::XMFLOAT4 AsXmFloat4() const
		{
			DirectX::XMFLOAT4 val;
			val.x = (float)x;
			val.y = (float)y;
			val.z = 0.0f;
			val.w = 0.0f;

			return val;
		}

		DirectX::XMINT2 AsXmInt2() const
		{
			DirectX::XMINT2 val;
			val.x = x;
			val.y = y;

			return val;
		}

		DirectX::XMINT3 AsXmInt3() const
		{
			DirectX::XMINT3 val;
			val.x = x;
			val.y = y;
			val.z = z;

			return val;
		}

		const DirectX::XMINT4 & AsXmInt4() const
		{
			return vec;
		}

		Vec4i Abs() const
		{
			return Vec4i(abs(x), abs(y));
		}

		Vec4f Normalize(bool ignoreW = false) const
		{
			Vec4f nor;

			if (!ignoreW)
				nor.Store(DirectX::XMVector4Normalize(Load()));
			else
			{
				float _w = w;
				nor.Store(DirectX::XMVector3Normalize(Load()));
				nor.w = _w;
			}

			return nor;
		}

		Vec4i Cross(const DirectX::XMVECTOR & vector)
		{
			Vec3f fVal = AsXmFloat3();
			return fVal.Cross(vector).Round().AsXmInt4();
		}

		Vec4i Cross(const Vec4i & _Vec3i)
		{
			Vec3f fVal = AsXmFloat3();
			return fVal.Cross(_Vec3i.AsXmFloat3()).Round().AsXmInt4();
		}

		Vec4i Cross(const DirectX::XMINT4 & _xmInt)
		{
			Vec3f fVal = AsXmFloat3();
			return fVal.Cross(DirectX::XMLoadSInt4(&_xmInt)).Round().AsXmInt4();
		}

		float Dot(const DirectX::XMVECTOR & vector)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Dot(Load(), vector));
		}

		float Dot(const Vec4i & _Vec4i)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Dot(Load(), _Vec4i.Load()));
		}

		float Dot(const DirectX::XMINT4 & _xmInt)
		{
			return DirectX::XMVectorGetX(DirectX::XMVector3Dot(Load(), DirectX::XMLoadSInt4(&_xmInt)));
		}

		float Length() const
		{
			return DirectX::XMVectorGetX(DirectX::XMVector4Length(Load()));
		}

		float LengthSq() const
		{
			return DirectX::XMVectorGetX(DirectX::XMVector4LengthSq(Load()));
		}

		std::string ToString() const
		{
			std::string str = "X: " + std::to_string(x) + ", " + "Y: " + std::to_string(y) + "Z: " + std::to_string(z) + "W: " + std::to_string(w);
			return str;
		}
#pragma endregion
		int & x = vec.x;
		int & y = vec.y;
		int & z = vec.z;
		int & w = vec.w;

	private:
		DirectX::XMINT4 vec;
	};

}