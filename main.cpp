#include <Box2D/Box2D.h>
#include <stdio.h>

int main(int argc, char** argv)

{
	B2_NOT_USED(argc);
	B2_NOT_USED(argv);
	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	b2Body* body = world.CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	for (int32 i = 0; i < 1000000; ++i)
	{
		world.Step(timeStep, velocityIterations, positionIterations);

		//Fun‹o de fisica.
		body->ApplyAngularImpulse(45, 1);

	}



	// When the world destructor is called, all bodies and joints are freed. This can

	// create orphaned pointers, so be careful about your world management.



	return 0;

}

