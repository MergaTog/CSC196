#include "ParticleSystem.h"

namespace nc
{
	float random() 
	{
		return rand() / static_cast<float>(RAND_MAX);
	}

	float random(float min, float max)
	{
		return min + (max - min) * random();
	}

	void ParticleSystem::Startup()
	{
		particles.resize(1000);
	}

	void ParticleSystem::Shutdown()
	{
		particles.clear();
	}

	void ParticleSystem::Update(float dt)
	{
		for (Particle& particle : particles)
		{
			if (particle.isActive)
			{
				particle.lifetime -= dt;
				particle.isActive = particle.lifetime > 0;
				particle.Prevposition = particle.position;
				particle.position += particle.velocity * dt;

			}
		}
	}

	void ParticleSystem::Draw(Core::Graphics& graphics)
	{
		for (const Particle& particle : particles)
		{
			if (particle.isActive)
			{
				graphics.SetColor(particle.color);
				graphics.DrawLine(particle.position.x, particle.position.y, particle.Prevposition.x, particle.Prevposition.y);
			}
		}
	}

	void ParticleSystem::Create(Vector2& position, size_t count, float lifetime, const color& color, float speed)
	{
		for (size_t i = 0; i < count; i++)
		{
			auto particle = std::find_if(particles.begin(), particles.end(), Particle::IsNotActive);
			if (particle != particles.end())
			{
				particle->isActive = true;
				particle->lifetime = lifetime;
				particle->position = position;
				particle->Prevposition = position;
				particle->color = color;

				particle->velocity = Vector2{ random(-1, 1), random(-1, 1) } * speed;
			}
		}
	}
}