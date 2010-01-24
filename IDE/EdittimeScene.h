/**
 * Game Develop
 *    Editor
 *
 *  Par Florian "4ian" Rival
 *
 */
/**
 *
 *
 *  Une "EdittimeScene" est une sc�ne utilis�e pour l'�dition
 *  ( �dit�e et affich�e par un EditorScene et un sceneCanvas )
 */

#ifndef EDITTIMESCENE_H
#define EDITTIMESCENE_H

#include <SFML/Graphics.hpp>
#include "GDL/RuntimeScene.h"
#include "GDL/Game.h"
#include <string>
#include <vector>

using namespace std;


class EdittimeScene : public RuntimeScene
{
    public:
        /** Default constructor */
        EdittimeScene(sf::RenderWindow * renderWindow_, RuntimeGame * game_);
        /** Default destructor */
        virtual ~EdittimeScene();
        void RenderEdittimeScene();

        bool editing; //Car une EdittimeScene peut aussi �tre jou�e

        sf::View view; //Vue pour l'�dition
        float zoom;

        //Ajout d'objet
        string objectToAdd;
        string addOnLayer;

        //Grille
        bool grid;
        bool snap;
        int gridWidth;
        int gridHeight;
        int gridR;
        int gridG;
        int gridB;

        //D�placement d'objets
        bool isMovingObject;
        vector < int > idObjectsSelected;
        vector < float > xObjectsSelected;
        vector < float > yObjectsSelected;
        int xDecalement;
        int yDecalement;

        //Affichage de rectangles autour des selections
        int colorGUI;
        bool colorPlus;
        sf::Shape selection;

        //Remember cursor old position
        int oldMouseX;
        int oldMouseY;

        //D�placement avec la souris ( clic molette )
        bool isMoving;
        int deplacementOX;
        int deplacementOY;

        int FindSmallestObject();

    protected:
    private:
        void UpdateGUI();
        void RenderGrid();
};

#endif // EDITTIMESCENE_H
