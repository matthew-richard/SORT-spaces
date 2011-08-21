/*
   FileName:      skybox.cpp

   Created Time:  2011-08-04 12:51:45

   Auther:        Cao Jiayin

   Email:         soraytrace@hotmail.com

   Location:      China, Shanghai

   Description:   SORT is short for Simple Open-source Ray Tracing. Anyone could checkout the source code from
                'sourceforge', https://soraytrace.svn.sourceforge.net/svnroot/soraytrace. And anyone is free to
                modify or publish the source code. It's cross platform. You could compile the source code in 
                linux and windows , g++ or visual studio 2008 is required.
*/

// include the header
#include "skybox.h"
#include "geometry/vector.h"
#include <math.h>

// default constructor
SkyBox::SkyBox()
{
	_registerAllProperty();

	m_up.SetTexCoordFilter( TCF_CLAMP );
	m_down.SetTexCoordFilter( TCF_CLAMP );
	m_left.SetTexCoordFilter( TCF_CLAMP );
	m_right.SetTexCoordFilter( TCF_CLAMP );
	m_front.SetTexCoordFilter( TCF_CLAMP );
	m_back.SetTexCoordFilter( TCF_CLAMP );
}

// evaluate value from sky
Spectrum SkyBox::Evaluate( const Vector& vec ) const
{
	float abs_x = fabs( vec.x );
	float abs_y = fabs( vec.y );
	float abs_z = fabs( vec.z );

	if( abs_x > abs_y && abs_x > abs_z )
	{
		if( vec.x > 0.0f )
		{
			float u = ( -vec.z / vec.x + 1.0f ) * 0.5f;
			float v = ( -vec.y / vec.x + 1.0f ) * 0.5f;
			return m_front.GetColor( u , v );
		}
		else
		{
			float u = ( -vec.z / vec.x + 1.0f ) * 0.5f;
			float v = ( vec.y / vec.x + 1.0f ) * 0.5f;
			return m_back.GetColor( u , v );
		}
	}else if( abs_y > abs_x && abs_y > abs_z )
	{
		if( vec.y > 0.0f )
		{
			float u = ( vec.x / vec.y + 1.0f ) * 0.5f;
			float v = ( vec.z / vec.y + 1.0f ) * 0.5f;
			return m_up.GetColor( u , v );
		}
		else
		{
			float u = ( -vec.x / vec.y + 1.0f ) * 0.5f;
			float v = ( vec.z / vec.y + 1.0f ) * 0.5f;
			return m_down.GetColor( u , v );
		}
	}else
	{
		if( vec.z > 0.0f )
		{
			float u = ( vec.x / vec.z + 1.0f ) * 0.5f;
			float v = ( -vec.y / vec.z + 1.0f ) * 0.5f;
			return m_left.GetColor( u , v );
		}
		else
		{
			float u = ( vec.x / vec.z + 1.0f ) * 0.5f;
			float v = ( vec.y / vec.z + 1.0f ) * 0.5f;
			return m_right.GetColor( u , v );
		}
	}

	return Spectrum();
}

// register property
void SkyBox::_registerAllProperty()
{
	_registerProperty( "up" , new UpProperty(this) );
	_registerProperty( "down" , new DownProperty(this) );
	_registerProperty( "left" , new LeftProperty(this) );
	_registerProperty( "right" , new RightProperty(this) );
	_registerProperty( "front" , new FrontProperty(this) );
	_registerProperty( "back" , new BackProperty(this) );
}

// get the average radiance
Spectrum SkyBox::GetAverage() const
{
	// to be modified
	return 0.0f;
}

// sample direction
Vector SkyBox::sample_v( float u , float v , float* pdf ) const
{
	return Vector();
}