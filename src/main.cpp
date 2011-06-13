/*
 * filename :	main.cpp
 *
 * programmer :	Cao Jiayin
 */

// include the header file
#include "sort.h"
#include "system.h"
#include "texture/gridtexture.h"
#include "utility/timer.h"
#include "camera/perspective.h"
#include "geometry/vector.h"

// the global system
System g_System;

// the main func
int main( int argc , char** argv )
{
	PerspectiveCamera* camera = new PerspectiveCamera();
	camera->SetEye( Point( 1 , 1 , 0.5 ) );
	camera->SetUp( Vector( 0 , 1 , 0 ) );
	camera->SetTarget( Point( 0 , 0 , 0 ) );
	camera->SetFov( 3.1415f / 4.0f );
	g_System.m_camera = camera;
	g_System.m_camera->SetRenderTarget( g_System.m_rt );

	g_System.Render();

	g_System.OutputRT( "test.bmp" );

	return 0;
}