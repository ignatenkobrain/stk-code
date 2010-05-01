#ifndef HEADER_GRAND_PRIX_OVER_HPP
#define HEADER_GRAND_PRIX_OVER_HPP

#include "guiengine/screen.hpp"

namespace irr { namespace scene { class ISceneNode; class ICameraSceneNode; class ILightSceneNode; } }
class KartProperties;

/**
  * \brief Screen shown at the end of a Grand Prix
  * \ingroup states_screens
  */
class GrandPrixOver : public GUIEngine::Screen, public GUIEngine::ScreenSingleton<GrandPrixOver>
{
    friend class GUIEngine::ScreenSingleton<GrandPrixOver>;
    
    GrandPrixOver();
    
    /** sky angle, 0-360 */
    float m_sky_angle;
    
    /** Global evolution of time */
    double m_global_time;
    
    irr::scene::IMeshSceneNode* m_village;

    irr::scene::IMeshSceneNode* m_podium_step[3];
    irr::scene::ISceneNode* m_kart_node[3];
    
    irr::scene::ISceneNode* m_sky;
    irr::scene::ICameraSceneNode* m_camera;

    irr::scene::ILightSceneNode* m_light;
    
    int m_phase;
    
    float m_kart_x[3], m_kart_y[3], m_kart_z[3];
    float m_podium_x[3], m_podium_z[3];
    float m_kart_rotation[3];
    
    float m_camera_x, m_camera_y, m_camera_z;
    float m_camera_target_x, m_camera_target_z;
    
public:

    /** \brief implement callback from parent class GUIEngine::Screen */
    virtual void loadedFromFile();
    
    /** \brief implement optional callback from parent class GUIEngine::Screen */
    void onUpdate(float dt, irr::video::IVideoDriver*);
    
    /** \brief implement callback from parent class GUIEngine::Screen */
    void init();
    
    /** \brief implement callback from parent class GUIEngine::Screen */
    void tearDown();
    
    /** \brief implement callback from parent class GUIEngine::Screen */
    void eventCallback(GUIEngine::Widget* widget, const std::string& name, const int playerID);
    
    void setKarts(const std::string idents[3]);

};

#endif

