/*
 * SimpleDraw.c
 *
 * Example program illustrating a simple use
 * of OpenGL to draw straight lines in 2D, and
 * to draw overlapping triangles in 3D.
 *
 * Author: Samuel R. Buss
 *
 * Software accompanying the book
 *		3D Computer Graphics: A Mathematical Introduction with OpenGL,
 *		by S. Buss, Cambridge University Press, 2003.
 *
 * Software is "as-is" and carries no warranty.  It may be used without
 *   restriction, but if you modify it, please change the filenames to
 *   prevent confusion between different versions.
 * Bug reports: Sam Buss, sbuss@ucsd.edu.
 * Web page: http://math.ucsd.edu/~sbuss/MathCG
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>	// OpenGL Graphics Utility Library
#include "SimpleDraw.h"

// These variables control the current mode
int CurrentMode = 0;
const int NumModes = 5;
bool OneTap = true;

// These variables set the dimensions of the rectanglar region we wish to view.
const double Xmin = 0.0, Xmax = 3.0;
const double Ymin = 0.0, Ymax = 3.0;

// glutKeyboardFunc is called below to set this function to handle
//		all "normal" ascii key presses.
// Only space bar and escape key have an effect.
void myKeyboardFunc()
{
	CurrentMode = (CurrentMode+1)%NumModes;
}

//Only allows one change per spacebar press
bool PressSpacebar(GLFWwindow * window) {
	if (OneTap && glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		return false;
	else if (!OneTap && glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		OneTap = true;
		return true;
	}
	else if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE) {
		OneTap = false;
		return false;
	}
	return false;
}

/*
 * drawScene() handles the animation and the redrawing of the
 *		graphics window contents.
 */
void drawScene()
{
	// Clear the rendering window

	// Set drawing color to white
	glColor3f( 1.0, 1.0, 1.0 );		

	switch (CurrentMode)
	{

	case 0:
		// Draw three points
		glBegin(GL_POINTS);
		glVertex2f( 0.5/3, 0.5/3 );
		glVertex2f( 1/3, .5/3 );
		glVertex2f( 1/3, 1/3 );
		glEnd();
		break;

	case 1:
	case 2:
	case 3:
		if ( CurrentMode==1 ) {
			// Draw lines in GL_LINES mode
			glBegin( GL_LINES );
		}
		else if ( CurrentMode==2 ) {
			// Draw lines in GL_LINE_STRIP mode
			glBegin( GL_LINE_STRIP );
		}
		else {
			// Draw lines in GL_LINE_LOOP mode
			glBegin( GL_LINE_LOOP );
		}
		glVertex2f( 0.5 / 3, 1.0 / 3);
		glVertex2f( 2.0 / 3, 2.0 / 3);
		glVertex2f( 1.8 / 3, 2.6 / 3);
		glVertex2f( 0.7 / 3, 2.2 / 3);
		glVertex2f( 1.6 / 3, 1.2 / 3);
		glVertex2f( 1.0 / 3, 0.5 / 3);
		glEnd();
		break;

	case 4:			// Overlapping triangles
		glBegin( GL_TRIANGLES );
		glColor3f( 1.0, 0.0, 0.0 );
		glVertex3f( 0.3 / 3, 1.0 / 3, 0.5 / 3);
		glVertex3f( 2.7 / 3, 0.85 / 3, 0.0 / 3);
		glVertex3f( 2.7 / 3, 1.15 / 3, 0.0 / 3);

		glColor3f( 0.0, 1.0, 0.0 );
		glVertex3f(2.53 / 3, 0.71 / 3, 0.5 / 3);
		glVertex3f(1.46 / 3, 2.86 / 3, 0.0 );
		glVertex3f(1.2 / 3, 2.71 / 3, 0.0 );

		glColor3f( 0.0, 0.0, 1.0 );
		glVertex3f(1.667 / 3, 2.79 / 3, 0.5 / 3);
		glVertex3f(0.337 / 3, 0.786 / 3, 0.0);
		glVertex3f(0.597 / 3, 0.636 / 3, 0.0);
		glEnd();
	}

}
void Exercise3() {
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 1, 1);
	glVertex2d(0, 0);
	glVertex2d(0, .6);
	glVertex2d(.07,.17);

	glColor3f(0, 1, 0);
	glVertex2d(.4, .2);

	glColor3f(0, 1, 1);
	glVertex2d(.1, -.02);

	glColor3f(0, 1, 0);
	glVertex2d(.3, -.5);
	glColor3f(0, 1, 1);
	glVertex2d(0, -.15);

	glColor3f(0, 1, 0);
	glVertex2d(-.3, -.5);
	glColor3f(0, 1, 1);
	glVertex2d(-.1, -.02);
	
	glColor3f(0, 1, 0);
	glVertex2d(-.4, .2);
	glColor3f(0, 1, 1);
	glVertex2d(-.07, .17);

	glColor3f(0, 1, 0);
	glVertex2d(0, .6);
	glEnd();

}
void Exercise5() {
	glBegin(GL_QUADS);
	//Front Face
	glVertex3d(-.5, .5,1);
	glVertex3d(-.5, -.5,1);
	glVertex3d(.5, -.5, 1);
	glVertex3d(.5, .5, 1);

	//Right Face
	glColor3f(0, 1, 0);
	glVertex3d(.5, .5, 1);
	glVertex3d(.5, -.5, 1);
	glVertex3d(.5, -.5, 0);
	glVertex3d(.5, .5, 0);

	//Back Face
	glColor3f(0, 1, 1);
	glVertex3d(.5, .5, 0);
	glVertex3d(.5, -.5, 0);
	glVertex3d(-.5, -.5, 0);
	glVertex3d(-.5, .5, 0);

	//Left Face
	glColor3f(1, 1, 0);
	glVertex3d(-.5, .5, 0);
	glVertex3d(-.5, -.5, 0);
	glVertex3d(-.5, -.5, 1);
	glVertex3d(-.5, .5, 1);

	//Top Face
	glColor3f(0, 0, 0);
	glVertex3d(-.5, .5, 1);
	glVertex3d(.5, .5, 1);
	glVertex3d(-.5, .5, 0);
	glVertex3d(.5, .5, 0);

	//Bottom Face
	glColor3f(0, 0, 1);
	glVertex3d(-.5, -.5, 1);
	glVertex3d(.5, -.5, 1);
	glVertex3d(-.5, -.5, 0);
	glVertex3d(.5, -.5, 0);
	glEnd();
}
void Exercise6() {
	glBegin(GL_QUAD_STRIP);
	//Top Face
	glVertex3d(-.5, .5, 1);
	glVertex3d(-.5, -.5, 1);
	glVertex3d(.5, -.5, 1);
	glVertex3d(.5, .5, 1);

	//Right Face
	glColor3f(0, 1, 0);
	glVertex3d(.5, .5, 0);
	glVertex3d(.5, -.5, 0);

	//Back Face
	glColor3f(0, 1, 1);
	glVertex3d(-.5, .5, 0);
	glVertex3d(-.5, -.5, 0);
	glEnd();

	glBegin(GL_QUAD_STRIP);
	//Top Face
	glColor3f(0, 0, 0);
	glVertex3d(.5, .5, 1);
	glVertex3d(.5, .5, 0);
	glVertex3d(-.5, .5, 1);
	glVertex3d(-.5, .5, 0);

	//Left Face
	glColor3f(1, 1, 0);
	glVertex3d(-.5, -.5, 1);
	glVertex3d(-.5, -.5, 0);

	//Bottom Face
	glColor3f(0, 0, 1);
	glVertex3d(.5, -.5, 1);
	glVertex3d(.5, -.5, 0);
	glEnd();
}
void Exercise7() {
	//Goes Clockwise, might fix later
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3d(-.5, -.5, 1);
	glVertex3d(-.5, -.5, 0);

	//Left face
	glVertex3d(-.5, .5, 0);
	glVertex3d(-.5, .5, 1);
	//Front face
	glVertex3d(.5, .5, 1);
	glVertex3d(.5, -.5, 1);
	//Bottom Face
	glVertex3d(.5, -.5, 0);
	glVertex3d(-.5, -.5, 0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3d(.5, .5, 0);
	glVertex3d(.5, .5, 1);
	//Top face
	glVertex3d(-.5, .5, 1);
	glVertex3d(-.5, .5, 0);
	//Back face
	glVertex3d(-.5, -.5, 0);
	glVertex3d(.5, -.5, 0);
	//Left face
	glVertex3d(.5, -.5, 1);
	glVertex3d(.5, .5, 1);
	glEnd();
}
// Initialize OpenGL's rendering modes
void initRendering()
{
	// Uncomment out the first block of code below, and then the second block,
	//		to see how they affect line and point drawing.
/*
	// The following commands should cause points and line to be drawn larger
	//	than a single pixel width.
	glPointSize(8);
	glLineWidth(5);
*/

/*
	// The following commands should induce OpenGL to create round points and 
	//	antialias points and lines.  (This is implementation dependent unfortunately).
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);	// Make round points, not square points
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);		// Antialias the lines
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
*/

}

// Called when the window is resized
//		w, h - width and height of the window in pixels.
void resizeWindow(int w, int h)
{
	double scale, center;
	double windowXmin, windowXmax, windowYmin, windowYmax;

	// Define the portion of the window used for OpenGL rendering.
	glViewport( 0, 0, w, h );	// View port uses whole window

	// Set up the projection view matrix: orthographic projection
	// Determine the min and max values for x and y that should appear in the window.
	// The complication is that the aspect ratio of the window may not match the
	//		aspect ratio of the scene we want to view.
	w = (w==0) ? 1 : w;
	h = (h==0) ? 1 : h;
	if ( (Xmax-Xmin)/w < (Ymax-Ymin)/h ) {
		scale = ((Ymax-Ymin)/h)/((Xmax-Xmin)/w);
		center = (Xmax+Xmin)/2;
		windowXmin = center - (center-Xmin)*scale;
		windowXmax = center + (Xmax-center)*scale;
		windowYmin = Ymin;
		windowYmax = Ymax;
	}
	else {
		scale = ((Xmax-Xmin)/w)/((Ymax-Ymin)/h);
		center = (Ymax+Ymin)/2;
		windowYmin = center - (center-Ymin)*scale;
		windowYmax = center + (Ymax-center)*scale;
		windowXmin = Xmin;
		windowXmax = Xmax;
	}
	
	// Now that we know the max & min values for x & y that should be visible in the window,
	//		we set up the orthographic projection.
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( windowXmin, windowXmax, windowYmin, windowYmax, -1, 1 );

}
