#ifndef DIRECTIONAL_LIGHT_SCENE_HPP
#define DIRECTIONAL_LIGHT_SCENE_HPP

#define GLM_FORCE_CXX11
#include <glm/glm.hpp>
#include <scene.hpp>
#include <shader.hpp>
#include <mesh/mesh.hpp>
#include <textures/texture2d.hpp>
#include <camera/camera.hpp>
#include <camera/controllers/fly_camera_controller.hpp>
#include<time.h>
enum TextureType 
{
    ALBEDO = 0,
    SPECULAR = 1,
    ROUGHNESS = 2,
    AMBIENT_OCCLUSION = 3,
    EMISSIVE = 4
};

class DirectionalLightScene : public Scene 
{
private:
    float Rotation;
    int speed;
    int obpos;
    float carpos;
    float rockpos;
    int rockrate;

    Shader* shader;
    time_t timer;
    Shader* skyShader;
    Mesh* groundLeft;
    Mesh* groundRight;
    Mesh* sky;
    Mesh* model;
    Mesh* carmodel;
    Mesh* track;
    Mesh* rock;
    Mesh* cone;
    
    Texture2D* metal[5];
    Texture2D* wood[5];
    Texture2D* asphalt[5];
    Texture2D* checkers[5];
    Texture2D* sand[5];
    Texture2D* carText[5];
    Texture2D* roadText[5];
    Texture2D* rockText[5];
    Texture2D* coneText[5];
    Camera* camera;
    FlyCameraController* controller;

    float sunYaw, sunPitch;
public:
    DirectionalLightScene(Application* app): Scene(app) {}

    void Initialize() override;
    void Update(double delta_time) override;
    void Draw() override;
    void Finalize() override;
};

#endif