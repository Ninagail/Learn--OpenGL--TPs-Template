#include <vector>
#include "../src-common/glimac/sphere_vertices.hpp"
#include "../src/model/model.hpp"
#include "../src/scene/loadShader.hpp"
#include "glimac/common.hpp"
#include "glm/vec2.hpp"
#include "p6/p6.h"

class Boids {
private:
    glm::vec3 m_position;
    glm::vec3 m_speed;
    glm::vec3 m_direction;
    glm::vec3 m_size;

public:
    // attributs
    static float cohesion_force;
    static float separation_force;

    static float distance_cohesion;
    static float distance_alignment;
    static float distance_separation;
    //bool         LODS = false;

    // constructeurs
    Boids()
        : m_position(glm::vec3(0.0, 0.0, 0.0)), m_speed(glm::vec3(0.01, 0.01, 0.01)), m_direction(glm::vec3(p6::random::direction(), 0.0f)), m_size(0.1){};

    Boids(glm::vec3 position, glm::vec3 speed, glm::vec3 size)
        : m_position(position), m_speed(speed), m_size(size){};

    ~Boids() = default;

    // Méthodes

    void drawBoids(p6::Context& ctx) const;
    void drawBoids3D(Model& model, glm::mat4 ProjMatrix, glm::mat4 NormalMatrix, glm::mat4 viewMatrix, LoadShader& loadShader, GLuint textName);
    void drawBoids3DSphere(const std::vector<glimac::ShapeVertex>& vertices, GLuint textureLadybug, const std::vector<Boids>& boids, glm::mat4 ProjMatrix, glm::mat4 MVMatrix, GLint uMVPMatrix, GLint uMVMatrix, GLint uNormalMatrix, GLint uTextLadybug);

    void update_pos();
    void update_direction(std::vector<Boids>& boids);

    // Lois Boids

    void cohesion(const std::vector<Boids>& boids);
    void alignment(const std::vector<Boids>& boids);
    void separation(const std::vector<Boids>& boids);

    // Getters
    glm::vec3 get_position() const { return m_position; };
    glm::vec3 get_speed() const { return m_speed; }
    glm::vec3 get_direction() const { return m_direction; }

    // Setters
    void set_position();
    void set_speed();
};