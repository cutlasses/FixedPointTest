// FixedPointTest.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

typedef short int          int16_t;
typedef int                int32_t;

class FIXED_POINT
{
	static constexpr int SHIFT_BITS			= 8;
	static constexpr float SCALE_FACTOR_F	= static_cast<float>( 1 << SHIFT_BITS );
	
	int32_t			m_fp_value;

	// set the implementation value directly
	explicit FIXED_POINT( int32_t value ) :
		m_fp_value( value )
	{
	}

public:

	explicit inline FIXED_POINT( float value ) :
		m_fp_value( static_cast<int32_t>( (value * SCALE_FACTOR_F) + 0.5f ) )
	{
	}
	explicit inline FIXED_POINT( int16_t value ) :
		m_fp_value( value << SHIFT_BITS )
	{
	}
	inline float to_float() const
	{
		return static_cast<float>( m_fp_value ) / SCALE_FACTOR_F;
	}
	inline FIXED_POINT operator+( const FIXED_POINT& rhs ) const
	{
		return FIXED_POINT( m_fp_value + rhs.m_fp_value );
	}
	inline FIXED_POINT operator-( const FIXED_POINT& rhs ) const
	{
		return FIXED_POINT( m_fp_value - rhs.m_fp_value );
	}
};

int main()
{
	FIXED_POINT a( 4.3f);
	FIXED_POINT b( 8.2f );
	
	FIXED_POINT c = a + b;

	printf( "%f + %f = %f", a.to_float(), b.to_float(), c.to_float() );

    return 0;
}

