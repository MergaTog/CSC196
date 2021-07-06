#pragma once
#include "../Math/Vector2.h"
#include "../Math/Color.h"
#include <vector>

namespace nc
{
	struct Particle
	{
		Vector2 position;
		Vector2 Prevposition;
		Vector2 velocity;
		color color;
		float lifetime;
		bool isActive{ false };

		static bool IsNotActive(Particle particle) { return particle.isActive == false; }

	};
	class ParticleSystem
	{
	public:
		void Startup();
		void Shutdown();

		void Update(float dt);
		void Draw(Core::Graphics& graphics);

		void Create(Vector2& position, size_t count, float lifetime, const color& color, float Speed);

	private:
		std::vector<Particle> particles;

	};
}