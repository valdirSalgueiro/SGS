#ifndef __GLES2SPRITEBATCH__
#define __GLES2SPRITEBATCH__

#include "SpriteBatch.h"
#include "Vector2D.h"
#include <GLES2/gl2.h>

#define COSINE_TABLE_SIZE 1024
#define COSINE_TABLE_AND 1023

#define BATCH_SIZE 16 // NOTE, THIS CANNOT BE CHANGED UNLESS CORRESPONDING VALUES FROM THE SHADER'S ARE CHANGED ACCORDINGLY

struct FrameBuffer{
	GLuint texture;
	GLuint buffer;
};

class GLES2SpriteBatch : public SpriteBatch
{
public:
    GLES2SpriteBatch(int targetWidth, int targetHeight);
    virtual ~GLES2SpriteBatch();

    void draw ( SpriteDrawInfo *sdi, int spriteCount=1 );
    void begin( int mode, TransformMode dTransform = ePIXELSPACE, float *customProjectionMatrix = 0);
    void end();


	GLuint createTexture();
	FrameBuffer createFramebuffer();

    void flushSprites();
	void startBloom();
	void endBloom();

private:

	void bloom();

protected:
    float cosineTable[COSINE_TABLE_SIZE];
    float inputMatrixTemp[ BATCH_SIZE * 16 ];
	float colorTemp[ BATCH_SIZE * 4 ];

    SpriteDrawInfo batchCollection[ BATCH_SIZE ];
    int batchCounter;

        // Currently active texture
    GLuint currentTexture;
    int currentTextureWidth;
    int currentTextureHeight;

        // Objects for GLES2 rendering
    TransformMode currentDestinationTransform;
    int currentViewportWidth;
    int currentViewportHeight;

    void setActiveProgram( int programIndex );
    int currentProgram;

    GLfloat projectionMatrix[16];         // Sroted projectionmatrix.

        // index0 = texture*color, index1=texture
    GLint program[8];
    GLint fragmentShader[8];
    GLint vertexShader[8];

    // Some locations to the program
    GLuint inputMatrixLocation[8];
	GLuint colorLocation[8];
    GLuint projmLocation[8];
    GLuint samplerLocation[8];


    GLuint vbo;
	GLuint buffer;

	Vector2D<int> playerPos;

};

#endif
